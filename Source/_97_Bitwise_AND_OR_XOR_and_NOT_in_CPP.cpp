//
// Created by LiMi on 2026/8/27.
//

#include "../Header/_97_Bitwise_AND_OR_XOR_and_NOT_in_CPP.h"

#include <iostream>
#include <ostream>

void _97_Bitwise_AND_OR_XOR_and_NOT_in_CPP::main() {
    auto a = true& false;//       有0替换存0  AOR
    std::cout << a << std::endl;//0
    auto b = true^ false; //XOR   相同就是0 不同就是1
    std::cout << b << std::endl;//1

    auto c = ~false;  //NOR       //取反
    std::cout << c << std::endl;//-1
    auto d = true|false;//        有1替换存1  XOR
    std::cout << d << std::endl;//1
}
