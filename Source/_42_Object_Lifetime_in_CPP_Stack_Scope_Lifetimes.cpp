//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_42_Object_Lifetime_in_CPP_Stack_Scope_Lifetimes.h"

#include <iostream>


namespace _42 {
    class Entity {
    private:
        int x;

    public:
        Entity() {
            std::cout << "Entity()" << std::endl;
        }

        ~Entity() {
            std::cout << "~Entity()" << std::endl;
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
    };
}

int* CreateArray() {
    int array[50]; //没有堆分配
    return array;
}

void _42_Object_Lifetime_in_CPP_Stack_Scope_Lifetimes::main() {
    //今天我们要全面讨论对象生命周期的主题
    //但编程里的堆栈可不这么玩
    //作用域有多种类型，例如函数作用域
    {
        //_42::Entity e;
        _42::Entity* e1 = new _42::Entity();
        delete e1;
    }

    int* array = CreateArray();
    //例如智能指针 包括作用域指针或作用域锁等机制
    //其中最典型的要数作用域指针 本质上是指针的封装类
    //构造时会在堆上分配指针内存 析构时自动释放指针内存
    //这样就能实现内存的自动分配与释放

    {
        _42::ScopedPtr e = new _42::Entity();
    }
    std::cin.get();
}
