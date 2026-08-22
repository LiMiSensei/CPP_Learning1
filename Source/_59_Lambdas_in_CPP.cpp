//
// Created by LiMi on 2026/8/23.
//

#include "../Header/_59_Lambdas_in_CPP.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>

namespace _59 {
    void ForEach(const std::vector<int>& values, const std::function<void(int)>& f) {
        for (int value: values) {
            f(value);
        }
    }
}

void _59_Lambdas_in_CPP::main() {
    //今天我们要讲解的是lambda表达式，本质上它相当于
    // 一种可以创建所谓匿名函数的方法 简单来说，它让我们无需正儿八经地声明函数
    // 就能快速创建一个临时函数来用 当我们需要演示某些代码片段时
    // 声明一个会被编译成符号的正式函数
    // 说白了，lambda就是一种无需明确定义函数即可实现函数功能的方法

    //我好奇这个捕获机制包含哪些内容或可能的值呢？

    //所以当我们在lambda表达式中引用外围作用域的变量时，比如这个函数体外声明的变量

    std::vector<int> values = {1, 2, 3, 4, 5};

    int a = 5;

    //等号表示值传递，而&符号则启用引用传递
    auto lambda = [&a](int value) {
        //std::cout << value << a << std::endl;
    };
    _59::ForEach(values, lambda);
    //或者当Lambda表达式需要修改原始数据时
    //若对引用传递的概念不太明确

    auto it = std::find_if(values.begin(), values.end(),
                           [](int value) {
                               return value > 5;
                           });
    std::cout << *it << std::endl;
}
