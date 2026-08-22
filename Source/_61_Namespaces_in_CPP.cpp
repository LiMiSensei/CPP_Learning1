//
// Created by LiMi on 2026/8/23.
//

#include "../Header/_61_Namespaces_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _61Test1 {
    void print(const char& text) {
        std::cout << text << std::endl;
    }
}

namespace _61Test2 {
    void print(const char* text) {
        std::cout << text << std::endl;
    }
}

void _61_Namespaces_in_CPP::main() {
    //今天我们将深入讲解C++的命名空间机制
    //命名空间的主业就是防重名
    //说白了，你要是搞不懂namespace为啥存在，记住一点：就为防重名
    //我们希望能在不同上下文中使用相同名称的符号
    namespace a = _61Test1;
    using namespace _61Test2;
    print("_61_Namespaces_in_CPP");
    //绝对不要在头文件里这么干
}
