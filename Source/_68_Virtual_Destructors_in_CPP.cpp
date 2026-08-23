//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_68_Virtual_Destructors_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _68 {
    class Base {
    public:
        Base() {
            std::cout << " Base" << std::endl;
        }

        virtual ~Base() {
            std::cout << "~ Base" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << " Derived" << std::endl;
        }

        ~Derived() {
            std::cout << "~ Derived" << std::endl;
        }
    };
}

void _68_Virtual_Destructors_in_CPP::main() {
    //因为虚析构函数，顾名思义，就是这两种概念的结合体
    //简单来说，，当存在多个子类构成继承体系时
    //假设存在基类A和派生类B 当B继承自A时，若需要通过基类指针操作派生类对象
    //虽然实际对象是B类实例，但通过基类指针执行删除操作时
    //我们需要确保派生类B的析构函数与基类A的析构函数都能正确执行

    _68::Base* base = new _68::Base;
    delete base;
    // Base
    //~ Base
    std::cout << " Base End----------------\n";

    _68::Derived* d = new _68::Derived;
    delete d; //删除时也调用了基类的析构函数
    // Base
    // Derived
    //~ Derived
    //~ Base
    std::cout << " Derived End----------------\n";

    _68::Base* bd = new _68::Derived;
    delete bd;
    //Base
    //Derived //很显然派生类的析构函数未被执行
    //~ Base
    //这问题很严重，会直接导致内存泄漏，稍后我就给你秀一波具体会产生什么后果
}
