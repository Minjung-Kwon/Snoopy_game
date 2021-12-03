//
//  main.cpp
//  coloring
//
//  Created by line.ash on 2021/11/29.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <bangtal>
using namespace bangtal;

extern ScenePtr mainScene;
extern void check_all_clear();
extern SoundPtr BGM2;

ScenePtr color_scene1, color_scene2, color_end;
ObjectPtr color_startButton, color_endButton;
ObjectPtr color_story[7], color_howto;
ObjectPtr color_colorButton[6];
ObjectPtr color_drawing_base;
ObjectPtr color_blue;
ObjectPtr color_white[6];
ObjectPtr color_ivory;
ObjectPtr color_brown;
ObjectPtr color_yellow;
ObjectPtr color_red;
ObjectPtr color_perfect;


int blue = 0, white = 0, yellow = 0, brown = 0, red = 0, ivory = 0;



SoundPtr coloring_BGMS;
// ���� 2�� ��ĥ�ϱ� �������
void game2_bgm()
{
    coloring_BGMS = Sound::create("main_sounds/02.mp3");
    coloring_BGMS->play();
}


bool coloring_check_clear()
{
    if (blue > 0 && white > 5 && yellow > 0 && brown > 0 && red > 0 && ivory > 0)
    {
        return true;
    }
    return false;
}



ScenePtr coloring_game_init() //�� �Լ��� �����ϸ� �˴ϴ�. coloring_game_init()->enter(); 
{
    //int blue = 0, white = 0, yellow = 0, brown = 0, red = 0, ivory = 0;
    //��1 ����
    color_scene1 = Scene::create("color_scene1", "coloring_images/color_scene1.png");

    color_startButton = Object::create("coloring_images/color_startButton.png", color_scene1, 880, 200);
    color_endButton = Object::create("coloring_images/color_endButton.png", color_scene1, 880, 100);

    color_startButton->setScale(0.25);
    color_endButton->setScale(0.25);



    //��2 ����
    color_scene2 = Scene::create("color_scene2", "coloring_images/background.png");
    for (int i = 0; i < 6; i++)
    {
        char buf[50];
        sprintf(buf, "coloring_images/color_button_%d.png", i);
        color_colorButton[i] = Object::create(buf, color_scene2, 1150, 42 + 113 * i);
        color_colorButton[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            switch (i) {
            case 5:
                if (blue < 1)
                {
                    color_blue = Object::create("coloring_images/drawing_11.png", color_scene2, 300, 73);
                    blue++;
                }
                break;
            case 4:
                if (white < 6)
                {
                    char buf[40];
                    sprintf(buf, "coloring_images/drawing_white_%d.png", white);
                    color_white[white] = Object::create(buf, color_scene2, 300, 73);
                    white += 1;
                }
                break;
            case 3:
                if (yellow < 1)
                {
                    color_yellow = Object::create("coloring_images/drawing_5.png", color_scene2, 300, 73);
                    yellow++;
                }
                break;
            case 2:
                if (brown < 1)
                {
                    color_brown = Object::create("coloring_images/drawing_4.png", color_scene2, 300, 73);
                    brown++;
                }
                break;
            case 1:
                if (red < 1)
                {
                    color_red = Object::create("coloring_images/drawing_1.png", color_scene2, 300, 73);
                    red++;
                }
                break;
            case 0:
                if (ivory < 1)
                {
                    color_ivory = Object::create("coloring_images/drawing_2.png", color_scene2, 300, 73);
                    ivory++;
                }
                break;
            default:
                break;
            }
            if (coloring_check_clear() == true)
            {
                

                //���� Ŭ����!
                blue = 0;
                white = 0;
                yellow = 0;
                brown = 0;
                red = 0;
                ivory = 0;//�� �ʱ�ȭ

                color_end = Scene::create("scene_end", "coloring_images/color_end.png");

                color_perfect = Object::create("coloring_images/color_perfect.png", color_scene2, 0,0);
                color_perfect->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    
                    color_end->enter();
                    color_perfect->hide();

                    return true;
                });


                ObjectPtr color_endGame = Object::create("coloring_images/color_endButton.png", color_end, 880, 200);
                color_endGame->setScale(0.25);
                color_endGame->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                    // ���� ȭ�� �̵�
                    coloring_BGMS->stop();
                    BGM2->play();

                    check_all_clear();
                    mainScene->enter();

                    return true;
                });

            }
            return true;
        });
    }

    color_drawing_base = Object::create("coloring_images/drawing_0.png", color_scene2, 300, 73);
    color_howto = Object::create("coloring_images/color_howto.png", color_scene2, 0, 0);
    color_howto->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        color_howto->hide();
        return true;
    });


    for (int i = 6; i >= 0; i--)
    {
        char buf[50];
        sprintf(buf, "coloring_images/color_story%d.png", i);
        color_story[i] = Object::create(buf, color_scene2, 0, 0);
        color_story[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            color_story[i]->hide();
            return true;
        });
    }


    color_startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {

        color_scene2->enter();

        return true;
    });


    color_endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {

        //���� ��� �������
        endGame();
        return true;
    });

    return color_scene1;
}








void coloring_init()
{
    game2_bgm();
    coloring_game_init()->enter();

}