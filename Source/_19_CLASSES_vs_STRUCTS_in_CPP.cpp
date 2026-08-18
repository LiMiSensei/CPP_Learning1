//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_19_CLASSES_vs_STRUCTS_in_CPP.h"

struct vec2 {
private:
    float x, y;
public:
    vec2(int x, int y) : x(x), y(y) {
    }
    vec2 operator+(vec2 const &v) {
        return vec2(x + v.x, y + v.y);
    }


};

void _19_CLASSES_vs_STRUCTS_in_CPP::main() {
    //结构体和类的区别 基本上没有区别
    //有一个与可见性相关的小差异
    //也就是那些仅包含若干变量的数据结构
    vec2 vec = vec2(0, 0) + vec2(0, 0);


   

}
