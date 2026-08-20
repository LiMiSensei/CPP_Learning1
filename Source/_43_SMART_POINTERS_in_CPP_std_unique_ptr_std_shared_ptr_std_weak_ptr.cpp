//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_43_SMART_POINTERS_in_CPP_std_unique_ptr_std_shared_ptr_std_weak_ptr.h"

#include <iostream>
#include <memory>
#include <ostream>

namespace _43 {
    class Entity {
    public:
        Entity() {
            std::cout << "Entity::Entity()" << std::endl;
        }

        ~Entity() {
            std::cout << "~Entity()" << std::endl;
        }

        void Print() {
            std::cout << "Print()" << std::endl;
        };
    };
}

void _43_SMART_POINTERS_in_CPP_std_unique_ptr_std_shared_ptr_std_weak_ptr::main() {
    //智能指针这个话题最近在我的视频里频频出现
    //new操作符在堆内存中开辟空间，delete操作符则负责释放这些空间
    //智能指针就是用来实现内存自动管理的
    //说白了智能指针就是个包装盒，里面装着原始的裸指针
    //首先介绍最基础的一种智能指针：uniquepointer（独占指针）
    //uniquepointer是作用域指针，当离开其作用域时
    //唯一指针不可被复制，一旦复制操作发生 就会出现两个唯一指针同时引用同一内存块的异常状态
    //当任一指针结束生命周期时，系统将自动释放对应内存 这将使另一个指针变成悬垂指针
    //鉴于此，唯一指针被设计为禁止拷贝的智能指针类型

    std::unique_ptr<_43::Entity> ptr;
    {
        //它甚至根本不需要额外空间 它就是个栈上分配的对象而已
        // 就会自动调用delete释放指针指向的内存
        // 如果你想复制这个指针 可以将其传入函数或交由类来存储 你会遇到无法复制的问题
        // 因为这个对象不允许被拷贝
        ptr = std::make_unique<_43::Entity>();
        ptr->Print();
    }

    std::shared_ptr<_43::Entity> ptr2;
    {
        //如果需要共享对象资源，就轮到shared_ptr智能指针出场了
        ptr2 = std::make_shared<_43::Entity>();
    }

    std::weak_ptr<_43::Entity> ptr3;
    {
        //如果对象仍然有效，就能执行所需操作，而弱指针不会维持对象的生命周期
        ptr3 = std::weak_ptr<_43::Entity>();
    }
    //优先选用unique_ptr，它的系统开销更低
    //但若确实需要跨对象共享资源
}

