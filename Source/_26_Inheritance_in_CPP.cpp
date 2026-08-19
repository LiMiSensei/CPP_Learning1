//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_26_Inheritance_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _26 {
    class Entity {
    private:

    public:
        float X = 0.0f, Y = 0.0f;
        const char* Name = "";

    public:
        void Move(float x, float y) {
            X += x;
            Y += y;
        }

        void Print() {
            std::cout << Name << ":" << X << ":" << Y << std::endl;
        }
    };

    class Player : public Entity {
        //Player继承了所有Entity的成员
    public:
        void PrintName() {
            std::cout << "PrintName" << std::endl;
        }
    };
}


void _26_Inheritance_in_CPP::main() {
    // 类之间的继承是其核心特性之一
    // 继承可以建立类之间的层级关系 我们可以定义一个包含公共功能的基类
    // 然后基于该类进行扩展 派生出各个子类
    std::cout << "main()" << std::endl;

    _26::Player p;
    p.Move(1.0f, 1.0f);
    p.Print();
    std::cout <<"sizeof_P:"<<sizeof(p)<< std::endl;
    std::cout <<"sizeof_E:"<<sizeof(_26::Entity)<< std::endl;
    std::cin.get();
}
