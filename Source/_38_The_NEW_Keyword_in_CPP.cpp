//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_38_The_NEW_Keyword_in_CPP.h"

#include <string>

namespace _38 {
    class Entity {
    private:
        std::string m_Name;

    public:
        const std::string &GetName() { return m_Name; }
    };
}

void _38_The_NEW_Keyword_in_CPP::main() {
    //new'关键字之是因为它涉及相当底层的实现机制
    //选择使用C++就意味着你必须重视内存管理、性能优化等底层细节
    //刚接触C++时，你可能会觉得：这不和Java差不多嘛，C++也没那么难
    //实际上，new关键字的本质功能是在堆内存中分配空间
    //具体用法是在new后声明数据类型，可以是类、基本类型或数组
    //编译器会根据类型声明自动计算所需分配的内存大小（以字节为单位）
    //获取这个数值后，程序会向操作系统（准确来说是C标准库）发出请求 请分配4个字节的内存空间
    //这时有趣的部分就开始了——系统需要找到一块连续的4字节内存空间
    //找到合适地址后，系统会返回指向该内存地址的指针
    //没错，这就是调用new时的关键点-它需要时间
    //其实有个叫空闲列表的机制，专门记录哪些地址有空闲内存
    //但核心要点是：new操作符本质上会寻找一块内存区域 容量足以满足我们的存储需求
    int a = 2;
    int *b = new int[50];

    _38::Entity *e = new _38::Entity;
    _38::Entity *e1 = (_38::Entity *) malloc(sizeof(_38::Entity));

    //malloc函数接收所需内存的字节数作为参数，返回一个void类型的指针

    delete e;
    delete[] b;
}
