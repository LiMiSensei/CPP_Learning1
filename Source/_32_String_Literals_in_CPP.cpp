//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_32_String_Literals_in_CPP.h"

#include <cstring>
#include <iostream>
#include <ostream>

void _32_String_Literals_in_CPP::main() {
    auto a = "Cherno";
    auto ba = "Ch\0erno"; //strlen(b) 会显示2 因为\0是休止符
    {
        char* name = "Cherno"; //所以必加限定符 const
        //name[2] = 'a';//这是错误的，不能修改位于常量内存的区域
    }
    {
        char name[] = "Cherno";
        name[2] = 'a';//这是可以的
        std::cout << name << std::endl;
    }
    {
        const char8_t *name1 = u8"Cherno";//一字节
        const wchar_t* wname1 = L"Cherno";//宽字符要加入L 双字节
        const char16_t* name2 = u"Cherno";//字符要加入u
        const char32_t* name3 = U"Cherno";//字符要加入U
    }
    {
        using namespace std::string_literals;
        std::string str = "Cherno"s + "hello";
    }
    //字符串字面量总是存储在只读内存中

    std::cout << strlen(a) << std::endl;
}
