//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_29_Visibility_in_CPP.h"

namespace _29 {
    class Entity {
    protected:
        float f1,f2;
    private://表示私有的，只有该类才能读写
        int x, y;
    };

    class Player : public Entity {
    };
}

void _29_Visibility_in_CPP::main() {
    //它定义了类成员或方法在程序中的可访问范围
    //这里说的可见性就是指：哪些外部代码可以访问类成员、调用类方法
    //可见性完全不会改变程序的运行时行为
    //这本质上是编程语言提供的一种组织规范，旨在提升代码质量
    //私有（private)、保护（protected）和公有（public）
    //友元（friend）机制：friend是C++的正式关键字
    //使用friend外部类或函数声明为当前类的友元 友元能访问类的私有成员
}
