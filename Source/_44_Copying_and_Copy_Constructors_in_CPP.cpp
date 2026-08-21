//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_44_Copying_and_Copy_Constructors_in_CPP.h"

#include <cstring>
#include <iosfwd>
#include <iostream>
#include <ostream>

namespace _44 {
    struct Vector2 {
        float x, y;
    };

    class String {
    private:
        char* m_Buffer;
        unsigned int m_Size;

    public:
        String(const char* str) {
            m_Size = strlen(str);
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, str, m_Size + 1);
            m_Buffer[m_Size] = 0;
        };

        String(const String& other)
            : m_Size(other.m_Size), m_Buffer(other.m_Buffer) {
            std::cout << "Copy String!" << std::endl;
            m_Buffer = new char[m_Size + 1];
            memcpy(this, &other, m_Size + 1);
        }

        ~String() {
            //由于赋值时使用的相同的指针，析构函数会两次释放该内存
            delete[] m_Buffer;
        }

        //友元变量
        friend std::ostream& operator<<(std::ostream& stream, const _44::String& string);

        char& operator[](unsigned int index) {
            //我们真正需要的是复制这块内存 我们需要让第二个字符串拥有独立的指针
            //正确的做法是编写拷贝构造函数
            return m_Buffer[index];
        }
    };



    std::ostream& operator<<(std::ostream& stream, const _44::String& string) {
        stream << string.m_Buffer;
        return stream;
    }
}

void PringtString( const _44::String& string) {
    std::cout << string << std::endl;
}

void _44_Copying_and_Copy_Constructors_in_CPP::main() {
    //今天我们要深入讲解拷贝操作 详细解析C++的拷贝构造函数
    // 拷贝操作本质是复制数据和内存 当需要完整复制某个对象或基本数据类型时
    // 但另一方面，冗余复制会带来负面影响 掌握其应用场景与规避方法

    // int a = 2;
    // int b = a; //复制
    // b = 3;
    //
    // _44::Vector2 vec1 = {2, 3};
    // _44::Vector2 vec2 = vec1; //复制
    //
    //
    // auto* vec3 = new _44::Vector2;
    // _44::Vector2* vec4 = vec3; //复制了指针，指针指向的内存内有任何变化
    //
     _44::String s = "Hello World!";
     _44::String s1 = s;
    // std::cout << s << std::endl;
    // std::cout << s1 << std::endl;

    PringtString(s);
    PringtString(s1);
}
