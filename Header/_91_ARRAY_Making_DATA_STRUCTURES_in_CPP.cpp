//
// Created by LiMi on 2026/8/27.
//

#include "_91_ARRAY_Making_DATA_STRUCTURES_in_CPP.h"

#include <array>
#include <iostream>
#include <ostream>

namespace _91 {
    template<typename T, size_t S>
    class Array {
    public:
        constexpr int Size() const { return S; }
        T operator[](int index){return m_Data[index];}
    private:
        T m_Data[S];
    };
}

void _91_ARRAY_Making_DATA_STRUCTURES_in_CPP::main() {
    //这里所说的数据结构，指的是数组、链表、集合、映射、树等常见类型
    int size = 5;
    int array[size];

    int* heapArray = new int[size];
    delete [] heapArray;

    //=================

    std::array<int, 10> collection;

    for (int i = 0; i < size; i++) {
        std::cout << i << std::endl;
    }
    //=================
    int s = 2;
    int data[size];

    //=================

    int size1 = 5;
    _91::Array<int, 5> data3;

    constexpr int size2 = 5;
    _91::Array<int, 10> data4;

    static_assert(data4.Size() < 11, "Size is too large");

    _91::Array<std::string,data4.Size()> newArray;
    const auto& arrayReference = data4;
    for (int i = 0; i < data4.Size(); i++) {
        //arrayReference[i] = 2;
        //std::cout << arrayReference[i] << std::endl;
    }

    //====================
}
