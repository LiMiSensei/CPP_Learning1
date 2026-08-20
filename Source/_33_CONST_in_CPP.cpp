//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_33_CONST_in_CPP.h"

#include <iostream>

namespace _33 {
    class Entity {
    public:
        //mutable的作用就是允许const函数或方法修改特定变量
        mutable int y;//mutable表示可变的 即使放在const函数里也是可变的
        int *x;

        const int *const GetX() const {
            //三个const
            return x; //表示返回一个不可修改的指针 值也不能修改 同时方法也不修改成员值
        }

        void Get_X() const {
            //代表这个方法不会任何修改成员的值
        }
    };
}

void PrintEntity(const _33::Entity &e ) {
    //就是指原则上我不希望复制这个对象，只修改值或者读取，且没有指针中间层
}

void _33_CONST_in_CPP::main() {
    //const这个关键字，说实在有点'假 因为它对最终生成的代码影响微乎其微
    //它更像是类和结构体的一种可见性修饰 本质上是一种让代码更整洁的机制
    //同时约束开发者必须遵守某些编码规范 const本质上是你对代码的一种承诺
    //在这里你承诺某件事会保持不变 但这只是个承诺，你可以完全无视它，甚至可以食言
    int a = 5;
    const int MAX_AGE = 6; //这是个常量整数 他的值不可以改变

    int *x = new int;
    *x = 2;
    x = (int *) &MAX_AGE; //绕过const限制
    *x = 23;

    int *ptr = const_cast<int *>(&MAX_AGE);
    *ptr = 100; // 尝试写入

    memcpy((void *) &MAX_AGE, "\x64\x00\x00\x00", sizeof(int)); // 写入 100

    std::cout << "*x:" << *x << std::endl;
    std::cout << "MAX_AGE:" << MAX_AGE << std::endl;

    //const的另外用法 1 可以修改指针对象，但是不能修改值
    const int *y = new int;
    int const *y1 = new int; //效果一样
    y = (int *) &MAX_AGE;


    //const的另外用法 2 可以修改值，但是不能修改指针对象
    int *const z = new int;
    *z = 12;

    //const的另外用法 3 不可以修改值，也不能修改指针对象
    const int *const z1 = new int;
}
