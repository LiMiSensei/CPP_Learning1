//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_34_The_Mutable_Keyword_in_CPP.h"

#include <iostream>
#include <ostream>
#include <string>

namespace _34 {
    class Entity {
    private:
        std::string m_Name;
        mutable int m_debugCount = 0;

    public:
        const std::string &GetName() const {
            m_debugCount++;
            return m_Name;
        }
    };
}


void _34_The_Mutable_Keyword_in_CPP::main() {
    //mutable关键字其实有两种截然不同的用途
    //第一种用法与const关键字相关 第二种用法则与lambda表达式相关
    const _34::Entity e; //保持计数的功能，这就是mutable
    e.GetName();

    //第二种 //lambda本质上是个即用即弃的临时函数
    int x = 8;
    auto f = [=]() {
        //x++; //这里就用不了外部变量
        std::cout << "Hello:" << x << std::endl;
    };
    auto f1 = [=]()mutable {
        x++; //这里就能用外部变量
        std::cout << "Hello:" << x << std::endl;
    };

    f();
    f1();
}
