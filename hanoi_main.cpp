//
//  main.cpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/19.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <bangtal>
#include "hanoi.hpp"
using namespace bangtal;
using namespace std;


class hanoi_Bar;
class hanoi_Tower;


ScenePtr hanoi_scene1, hanoi_scene2;
ObjectPtr hanoi_startButton, hanoi_endButton;
ObjectPtr hanoi_tower_img[3];
ObjectPtr hanoi_selectButton[3], hanoi_toButton[3], hanoi_clearButton;

ObjectPtr hanoi_howto;
ObjectPtr hanoi_story[3];
ObjectPtr hanoi_end;

extern ScenePtr mainScene;
extern void check_all_clear();
extern SoundPtr BGM2;

//Ÿ�� ��ü ����
hanoi_Tower hanoi_tower[3];
hanoi_Tower hanoi_towerR;
int hanoi_tempTower;

//*���� ��ü ����
hanoi_Bar BAR[4];


SoundPtr hanoi_BGM;
// ���� 2�� ��ĥ�ϱ� �������
void game5_bgm()
{
    hanoi_BGM = Sound::create("main_sounds/05.mp3");
    hanoi_BGM->play();
}


ScenePtr hanoi_game_init();
void hanoi_init()
{
    hanoi_game_init()->enter();
}

bool hanoi_check_Clear()
{
    for (int i = 0; i < 4; i++)
    {
        if (hanoi_tower[2].slot[i] == NULL)
            return false;
    }
    return true;
}
void hanoi_resetToButton()
{
    //��ư �ʱ�ȭ
    hanoi_selectButton[hanoi_tempTower]->setImage("hanoi_images/hanoi_selectButton.png"); //ing->select ��ư �̹��� ����
    for (int button = 0; button < 3; button++) //��ư ����
    {
        if (button != hanoi_tempTower)
        {
            hanoi_selectButton[button]->show();
            hanoi_toButton[button]->hide();
        }
    }
}
//��2 �����Լ�
void hanoi_create_scene2()
{
    //��ư ����
    for (int i = 0; i < 3; i++)
    {
        hanoi_selectButton[i] = Object::create("hanoi_images/hanoi_selectButton.png", hanoi_scene2, 290 + 300 * i, 130);
    }
    for (int i = 0; i < 3; i++)
    {
        hanoi_toButton[i] = Object::create("hanoi_images/hanoi_toButton.png", hanoi_scene2, 290 + 300 * i, 130);
        hanoi_toButton[i]->hide();
    }

    //select ��ư �ݹ�
    //������ Ÿ���� top���븦 Ȯ���մϴ�.
    for (int i = 0; i < 3; i++)
    {
        hanoi_selectButton[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hanoi_tempTower = i; // ������ Ÿ�� ���
            hanoi_tower[i].check_tower_index(); //Ÿ�� ���ΰ�ħ
            if (hanoi_tower[i].tower_top == -1) //���밡 ���� Ÿ�� ���ý�
            {
                showMessage("���밡 ���� Ÿ���Դϴ�.");
            }
            if (hanoi_tower[i].tower_top >= 0)
            {
                hanoi_selectButton[i]->setImage("hanoi_images/hanoi_ingButton.png"); //��ư �̹��� ����
                for (int button = 0; button < 3; button++) //��ư ����
                {
                    if (button != i)
                    {
                        hanoi_selectButton[button]->hide();
                        hanoi_toButton[button]->show();
                    }
                }
            }
            return true;
        });
    }

    //to ��ư �ݹ�
    //1.to Ÿ���� top ���븦 Ȯ���մϴ�.
    //2.index �񱳸� ���� bool �Ǵ��� �մϴ�.
    //3.select Ÿ���� top ���븦 to Ÿ���� �� ���� �ű�ϴ�.
    for (int i = 0; i < 3; i++)
    {
        hanoi_toButton[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            //1.to Ÿ���� top���븦 Ȯ���մϴ�.
            hanoi_tower[i].check_tower_index(); //Ÿ�� ���ΰ�ħ
            //2.index�񱳸� ���� bool �Ǵ��� �մϴ�.
            if (hanoi_tower[i].slot[0] == nullptr) //Ÿ���� �� ���
            {
                //�׷���
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->object->locate(hanoi_scene2, 240 + 300 * i, 220);
                //showMessage("���븦 �Ű���ϴ�.");

                //��
                hanoi_tower[i].slot[0] = hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top];
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top] = nullptr;
                hanoi_tower[hanoi_tempTower].check_tower_index();
                hanoi_tower[i].check_tower_index();

                hanoi_resetToButton(); //��ư �ʱ�ȭ

            }
            else if (hanoi_tower[i].slot[hanoi_tower[i].tower_top]->index < hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->index) //�ű���� ���밡 �� ���� ���
            {
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->object->locate(hanoi_scene2, 240 + 300 * i, 270 + 50 * hanoi_tower[i].tower_top);
                //showMessage("���븦 �Ű���ϴ�.");

                hanoi_tower[i].slot[hanoi_tower[i].tower_top + 1] = hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top];
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top] = nullptr;
                hanoi_tower[hanoi_tempTower].check_tower_index();
                hanoi_tower[i].check_tower_index();

                hanoi_resetToButton(); //��ư �ʱ�ȭ
            }
            else {
                //�� �� ���
                showMessage("Ÿ���� �ű� �� �����ϴ�.");

                hanoi_resetToButton();
            }
            if (hanoi_check_Clear() == true) //Ŭ���� üũ
            {
                hanoi_clearButton = Object::create("hanoi_images/hanoi_clearButton.png", hanoi_scene2, 540, 550);
                hanoi_clearButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    //�ɷ�ġ�� ����

                    hanoi_end = Object::create("hanoi_images/hanoi_end.png", hanoi_scene2, 0, 0);
                    hanoi_end->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                        // ���� Ȩ ȭ�� �̵�
                        hanoi_BGM->stop();
                        BGM2->play();
                        check_all_clear();
                        mainScene->enter();

                        return true;
                    });//�������


                    return true;
                });
            }
            return true;
        });
    }
}

