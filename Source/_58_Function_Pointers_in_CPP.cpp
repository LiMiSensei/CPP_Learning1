//
// Created by LiMi on 2026/8/23.
//

#include "../Header/_58_Function_Pointers_in_CPP.h"

#include <iostream>
#include <ostream>
#include <vector>


void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

void HelloWorldFun(int a) {
    std::cout << "Hello World!" << std::endl;
}

void ForEach(const std::vector<int>& values, void (*f)(int)) {
    for (int value: values) {
        f(value);
    }
}

void _58_Function_Pointers_in_CPP::main() {
    //理解函数指针的概念、用法和优势，最有效的方式就是通过实际示例演示
    //HelloWorld();

    //======================================================
    typedef void (*HelloWorldFunction)();
    HelloWorldFunction f = HelloWorld;
    f();
    //======================================================


    //函数本质上就是CPU指令
    void (*function)() = &HelloWorld;
    //我们要告诉编译器：在这个可执行文件里 帮我定位这个helloworld函数
    function(); //执行函数

    //======================================================
    typedef void (*HelloWorldFunInt)(int);
    HelloWorldFunInt ff = HelloWorldFun;
    ff(8);
    //======================================================
    std::vector<int> v = {1, 2, 3, 4, 5};

    ForEach(v, HelloWorldFun);
    ForEach(v, [](int value) {
        std::cout << "Hello World!" << std::endl;
    });
}
