//
// Created by LiMi on 2026/8/18.
//

#include "../Header/_8_Variables_in_CPP.h"

#include <iostream>

void _8_Variables_in_CPP::main() {
    int variable = 8;
    {
        char ch;//占用一字节
        unsigned char uch;//占用一字节 去除符号
        short sh;//占用两字节
        int in;//占用四字节
        long lo;//占用四字节
        long long lolong;//占用八字节

        unsigned variable = 8;
        std::cout << variable << std::endl;

        char a = 'A';
        //std::cout  << "原始的char的值：" + a << std::endl;

        a = 65;
        //std::cout << "设置数字后char的值：" + a << std::endl;

        float f = 65.0;//实际上是双精度
        float _f = 65.0f;//这是是单精度
        double d = 65.0;

        bool b = true; //占用一字节
        std::cout << R"( bool value is:)"+b << std::endl;

        bool* b1 = new bool;//指针
        bool& b2 = *b1;//引用
    }
    std::cin.get();
}
