//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_66_Type_Punning_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _66 {
    struct Entity {
        int x, y;

        int* GetPositions() {
           return &x;
        }
    };
}

void _66_Type_Punning_in_CPP::main() {
    //今天我们要深入讲解C++中的类型双关（typepunning）技术
    //类型双关其实就是用来规避 C++类型系统的一种方法
    // 我们知道，C++是强类型语言 这意味着它有严格的类型检查机制
    // 我们不会把所有变量都用auto声明 类型检查机制，你仍能直接操作内存地址
    int a = 50;
    double value = a; //我们将4字节整型变量强行赋值给8字节双精度浮点型
    //本质上这就是将整型指针强制转换为双精度指针后解引用
    //这会导致程序越界读取整数相邻的4字节内存 这片越界访问的内存根本不属于当前整型变量
    std::cout << value << std::endl;

    //将强制写入8字节数据到4字节空间？几乎必然导致内存溢出崩溃
    double& v1 = *(double *) (&a);
    v1 = 0.0;

    //
    _66::Entity e = {5, 8};
    int* position = (int *) &e;
    std::cout << position[0] << ":"
            << position[1] << std::endl;

    int y = *(int *) ((char *) &e + 4); //关键在于我们实现了底层的内存操作
    //这正是C++的强项所在 能够灵活自如地操控内存 而内存管理正是编程中最关键的环节之一
    std::cout << y << std::endl;

    int* position1 = e.GetPositions();//我只是选择了一种不同的内存数据解析方式

    //将现有内存强行解释成另一种数据类型来操作
    //关键只需获取该类型的指针并进行指针类型转换
    //后续可随时解引用并直接操作对应数据
}
