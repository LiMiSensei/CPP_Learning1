//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_22_Static_for_Classes_and_Structs_in_CPP.h"

#include <iostream>
#include <ostream>



struct Entity {
    static int x, y;

    static void Print() {
        std::cout << x << ":" << y << std::endl;
    }
};

int Entity::x; //设置static时要外部定义
int Entity::y;

void _22_Static_for_Classes_and_Structs_in_CPP::main() {
    //因为本质上所有实例共享的是同一个变量，不论你创建了多少个类对象

    Entity::x = 5;
    Entity::y = 6;

    Entity::x = 12;
    Entity::y = 41;

    Entity::Print();//静态方法无法访问示例成员
    Entity::Print();//静态方法无法访问示例成员
}
