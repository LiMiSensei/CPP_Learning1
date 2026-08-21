//
// Created by LiMi on 2026/8/22.
//

#include "../Header/_47_Optimizing_the_usage_of_std_vector_in_CPP.h"

#include <iostream>
#include <ostream>
#include <vector>

namespace _47 {
    struct Vertex {
        float x, y, z;

        Vertex(float x, float y, float z)
            : x(x), y(y), z(z) {
        }

        Vertex(const Vertex& vertex)
            : x(vertex.x), y(vertex.y), z(vertex.z) {
            std::cout << "Vertex created" << std::endl;
        }
    };
}

void _47_Optimizing_the_usage_of_std_vector_in_CPP::main() {
    //本期视频主要讲解vector类的高阶用法 个绍其优化使用技巧，并部析其实现原理
    //并分享代码优化技巧，提升程序运行效率 许多人选择C++正是看中它的底层优化能力
    //所谓’了解环境’，就是要摸清系统原理和明确操作要点

    //首先创建向量对象，然后通过push_back方法添加元素 当向向量容器中插入新元素时
    // 当向量当前容量不足时 无法容纳待插入的新元素 向量就会自动触发内存重新分配
    // 并将原内存地址中的所有数据拷贝 到新的内存地址后释放原内存空间。这就是完整的操作流程
    // 这正是导致代码性能下降的一个常见根源 问题在于频繁的内存重分配会产生巨大的性能开销

    std::vector<_47::Vertex> vertices;
    vertices.reserve(10);
    vertices.emplace_back(0, 0, 0);//最终输出整洁美观，完全消除了冗余的复制操作
    vertices.emplace_back(0, 0, 0);
    vertices.emplace_back(0, 0, 0);

    //下面的代码单独使用会导致6次复制操作
    //vertices.push_back(_47::Vertex(0, 0, 0));
    //vertices.push_back(_47::Vertex(0, 0, 0));
    //vertices.push_back(_47::Vertex(0, 0, 0));

    std::cin.get();
}
