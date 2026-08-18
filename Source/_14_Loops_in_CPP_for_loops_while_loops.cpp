//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_14_Loops_in_CPP_for_loops_while_loops.h"

#include <iostream>
#include <ostream>

void _14_Loops_in_CPP_for_loops_while_loops::main() {
    //用于需要重复执行某些操作的场景
    for (int i = 0; i < 5; ++i) {
        std::cout << i << std::endl;
    }

    //另外一种写法
    int j = 0;
    bool run = true;
    for (; run;) {
        std::cout << j << std::endl;
        j++;
        if (!(j < 5)) run = false;
    }
    //另外的写法
    int k = 0;
    for (;;) {
        std::cout << k << std::endl;
        k++;
        if (!(k < 5)) break;
    }
    std::cout << "over" << std::endl;

    int x = 0;
    while (x < 5) {
        std::cout << "while: " << x << std::endl;
        x++;
    }

    // do while
    do {
        std::cout << "while: " << x << std::endl;
    } while (x < 5);
}
