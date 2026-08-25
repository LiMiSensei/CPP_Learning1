//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_85_lvalues_and_rvalues_in_CPP.h"

#include <string>

int GetValue() {
    return 10;
}

int& GetValue1() {
    int i = 1;
    return i;
}

void SetValue(int value) {
}

void SetValue1(int& value) {
}

void SetValue2(const int& value) {
}

void PrintName(std::string& name) {
    //不接受临时的值
}

void PrintName1(const std::string& name) {
    //同时兼容临时的值
}

void PrintName2( std::string&& name) {
    //只接受临时的值
}

void _85_lvalues_and_rvalues_in_CPP::main() {
    //今天我们要讲解C++中的左值和右值
    //还会介绍左值引用和右值引用的知识
    //很多人都把L值称为定位值 这是因为它具有位置属性，我们稍后会详细解释
    // 不过关于L值和R值的定义方式其实有很多种
    int i = 10;
    int a = i;

    //获取这个右值（临时值），并将其存入左值（Lvalue）中
    int i1 = GetValue(); //getValue函数返回的是一个右值（Rvalue） 它返回的是个临时值
    int a1 = i1;
    //GetValue() = 5;//可修改指的是不能是常量（const），左值（Lvalue）则必须是有效的存储位置
    GetValue1() = 5; //这就是所谓的左值引用（Lvaluereference），这时我们就需要为这个值提供存储空间

    SetValue(i); //这里演示的是用左值调用set_value，接下来是用右值调用的情况
    SetValue(10); //这是个临时值，也就是右值。我反复强调就是希望大家能真正掌握这个关键概念

    //左值引用只能引用左值。要验证这点很简单，只要在这里加个&符号就行
    SetValue1(i);
    //SetValue1(10);//现在我声明一个int引用，这是个左值引用。可以看到编译器立即报错了
    //这到底是怎么回事呢？其实这里有一条特殊规则：虽虽然我们无法直接获取右值的左值引用

    int i2 = 10;
    //这其实是一种折中方案。实际上，编译器会创建一个临时变量来存储数据
    //int& a2 = 10;//所以只要加上const关键字，就能正常运行。这就是C++的特殊规则
    const int& a3 = 10;

    SetValue2(i);
    SetValue2(10); //既能接受左值，也能接受右值，这正是const左值引用的特性

    //在这个示例中，等号左侧的都是左值 而这里右侧的所有内容都是右值（Rvalue）
    std::string firstName = "First Name";
    std::string lastName = "Last Name";
    //这个表达式属于右值（Rvalue），它实际上是一个临时对象
    std::string fullName = firstName + lastName;

    //PrintName(firstName + lastName);//也能兼容实际存在的左值变量
    PrintName1(firstName + lastName);//因为它们既能兼容临时对象
    PrintName2(firstName + lastName);//只接受临时的值
}
