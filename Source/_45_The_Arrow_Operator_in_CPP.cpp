//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_45_The_Arrow_Operator_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _45 {
    class Entity {
    public:
        void Print() const {
            //std::cout << "1" << std::endl;
        }
    };

    class ScopedPtr {
    private:
        Entity* entity;

    public:
        ScopedPtr(Entity* entity) : entity(entity) {
        }

        ~ScopedPtr() {
            delete entity;
        }

        Entity* GetObject() {
            return entity;
        }

        Entity* operator->() {
            return entity;
        }

        const Entity* operator->() const {
            return entity;
        }
    };

    struct Vector3 {
        float x, y, z;
    };
}

void _45_The_Arrow_Operator_in_CPP::main() {
    //今天我们要全面讲解C++中的箭头操作符
    //我们将详细解析箭头操作符的实际功能
    _45::Entity e;
    e.Print();

    _45::Entity* e1 = &e;
    (*e1).Print();
    e1->Print();

    _45::Entity& e2 = *e1;
    e2.Print();

    _45::ScopedPtr scopedPtr = new _45::Entity;
    scopedPtr.GetObject();
    scopedPtr->Print(); //这个->符号将调用Entity的功能

    //当需要将数据转为字节流并计算偏移量时
    //auto offset = ((_45::Vector3*)nullptr)->x;//用于获取内存中特定值的偏移地址
    //std::cout << "offset: " << offset << std::endl;
}
