//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_30_Arrays_in_CPP.h"

#include <iostream>
#include <ostream>

void _30_Arrays_in_CPP::main() {
    //数组（array）本质上是一种管理变量集合的方法
    //它其实就是一组同类型变量，存储在连续内存空间
    //因为在无数场景下，我们需要表示完整的数据集合
    //处理批量数据时，逐个创建变量显然不是明智之举
    //在C++中无法直接获取数组长度
    //永远不要试图直接从数组内存中获取其长度
    int example[50];
    example[0] = 0;
    for (int i = 1; i < 50; i++) {
        example[i] = i;
        //std::cout << i << std::endl;
    }
    //example[-1] = 0;//越界
    int *ptr = example;
    *(int *) ((char *) ptr + 8) = 6; //指定位置修改数值

    std::cout << example << std::endl;

    //但两者的生命周期特性存在差异
    {
        //由于数组在堆栈上分配栈指针存储着对应的内存偏移量
        int e1[5]; //栈上 程序离开时销毁
        int len = sizeof(e1) / sizeof(int);
        std::cout << "len:" << len << std::endl;
        for (int i = 1; i < 5; i++) {
            e1[i] = i;
        }

        int *another = new int[5]; //堆上 需要自己手动删除
        for (int i = 1; i < 5; i++) {
            another[i] = i;
        }
        delete[] another;
    }
    // 例如当函数需要返回一个数组时 就必须使用new关键字来分配内存
    // 除非通过参数传入预分配的内存地址 若想从函数返回新创建的数组
    // 特别是当数组在函数内部动态生成时 就必须使用new关键字
    // 此外还需考虑内存间接引用的问题 简而言之，由于我们实际操作的是指针
    // 该指针会指向存储实际数组的内存块 这里存储着实际数组数据，但会导致内存碎片化问题
    // 还会引发缓存失效等各种复杂问题
    std::cin.get();
    //得先定位实体对象，再找到数组位置，相当费周折
    //因此最佳做法是尽可能在栈上创建数组，以避免这种间接访问
    //因为这种内存地址的间接跳转会明显拖累系统性能
}
