//
// Created by LiMi on 2026/8/20.
//

#include "_37_How_to_CREATE_INSTANTIATE_OBJECTS_in_CPP.h"


#include <iostream>
#include <ostream>
#include <string>

namespace _37 {
    using String = std::string;

    class Entity {
    private:
        String m_Name;

    public:
        Entity() : m_Name("Unknown") {
        }

        Entity(const String &name) : m_Name(name) {
        }

        const String &GetName() const { return m_Name; }
    };
}

/*void Function() {
    _37::Entity e("Test");
    //在这里不能这样做 这里是栈帧
    //在函数里面创建这个对象在函数结束后就立即被销毁了
}*/

void _37_How_to_CREATE_INSTANTIATE_OBJECTS_in_CPP::main() {
    //我们将全面探讨如何在C++中创建对象
    //现在我们需要实例化这个类，具体该如何实现呢？
    //这两种实现方案的本质区别在于内存的分配位置  即对象实际被创建的内存空间

    //即栈区和堆区  此外，还有其他内存区域，比如   一般只有1MB到2MB
    //暂时只需记住栈（stack）和堆（heap）这两个概念
    //这两种方式在功能特性上存在显著差异

    //以栈对象为例，它们具有自动生命周期特性 其生命周期完全受限于声明它们的作用域范围
    //内存会被自动回收，因为作用域结束时栈帧会自动弹出

    //堆内存如同一个庞大而神秘的领域 这个对象就会一直驻留，直到你主动决定

    //答案是绝大多数情况下 因为这是C++中最快的实现方式
    _37::Entity e("Test"); //因为这看起来像是没初始化对象，但其实已经初始化了
    std::cout << e.GetName() << std::endl;

    _37::Entity *e1;
    {
        //在for循环，if里面，还有这个花括号里面都不能这样实现
        _37::Entity e2("Test");
        e1 = &e2;
        std::cout << e2.GetName() << std::endl;
        //生命周期结束
    }


    _37::Entity *e3;
    {
        //在for循环，if里面，还有这个花括号里面都不能这样实现
        _37::Entity *e2 = new _37::Entity("Test");
        e3 = e2;
        std::cout << (*e2).GetName() << std::endl;
        std::cout << e2->GetName() << std::endl;
        //生命周期持续
    }

    delete e3;//手动释放
}