ScenePtr hanoi_game_init()
{

    // 
    //�� ����
    hanoi_scene1 = Scene::create("scene1", "hanoi_images/hanoi_scene1.png");
    hanoi_scene2 = Scene::create("scene2", "hanoi_images/hanoi_scene2.png");

    game5_bgm();

    //������Ʈ ����, �ݹ� ���
    hanoi_startButton = Object::create("hanoi_images/hanoi_startButton.png", hanoi_scene1, 880, 200);
    hanoi_startButton->setScale(0.25);
    hanoi_startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        //��2 ����
        hanoi_create_scene2();
        hanoi_scene2->enter();

        // ���� �߰�
        hanoi_howto = Object::create("hanoi_images/hanoi_howto.png", hanoi_scene2, 0, 0);
        hanoi_howto->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hanoi_howto->hide();
            return true;
        });

        for (int i = 2; i >= 0; i--)
        {
            char buf[50];
            sprintf(buf, "hanoi_images/hanoi_story%d.png", i);
            hanoi_story[i] = Object::create(buf, hanoi_scene2, 0, 0);
            hanoi_story[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hanoi_story[i]->hide();
                return true;
            });
        }


        return true;
    });

    //����ȭ��-endButton
    hanoi_endButton = Object::create("hanoi_images/hanoi_endButton.png", hanoi_scene1, 880, 100);
    hanoi_endButton->setScale(0.25);
    hanoi_endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        endGame();
        return true;
    });

    //Ÿ�� ������Ʈ ����
    for (int i = 0; i < 3; i++)
    {
        Object::create("hanoi_images/hanoi_tower.png", hanoi_scene2, 240 + 300 * i, 190.8);
    }

    //���� ���� �� ���� ���

    BAR[0].setInfo(0, hanoi_scene2);
    BAR[1].setInfo(1, hanoi_scene2);
    BAR[2].setInfo(2, hanoi_scene2);
    BAR[3].setInfo(3, hanoi_scene2);

    hanoi_tower[0].slot[0] = &BAR[0];
    hanoi_tower[0].slot[1] = &BAR[1];
    hanoi_tower[0].slot[2] = &BAR[2];
    hanoi_tower[0].slot[3] = &BAR[3];


    return hanoi_scene1;
}

/*
int main() {

    //���ӿɼǼ���
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    //���ӽ���
    startGame(hanoi_game_init());

    return 0;
}*/
