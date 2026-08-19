//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_25_Destructors_in_CPP.h"

#include <iostream>

class Entity {
private:
    int x = 1, y = 1;

public:
    Entity(int x, int y) {
        std::cout << x << ":" << y << std::endl;
        this->x = x;
        this->y = y;
        std::cout << this->x << ":" << this->y << std::endl;
        std::cout << "Entity()" << std::endl;
    }


    void Print() const {
        std::cout << "Print:" << this->x << ":" << this->y << std::endl;
    }

    ~Entity() {
        std::cout << "~Entity()" << std::endl;
    }
};

void Function() {
    Entity e = Entity(1, 2);

    e.Print();
    e.Print();
}

void _25_Destructors_in_CPP::main() {
    //析构函数 析构函数则在对象销毁时自动触发 析构函数负责资源的释放与清理工作
    Function();
}
