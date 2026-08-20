//
// Created by LiMi on 2026/8/20.
//

#include "_35_Member_Initializer_Lists_in_CPP_Constructor_Initializer_List.h"

#include <iostream>
#include <ostream>

namespace _35 {
    class Entity {
    private:
        int x, y;

    public://成员初始化列表
        Entity() : x(0), y(0) {
            //x = 0; 虽然与上面写法一致 但是在时机不同，下面的可能会实例化两次
            //y = 0; 先在括号后面用引号，在变量名()
        }

        Entity(int x, int y) : x(x), y(y) {
        }

        void GetXY() {
            std::cout << "x=" << x << " y=" << y << std::endl;
        }
    };
}

void _35_Member_Initializer_Lists_in_CPP_Constructor_Initializer_List::main() {
    //今天我们要讲解的是构造函数中的成员初始化列表
    _35::Entity e0;
    e0.GetXY();

    _35::Entity e1 = _35::Entity(1, 2);
    e1.GetXY();
}
