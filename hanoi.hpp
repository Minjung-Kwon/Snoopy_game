#pragma once

//
//  hanoi.hpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/26.
//

#define _CRT_SECURE_NO_WARNINGS

#ifndef hanoi_hpp
#define hanoi_hpp

#include <iostream>
#include <bangtal>
using namespace bangtal;

//���� Ŭ����
class hanoi_Bar {
public:
    int index;
    ObjectPtr object;
    hanoi_Bar(int i, ScenePtr scene);
    hanoi_Bar() {};
    void setInfo(int i, ScenePtr scene);
};

//Ÿ�� Ŭ����
class hanoi_Tower {
public:
    hanoi_Bar* slot[4];//={nullptr}; //Ÿ���� ���� ���� ������ �˱� ���� ���������͸� ������.
    int tower_top = -1; //Ÿ���� ���밡 �������� �ִ���.
    int tower_index = -1; //Ÿ���� �� �� ���� ũ��.

    hanoi_Tower() {
        tower_top = -1;
        tower_index = -1;
    };
    int check_top();
    int check_tower_index();
};

#endif /* hanoi_hpp */

