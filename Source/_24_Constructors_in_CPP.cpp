//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_24_Constructors_in_CPP.h"

#include <iostream>
#include <ostream>
class Entity1 {
public:
    int x, y;

    Entity1() {
        x = 1;
        y = 1;
    }

    Entity1(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void Print1() {
        std::cout << "x = " << x << " y = " << y << std::endl;
    }
};

class Log {
public:
    Log() = delete;//变成单例模式
    static void Print1() {
        std::cout << "Log" << std::endl;
    }
};

void _24_Constructors_in_CPP::main() {
    // 构造函数是一种特殊方法，每当实例化对象时就会自动调用
    // 该方法会在每次实例化对象时自动触发
    Entity1 e;
    e.Print1();

    Log::Print1();
}
