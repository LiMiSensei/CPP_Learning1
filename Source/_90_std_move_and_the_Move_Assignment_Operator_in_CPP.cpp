//
// Created by LiMi on 2026/8/27.
//

#include "../Header/_90_std_move_and_the_Move_Assignment_Operator_in_CPP.h"

#include <cstdint>
#include <cstring>
#include <iostream>

namespace _90 {
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

        String& operator=(String&& other) noexcept {
            printf("Move!\n");
            if (this != &other) {
                delete [] m_Data; //最关键的部分
                m_Size = other.m_Size;
                m_Data = other.m_Data;

                //所谓空壳对象
                other.m_Size = 0;
                other.m_Data = nullptr;
            }
            return *this;
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

        Entity(String&& name) : m_Name((String &&) name) {
        }

        void PrintName() {
            m_Name.Print();
        }

    private:
        String m_Name;
    };
}

void _90_std_move_and_the_Move_Assignment_Operator_in_CPP::main() {
    using namespace _90;
    //今天我们要继续探讨移动语义这个话题，
    //系统学习了移动语义的核心概念和基础知识
    //真正实现将一个对象移动到另一个对象中究竟意味着什么？
    //第一个是std::move.这个函数到底是干什么用的
    //另一个是移动赋值运算符
    //现在让我们来探讨移动赋值运算符和std：：move

    /*
    Entity entity("Cherno");
    entity.PrintName();
    */

    String apple = "Apple";
    String dest0;


    std::cout << "apple.Print():";
    apple.Print();
    std::cout << "dest0.Print():";
    dest0.Print();

    dest0 = std::move(apple);

    std::cout << "apple.Print():";
    apple.Print();
    std::cout << "dest0.Print():" ;
    dest0.Print();


    //==================================
    /*String string = "Hello";
    String dest = (String &&) string; //右值是一个临时变量，启动移动语义
    String dest2(std::move(string)); //右值是一个临时变量，启动移动语义*/


    std::cin.get();
}
