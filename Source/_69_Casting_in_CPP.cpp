//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_69_Casting_in_CPP.h"

#include <iostream>
#include <ostream>

void _69_Casting_in_CPP::main() {
    //今天咱们来系统聊聊C++里的类型转换那些事儿
    // 我会详细讲讲C风格的类型转换 特指数据类型转换 或任何必要的数据转换
    // 如果把变量声明为整型 就不能随意当成双精度类型
    // 除非存在安全的自动类型转换 这里要进行的是显式类型转换
    // 类型转换的核心机制与实践应用 显式类型转换主要有两种实现方式
    // 一种是C风格的强制转换,另一种则是C++风格的强制转换
    int a = 5;
    double b = a;//无需显式声明类型转换
    double b1 = (int)(a + 5.3);
    std::cout << b << std::endl;
    std::cout << b1 << std::endl;

    double c = 3.1415;
    int d = (int)c;//这相当于我们明确指定要将该值转换为整数类型

    //--------------- C++ 规范
    double s = static_cast<int>(c) + 5.3;
    // 但大多数C++风格的类型转换都不会带来额外性能开销
    // 使用static_cast时编译器还会执行额外的编译期检查
    // reinterpret_cast同样以关键词形式呈现

    //double v = reinterpret_cast<int*>(&c) + 5.3;

    //dynamic_cast<>
}
