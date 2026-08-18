//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_17_REFERENCES_in_CPP.h"

#include <iostream>
#include <ostream>

void Increment_copy(int value) {
    {
        //如果使用 int value作为输入就会复制再++
        int temp = value;
        temp++;
    }
}

void Increment_ref(int &value) {
    {
        //如果是传入引用
        int temp = value;
        temp++;
        value = temp; //差不多是这个意思
    }
}

void Increment_ptr(int *value) {
    *value += 1;
}

void _17_REFERENCES_in_CPP::main() {
    //引用其实就是指针
    //说白了就是给指针加了一层语法糖，目的是
    //这样读起来更轻松，理解起来也更顺畅
    //引用已有变量的方法 与指针不同（指针可以新建变量）

    //因为引用必须指向已定义的变量
    //它们既不占用内存空间，也不分配存储资源

    int a = 0;
    int b = 100;
    int &ref = a; //引用 （这个变量实际不存在）引用必须立即初始化
    int *ptr = &a; //指针

    ref = 1;
    //ref = b;//引用所引用的对象不能更改（对象不能更改）
    std::cout << "ref=1:" << a << std::endl;

    Increment_copy(a);
    std::cout << "copy:" << a << std::endl;

    Increment_ref(ref); //引用
    std::cout << "ref:" << a << std::endl;

    Increment_ptr(ptr); //指针
    std::cout << "ptr:" << a << std::endl;
    //表格
    //特性	        值传递 int	引用传递int&	        指针传递 int*
    //能否修改外部变量	❌ 不能	    ✅ 能	            ✅ 能（需解引用）
    //能否传入字面量	✅ 能	    ❌ 不能（需左值）	    ❌ 不能（需地址）
    //是否可为空	    N/A	❌      不能	✅              可以传 nullptr
    //语法复杂度	    简单	        最简单（像普通变量）	 较复杂（需 * 和 &）
    //能否重新指向	N/A	        ❌ 不能	             ✅ 可以改指向
}
