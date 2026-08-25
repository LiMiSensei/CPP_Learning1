//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_83_Small_String_Optimization_in_CPP.h"

#include <string>

void _83_Small_String_Optimization_in_CPP::main() {
    //具体来说是一种叫做'短字符串优化'（SmallStringOptimization，简称SSO）的技术
    //因为字符串总是背负着一些负面评价  千万别跟C++程序员聊性能问题
    //因为对这些C++大佬来说，要是发现代码运行慢 他们一眼就能看出问题所在
    //说真的，字符串在C++圈里简直就是原罪 不过话说回来，减少代码中的字符串使用
    // 能大幅提升运行速度，关键看你怎么用
    // C++标准库对小字符串的优化技巧 在C++中，堆内存分配可是个忌讳
    // 他们通过规定短字符串（即长度不太长的字符串）来解决这个问题
    // 只需分配一个栈上的小缓冲区 这样就避免了堆内存分配
    // 但当字符串长度达到16个字符以上时 就会触发malloc的堆内存分配机制

    std::string str = "Hello World!";
    //实际上它不会产生堆内存分配的开销 因为它符合C++中小型字符串的优化标准
    //一个完全不涉及堆内存的静态分配缓冲区里
}
