/*
*
*   Snoopy's Happy Christmas
* 
*   2021.12.04
* 
*   Kwon Minjing
*   Kim Sunjae
*   Jung Woojin
* 
* 
*/




#define _CRT_SECURE_NO_WARNINGS

#include <bangtal>
#include <iostream>
#include <stdio.h>
#include <time.h>


using namespace bangtal;
using namespace std;

int main_score = 0;


ScenePtr startScene, mainScene, endScene, end2Scene;

ObjectPtr main_button[5], startcartoon[15], main_intro, endcartoon[4];

SoundPtr BGM1, BGM2, BGM3;



extern void letter_init();

extern void coloring_init();

extern void piano_init();

extern void pizza_init();

extern void hanoi_init();


void init_intro();


// 처음 시작 음악
void bgm1_start()   
{
    BGM1 = Sound::create("main_sounds/intro.mp3");
    BGM1->play();
}


// 크리스마스 시작 . 메인 메뉴 노래
void bgm2_start()
{
    BGM2 = Sound::create("main_sounds/jinglebell.mp3");
    BGM2->play();
}


// 크리스마스 시작 . 메인 메뉴 노래
void bgm3_start()
{
    BGM3 = Sound::create("main_sounds/final.mp3");
    BGM3->play();
}





void end2_scene()
{
    end2Scene->enter();

    auto end_button = Object::create("main_images/snoopy-main_end.png", end2Scene, 300, 50);
    end_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        
        // 게임 전체 종료
        endGame();


        return true;
    });


    auto restart_button = Object::create("main_images/snoopy-main_restart.png", end2Scene, 700, 50);
    restart_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        // 게임 재시작
        BGM3->stop();
        startScene->enter();
        init_intro();
        

        return true;
    });

}



void end_scene()
{
    endScene->enter();
    BGM2->stop();
    bgm3_start();


    endcartoon[0] = Object::create("main_images/snoopy_end_0.png", endScene, 0, 0);
    endcartoon[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        endcartoon[0]->hide();
        endcartoon[1] = Object::create("main_images/snoopy_end_1.png", endScene, 0, 0);
        endcartoon[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

            endcartoon[1]->hide();
            endcartoon[2] = Object::create("main_images/snoopy_end_2.png", endScene, 0, 0);
            endcartoon[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                endcartoon[2]->hide();
                endcartoon[3] = Object::create("main_images/snoopy_end_3.png", endScene, 0, 0);
                endcartoon[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    
                    endcartoon[3]->hide();
                    end2_scene();

                    return true;
                });
                return true;
            });
            return true;
        });
        return true;
    });



}






// 5가지의 게임을 모두 클리어하고 왔는지 확인하는 함수
void check_all_clear()
{

    if (++main_score >= 5)
    {
        auto enter_xmas_button = Object::create("main_images/snoopy-main_enter_christmas.png", mainScene, 535, 20);
        enter_xmas_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

            
            end_scene();

            return true;

        });
    }
}




// 01 게임 메인 홈 화면
void main_scene()
{
    mainScene->enter();

    
    
    main_intro->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        main_intro->hide();

        return true;

    });




    ObjectPtr main_color_button[5];
    main_color_button[0] = Object::create("main_images/snoopy-main_color_button1.png", mainScene, 170, 520);
    main_color_button[1] = Object::create("main_images/snoopy-main_color_button2.png", mainScene, 370, 480);
    main_color_button[2] = Object::create("main_images/snoopy-main_color_button3.png", mainScene, 570, 510);
    main_color_button[3] = Object::create("main_images/snoopy-main_color_button4.png", mainScene, 770, 470);
    main_color_button[4] = Object::create("main_images/snoopy-main_color_button5.png", mainScene, 970, 490);





    // 01 편지 쓰기 게임 버튼
    main_button[0] = Object::create("main_images/snoopy-main_button1.png", mainScene, 170, 520);
    main_button[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();
        main_button[0]->hide();
        letter_init();


        return true;

    });


    // 02 그림 그리기 게임 버튼
    main_button[1] = Object::create("main_images/snoopy-main_button2.png", mainScene, 370, 480);
    main_button[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();
        main_button[1]->hide();
        coloring_init();

        return true;

    });



    // 03 그림 그리기 게임 버튼
    main_button[2] = Object::create("main_images/snoopy-main_button3.png", mainScene, 570, 510);
    main_button[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        
        BGM2->stop();
        main_button[2]->hide();
        piano_init();

        return true;

    });



    // 04 피자 게임 버튼
    main_button[3] = Object::create("main_images/snoopy-main_button4.png", mainScene, 770, 470);
    main_button[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        BGM2->stop();
        main_button[3]->hide();
        pizza_init();

        return true;

    });




    // 05 하노이 게임 버튼
    main_button[4] = Object::create("main_images/snoopy-main_button5.png", mainScene, 970, 490);  
    main_button[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        
        BGM2->stop();
        main_button[4]->hide();
        hanoi_init();

        return true;

    });

    

}




