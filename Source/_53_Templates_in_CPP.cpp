//
// Created by LiMi on 2026/8/22.
//

#include "../Header/_53_Templates_in_CPP.h"

#include <iostream>

namespace _53 {
    //这意味着这是一个在编译时实例化的模板
    template<typename T>
    void Print(T t) {
        std::cout << t << std::endl;
    }


    template<typename T, int N>
    class Array {
    private:
        T m_Array[N];

    public:
        T GetSize() const { return N; }
    };
}

void _53_Templates_in_CPP::main() {
    //但考虑到这是高阶内容，我想还是稳妥点慢慢来
    //熟悉Java或其他语言的同学可能觉得它类似泛型概念，对吗？
    //不对不对，准确说是功能碾压那些托管语言的泛型实现，懂我意思吧？
    //模板（T）的功能与宏指令颇为相似 但泛型编程受制于类型系统的严格约束及其他限制因素
    //模板的灵活性则显著优于泛型 简言之，模板允许你定义一个随调用方式实时编译的代码模板
    //编译器可以根据预设规则自动为你生成代码
    //实际上是在创建一种代码蓝图，当调用函数时
    //通过传入不同参数，就能动态控制模板生成的最终代码

    //仅在调用时才会生成具体的实现代码
    _53::Print<const char *>("Hello World");
    _53::Print<int>(123);
    _53::Print(123.f);
    _53::Print('a');

    //这是C++中的一种元编程方式
    //_53::Array<std::string, 5> array;
    //std::cout << array.GetSize() << std::endl;
}
