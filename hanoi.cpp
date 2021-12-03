//
//  hanoi.cpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/26.
//

#define _CRT_SECURE_NO_WARNINGS

#include "hanoi.hpp"
#include <iostream>
#include <bangtal>
using namespace bangtal;

//���� Ŭ����
hanoi_Bar::hanoi_Bar(int i, ScenePtr scene) :index(i) {
    char buf[30];
    sprintf(buf, "hanoi_images/hanoi_%d.png", i);
    object = Object::create(buf, scene, 240, 220 + 50 * i); //����� ��� ù��° Ÿ������ �����ȴ�.
};

void hanoi_Bar::setInfo(int i, ScenePtr scene) {
    index = i;
    char buf[30];
    sprintf(buf, "hanoi_images/hanoi_%d.png", i);
    object = Object::create(buf, scene, 240, 220 + 50 * i); //����� ��� ù��° Ÿ������ �����ȴ�.
};

//Ÿ�� Ŭ����
/*
hanoi_Tower::hanoi_Tower()
    {

    }*/

int hanoi_Tower::check_top() //Ÿ���� ���밡 �������� �ִ��� üũ�մϴ�.
{
    tower_top = -1; //�ʱ�ȭ
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] != nullptr)
            tower_top = i;
    }
    return tower_top;
}

int hanoi_Tower::check_tower_index() //�� �� ������ ũ�⸦ Ȯ���մϴ�.
{
    tower_index = -1; //�ʱ�ȭ
    if (check_top() == -1)
    {
        //showMessage("Ÿ���� ������ϴ�.");
    }
    else if (check_top() >= 0) {
        tower_index = slot[check_top()]->index;
    }
    return tower_index;
}