void init_intro()
{
    bgm1_start();

    startScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_start_s.png");   //시작 전 화면
    // 인트로 화면. 스누피와 우드스탁과의 대화
    auto startimage = Object::create("main_images/snoopy-main_press.png", startScene, 0, 0);
    startimage->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

        startcartoon[0] = Object::create("main_images/snoopy_start_0.png", startScene, 0, 0);
        startcartoon[0]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

            startcartoon[0]->hide();
            startcartoon[1] = Object::create("main_images/snoopy_start_1.png", startScene, 0, 0);
            startcartoon[1]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                startcartoon[1]->hide();
                startcartoon[2] = Object::create("main_images/snoopy_start_2.png", startScene, 0, 0);
                startcartoon[2]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                    startcartoon[2]->hide();
                    startcartoon[3] = Object::create("main_images/snoopy_start_3.png", startScene, 0, 0);
                    startcartoon[3]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                        startcartoon[3]->hide();
                        startcartoon[4] = Object::create("main_images/snoopy_start_4.png", startScene, 0, 0);
                        startcartoon[4]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                            startcartoon[4]->hide();
                            startcartoon[5] = Object::create("main_images/snoopy_start_5.png", startScene, 0, 0);
                            startcartoon[5]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                startcartoon[5]->hide();
                                startcartoon[6] = Object::create("main_images/snoopy_start_6.png", startScene, 0, 0);
                                startcartoon[6]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                    startcartoon[6]->hide();
                                    startcartoon[7] = Object::create("main_images/snoopy_start_7.png", startScene, 0, 0);
                                    startcartoon[7]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                        startcartoon[7]->hide();
                                        startcartoon[8] = Object::create("main_images/snoopy_start_8.png", startScene, 0, 0);
                                        startcartoon[8]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                            startcartoon[8]->hide();
                                            startcartoon[9] = Object::create("main_images/snoopy_start_9.png", startScene, 0, 0);
                                            startcartoon[9]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                startcartoon[9]->hide();
                                                startcartoon[10] = Object::create("main_images/snoopy_start_10.png", startScene, 0, 0);
                                                startcartoon[10]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                    startcartoon[10]->hide();
                                                    startcartoon[11] = Object::create("main_images/snoopy_start_11.png", startScene, 0, 0);
                                                    startcartoon[11]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                        startcartoon[11]->hide();
                                                        startcartoon[12] = Object::create("main_images/snoopy_start_12.png", startScene, 0, 0);
                                                        startcartoon[12]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                            startcartoon[12]->hide();

                                                            BGM1->stop();
                                                            bgm2_start();    // 징글벨 노래

                                                            startcartoon[13] = Object::create("main_images/snoopy_start_13.png", startScene, 0, 0);
                                                            startcartoon[13]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                                startcartoon[13]->hide();
                                                                startcartoon[14] = Object::create("main_images/snoopy_start_14.png", startScene, 0, 0);
                                                                startcartoon[14]->setOnMouseCallback([&](ObjectPtr, int, int, MouseAction)-> bool {

                                                                    startcartoon[14]->hide();

                                                                    main_intro = Object::create("main_images/snoopy_main_0.png", mainScene, 0, 0);
                                                                    // 게임 메인 메뉴 화면
                                                                    main_scene();


                                                                    return true;
                                                                });

                                                                return true;
                                                            });

                                                            return true;
                                                        });
                                                        return true;
                                                    });
                                                    return true;
                                                });
                                                return true;
                                            });
                                            return true;
                                        });
                                        return true;
                                    });
                                    return true;
                                });
                                return true;
                            });
                            return true;
                        });
                        return true;
                    });
                    return true;
                });
                return true;
            });
            return true;
        });
        return true;
    });
}






int main()
{
    
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    //setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);


    mainScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_main_s.png"); //게임 메인 화면
    endScene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_end_s.png"); // 게임 엔딩 화면
    end2Scene = Scene::create("Snoopy's Happy Christmas", "main_images/snoopy_endgame_s.png"); // 게임 엔딩 화면


    bgm1_start();

    init_intro();

    startGame(startScene);
    return 0;
}