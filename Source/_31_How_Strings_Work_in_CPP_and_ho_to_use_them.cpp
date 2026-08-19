//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_31_How_Strings_Work_in_CPP_and_ho_to_use_them.h"

#include <iostream>
#include <ostream>
#include <string>
#include <windows.h>


void PrintString(const std::string &s) {
    //需要使用引用，不然就是复制字符串
    std::cout << s << std::endl;
}

void _31_How_Strings_Work_in_CPP_and_ho_to_use_them::main() {
    //因为要分配1KB内存的话 直接分配1024个char类型就搞定了
    //这种特性对处理字符串也很方便，毕竟C++默认处理字符的方式
    //但在C++中 我们默认每个字符占用1个字节
    //有些字符集的字符大小远超1个字节 包括2字节、3字节甚至4字节的字符都存在


    const char *str = "Hello World!"; //这其实是C语言定义字符串的方式
    std::cout << str << std::endl;
    //delete[] str;//要删除

    std::string s = "How Strings Work in C++"; //C++库
    s += "中文来了"; //GBK 会出错 使用UTF-8
    int len = s.length();
    int size = s.size();
    bool contains = s.find("C++") != std::string::npos;
    std::cout << s << "\nlen:" << len
            << " size:" << size
            << " contains:" << contains
            << std::endl;

    char name[7] = {'C', 'h', 'e', 'r', 'n', 'o', 0};
    std::cout << name << std::endl; //Chernop@�Z╗ //控制台不知道休止符
}
