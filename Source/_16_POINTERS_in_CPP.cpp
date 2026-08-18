//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_16_POINTERS_in_CPP.h"

#include <cstring>

void _16_POINTERS_in_CPP::main() {
    //指针：它实际上就是个保存内存地址的整数值
    //类型不重要  4字节的整数

    void* ptr = 0;//0表示当前指针不可用
    void* ptr2 = nullptr;


    int var = 8;
    int* var_ptr = &var;//&表示询问var的内存地址

    //逆向操作，拿到指针修改内存的值
    *var_ptr = 10; //解引用

    char* buffer = new char[10];//申请1字节x10的缓冲区 并返回该内存的地址
    memset (buffer, 0, 10);//填充
    char** buffer_ptr = &buffer;//指向指针内存地址的指针
    delete[] buffer;    //释放内存
}
