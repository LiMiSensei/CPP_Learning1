//
// Created by LiMi on 2026/8/23.
//

#include "../Header/_57_Static_Arrays_in_CPP_std_array.h"

#include <array>
#include <iostream>

void PrintArray(const std::array<int, 5>& data) {
    for (int i = 0; i < data.size(); i++) {}
}

void _57_Static_Arrays_in_CPP_std_array::main() {
    //今天我们要深入讲解C++的标准数组（stdarray）
    //本质上这是C++标准库提供的静态数组操作类

    std::array<int, 5> datas;
    datas[0] = 2;
    datas[1] = 1;
    datas.size();

    //由此可见，标准数组类与传统C风格数组几乎别无二致
    int dataDld[5];
    dataDld[0] = 1;

    std::cin.get();

    //以及它相比普通整型数组的优势所在
}
