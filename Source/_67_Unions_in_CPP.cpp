//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_67_Unions_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _67 {
    struct Vector2 {
        float x, y;
    };

    struct Vector4 {
        union {
            struct {
                float x, y, z, w;
            };

            struct {
                Vector2 a,b;
            };
        };
    };

    struct Union {
        union {
            float a;
            int b;
        };
    };
}

void _67_Unions_in_CPP::main() {
    //今天我们来深入讲解C++中的联合体（union）
    //联合体有点儿类似类类型，就像结构体一样
    //但不同之处在于，它同一时刻只能保存一个成员的数据
    //那么它就会占用4个变量乘以每个4字节
    //联合体一次只能使用一个成员变量
    //即便我定义四个浮点型变量 该联合体的内存占用仍是4字节
    //当我操作成员A时 例如修改成员A/B/C/D的数值时 实际操作的始终是同一片内存区域
    //如果将成员A赋值为5 成员D的值也会同步变为5这就是联合体的内存共享机制
    //但当你需要给变量起两个别名时，这个功能就派上用场了
    // 同时我还想用RGB这种颜色命名方式来访问它，让X/Y/Z分别对应R/G/B
    // 其实就是让X对应R，Y对应G，Z对应B这样的映射关系

    _67::Union u;
    u.a = 3.14;

    _67::Vector4 v4 = {
        1.0f, 2.0f,
        3.0f, 4.0f
    };

    v4.x = 4.0f;
    std::cout << &v4.a << std::endl;
}
