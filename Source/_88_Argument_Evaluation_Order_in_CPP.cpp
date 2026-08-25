//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_88_Argument_Evaluation_Order_in_CPP.h"

#include <iostream>
#include <ostream>
void Function88(int a,int b,int c){}
void PrintSum88(int a,int b) {
    std::cout<<a<<" "<<b<<" "<<std::endl;
}
void _88_Argument_Evaluation_Order_in_CPP::main() {
    //具体来说，我准备在这个C++系列中开个小专题
    //专门分享一些C++的实用技巧和小窍门
    //今天我们要探讨的是参数求值顺序这个主题
    //因为在传入参数时，我们可以在其中编写对这些参数进行求值的表达式
    int a = 2;

    //若参数较多时，系统会优先对第一个参数求值吗？
    Function88(1,++a,a--);

    int value = 0;
    //很明显这是后置++运算符，表示会先使用原值
    //不过话说回来，我可能错了，因为这种情况属于未定义行为 结果无法预测
    PrintSum88(value++,value++);//编译模式属于 1 0 发布模式可能是0 0
}
