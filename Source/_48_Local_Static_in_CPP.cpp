//
// Created by LiMi on 2026/8/22.
//

#include "../Header/_48_Local_Static_in_CPP.h"

#include <iostream>
#include <ostream>

namespace _48 {
    //如果加上static修饰符，就相于当直接把变量声明提到外层作用域
    static int i = 0;

    void Function() {
        i++;
        std::cout << i << std::endl;
    }

    class Singleton {
    private:
        static Singleton* s_Instance;

    public:
        static Singleton& Get() {
            return *s_Instance;
        }

        void Hello() {
        }
    };
}

void _48_Local_Static_in_CPP::main() {
    //生命周期指的是该变量实际存在的时间长度
    _48::Function();
    _48::i = 10;
    _48::Function();
    _48::Function();
    _48::Function();
}
