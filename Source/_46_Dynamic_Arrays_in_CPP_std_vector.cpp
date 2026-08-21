//
// Created by LiMi on 2026/8/22.
//

#include "../Header/_46_Dynamic_Arrays_in_CPP_std_vector.h"

#include <iostream>
#include <vector>

namespace _46 {
    struct Vertex {
        float x, y, z;
    };

    std::ostream& operator<<(std::ostream& os, const Vertex& v) {
        os << v.x << "," << v.y << "," << v.z;
        return os;
    }
}

void _46_Dynamic_Arrays_in_CPP_std_vector::main() {
    //即使没有任何模板知识也能轻松使用标准模板库
    //为什么命名为vector呢？ 说白了，它就是个数组
    //不过和C++原生数组不同 初始化动态数组时无需指定容量
    //当然也可以预分配指定容量 每添加一个元素，它的容量就会自动扩大
    //以EA为例，我们采用的是自主开发的EASTL容器库
    //一旦容量不足，系统就会在内存中开辟更大的存储空间

    _46::Vertex* v = new _46::Vertex[5];
    v[5];
    //技术上的首要考量是直接存储顶点对象比存储指针更高效
    //因为直接存储顶点对象可以实现内存的内联布局 动态数组的特性在于其内存空间是连续的
    //简单来说，只要条件允许，就该尽量采用这种内联分配方式
    std::vector<_46::Vertex> v1; //这是一个C++模板类
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});
    v1.push_back({1, 2, 3});

    std::cout << v1.size() << ":" << v1.size() << std::endl;

    //循环写法
    for (int i = 0; i < v1.size(); i++) {
        //std::cout << v1[i] << std::endl;
    }
    //vector写法
    for (_46::Vertex& v: v1) {
        std::cout << v << std::endl;
    }
    v1.clear();
}
