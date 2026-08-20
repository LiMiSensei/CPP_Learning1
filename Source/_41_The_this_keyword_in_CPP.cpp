//
// Created by LiMi on 2026/8/21.
//

#include "../Header/_41_The_this_keyword_in_CPP.h"

namespace _41 {
    class Entity {
    public:
        int x, y;

        Entity(int x) {
            Entity* const & e = this;
            (*this).x = x;
            this->x = x;
        }
    };
}

void _41_The_this_keyword_in_CPP::main() {
    //C++中的this关键字。这个术语说起来有点拗口
    //this实际上个指针指向当前的对象实例
}
