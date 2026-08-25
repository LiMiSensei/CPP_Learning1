//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_84_Track_MEMORY_ALLOCATIONS_the_Easy_Way_in_CPP.h"

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

namespace _84 {
    struct Object {
        int x, y, z;
    };
}

//声明一个全局的new重载

struct AllocationMetrics {
    uint32_t TotalAllocations = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocations - TotalFreed; }
};

static AllocationMetrics allocationMetrics;


void* operator new(std::size_t size) {
    allocationMetrics.TotalAllocations += size;
    std::cout << "Allocated size " << size << " butes\n";
    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    allocationMetrics.TotalFreed += size;
    std::cout << "memory:" << memory << " size:" << size << std::endl;
    free(memory);
}

static void PrintMemoryUserge() {
    std::cout << "Memory usage:" <<allocationMetrics.CurrentUsage()<<" Bytes"<< std::endl;
}

void _84_Track_MEMORY_ALLOCATIONS_the_Easy_Way_in_CPP::main() {
    //要写出能占满这么多内存的C++程序还真不太容易
    // 当程序进行内存分配时 具体来说是在堆内存上分配，这正是我们要讨论的重点
    // 若能掌握程序的内存分配位置 就有机会优化内存使用 从而提升程序运行效率
    // 因为堆内存分配并非最佳实践 此外，追踪内存分配位置
    // 还能深入理解程序的运行机制
    // 接下来我们要探讨如何精确定位每个内存分配的来源 仅需编写少量代码就能实现


    //我们的方法是重载new运算符
    _84::Object* obj = new _84::Object();
    PrintMemoryUserge();
    delete obj;
    PrintMemoryUserge();
    //利用这两个函数，我们就能创建一个内存分配追踪器
}
