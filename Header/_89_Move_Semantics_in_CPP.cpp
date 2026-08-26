//
// Created by LiMi on 2026/8/27.
//

#include "_89_Move_Semantics_in_CPP.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>

namespace _89 {
    class String {
    public:
        String() = default;

        String(const char* string) {
            printf("Created!\n");
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            memcpy(m_Data, string, m_Size);
        }

        String(const String& other) {
            //拷贝构造函数
            printf("Copy!\n");
            m_Size = other.m_Size;
            m_Data = new char[other.m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }

        //移动构造函数
        String(String&& other) noexcept {
            //只接受临时变量  不抛出异常
            printf("Move!\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            //所谓空壳对象
            other.m_Size = 0;
            other.m_Data = nullptr;
            //memcpy(m_Data, other.m_Data, m_Size);
            //实际上只是引用同一块内存
        }


        ~String() {
            printf("Destoryed!\n");
            delete m_Data;
        }

    public:
        void Print() {
            for (uint32_t i = 0; i < m_Size; ++i) {
                printf("%c", m_Data[i]);
            }
            printf("\n");
        }

    private:
        char* m_Data;
        uint32_t m_Size;
    };

    class Entity {
    public:
        Entity(const String& name) : m_Name(name) {
        }

        Entity(String&& name) : m_Name((String&&)name) {
        }

        void PrintName() {
            m_Name.Print();
        }

    private:
        String m_Name;
    };
}

void _89_Move_Semantics_in_CPP::main() {
    //移动语义。简单来说 移动语义的核心功能就是实现对象转移
    //直到C+十11引入了R值引用 这才使移动语义成为可能
    // 其核心理念在于：当我们编写C++代码时 经常会遇到无需实际执行的情况
    // 或者需要将对象从一个位置原样复制到另一个位置时
    // 但这确实是实现对象跨位置转移的唯一途径 当需要将对象传入会获取其所有权的函数时，复制操作就不可避免
    // 同理，当函数需要返回对象时 仍需在函数内部创建对象并返回，这本质上仍是数据复制
    // 在当前栈帧中构造一个临时对象 无论在哪个调用位置，都得先构造再传参拷贝到目标函数
    // 这种做法很低效，因为对象不需要在当前上下文使用，而是要在目标函数里才用得上
    // 但又没法直接就地构造，必须通过参数传递链来中转，导致代码臃肿。虽然
    // 如果对象只是简单数据类型（比如几个整型变量） 那拷贝操作的性能影响可以忽略
    // 但如果是资源密集型的堆内存对象呢？ 以字符串对象为例，每次拷贝都会
    // 触发完整的堆内存深拷贝 这正是移动语义大显身手之处 若能直接移动对象而非复制
    _89::Entity entity("Cherno");
    entity.PrintName();

    std::cin.get();
}
