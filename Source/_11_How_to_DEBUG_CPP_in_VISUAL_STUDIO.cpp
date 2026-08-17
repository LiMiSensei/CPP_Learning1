//
// Created by LiMi on 2026/8/18.
//

#include "../Header/_11_How_to_DEBUG_CPP_in_VISUAL_STUDIO.h"

#include <iostream>

void _11_How_to_DEBUG_CPP_in_VISUAL_STUDIO::main() {
    //断点就是程序运行到特定位置时，调试器会自动暂停执行的位置
    //可以暂停程序运行，直接查看内存内容
    //步入、步过和步出
    int a = 8;
    a++;
    const char* string = "Hello";

    for (int i = 0;i< 5;i++) {
        const char c = string[i];
        std::cout << c<<std::endl;

    }
    //还没初始化时会用CC来初始化内存 表示未赋值状态
}
