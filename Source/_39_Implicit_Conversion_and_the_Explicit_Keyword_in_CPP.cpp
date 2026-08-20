//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_39_Implicit_Conversion_and_the_Explicit_Keyword_in_CPP.h"

#include <iostream>
#include <ostream>
#include <string>

namespace _39 {
    class Entity {
    private:
        int m_Age;
        std::string m_Nmae;

    public:
        std::string get_Age() {
            return m_Nmae;
        }

        explicit  Entity() : m_Age(0), m_Nmae("Unknown") {
        }

        explicit Entity(int age) : m_Age(age), m_Nmae("Unknown") {
        }

        Entity(std::string Nmae) : m_Age(0), m_Nmae(Nmae) {
        }
    };
}

void PrinterEntity(const _39::Entity &e) {
    //::cout << e.get_Age() << std::endl;
}

void _39_Implicit_Conversion_and_the_Explicit_Keyword_in_CPP::main() {
    //今天我们要详细讲解隐式构造的相关问题
    //隐式类型转换，以及explicit关键字的真正含义
    //隐式的意思就是你不用显式指明，编译器就会自动处理

    _39::Entity e0(22);
    //PrinterEntity(22); //映射转换

    PrinterEntity(_39::Entity(22));//如果使用explicit关键字，则要求显示

    _39::Entity e1("A");
    PrinterEntity(std::string("Cherno")); //映射转换
}
