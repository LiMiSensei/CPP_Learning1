//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_15_Control_Flow_in_CPP_continue_break_return.h"

#include <iostream>
#include <ostream>

void _15_Control_Flow_in_CPP_continue_break_return::main() {
    for (int i = 0; i < 10; i++) {
        if (i%2 == 0)continue;
        std::cout << i << std::endl;
    }
}
