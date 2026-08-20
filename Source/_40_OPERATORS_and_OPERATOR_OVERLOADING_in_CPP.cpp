//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_40_OPERATORS_and_OPERATOR_OVERLOADING_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _40 {
    struct Vector2 {
        float x, y;

        Vector2(float x, float y) : x(x), y(y) {
        }

        /*Vector2 Add(const Vector2 &b) const {
            return Vector2(x + b.x, y + b.y);
        }*/
        /*Vector2 Mulity(const Vector2 &b) const {
            return Vector2(x * b.x, y * b.y);
        }*/

        Vector2 operator+(const Vector2& b) const {
            return Vector2(x + b.x, y + b.y);
        }

        Vector2 operator*(const Vector2& b) const {
            //*this + b 编译器会解析为 this->operator+(b)，
            //于是函数不断调用自己，直到栈空间耗尽崩溃
            return Vector2(x * b.x, y * b.y);
        }

        bool operator==(const Vector2& b) const {
            return x == b.x && y == b.y;
        }
        bool operator!=(const Vector2& b) const {
            return !(*this == b);
        }
    };
}

std::ostream& operator<<(std::ostream& stream, const _40::Vector2& other) {
    stream << other.x << ", " << other.y;
    return stream;
}

void _40_OPERATORS_and_OPERATOR_OVERLOADING_in_CPP::main() {
    using vec2 = _40::Vector2;

    std::cout << "OK" << std::endl;
    //运算符就是某种特定符号
    //比如解引用运算符 还有箭头运算符、加号和等号
    //逗号其实也是个运算符，圆括号同样如此
    //实际上就是给运算符赋予新功能，扩展参数或重新定义行为
    //它赋予开发者过高的控制权，反而容易产生低质量的代码
    //但本质上，运算符其实就是特殊函数
    vec2 position = vec2(1.0f, 1.0f);
    vec2 speed = vec2(2.0f, 2.0f);
    vec2 powerup = vec2(3.0f, 3.0f);

    vec2 result = position + speed * powerup;

    std::cout << result.x << std::endl;

    int* a = new int;
    int& b = *(a);
}
