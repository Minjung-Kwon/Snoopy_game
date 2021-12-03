#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef hanoi_main_hpp
#define hanoi_main_hpp

#include <iostream>
#include <bangtal>
using namespace bangtal;

//�������
class hanoi_Bar;
class hanoi_Tower;
/*
ScenePtr hanoi_scene1, hanoi_scene2;
ObjectPtr hanoi_startButton, hanoi_endButton;
ObjectPtr hanoi_tower_img[3];
ObjectPtr hanoi_selectButton[3], hanoi_toButton[3], hanoi_clearButton;


//Ÿ�� ��ü ����
hanoi_Tower hanoi_tower[3];
hanoi_Tower hanoi_towerR;
int hanoi_tempTower;
//������� �ϳ���
*/
void hanoi_init();
ScenePtr hanoi_game_init();
void hanoi_create_scene2();
void hanoi_resetToButton();
bool hanoi_check_Clear();

#endif /* hanoi_main_hpp */