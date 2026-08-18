//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_12_CONDITIONS_and_BRANCHES_in_CPP_if_statements.h"

#include <iostream>
#include <ostream>

void _12_CONDITIONS_and_BRANCHES_in_CPP_if_statements::main() {
    //CPU会根据条件跳转到不同的机器指令段执行
    //当程序遇到分支条件时转到内存的指定位置继续执行
    int x = 5;
    bool comparisonResult = x == 5;
    if (comparisonResult) {
        std::cout << "Comparison Result" << std::endl;
    }
    if (1) {
        std::cout << "1" << std::endl;
    }

    const char *ptr = nullptr;
    if (ptr == nullptr) {
        std::cout << "ptr == nullptr" << std::endl;
    } else if (ptr == "Hell0") {
        std::cout << "ptr == Hell0" << std::endl;
    } else {
        std::cout << "ptr != nullptr" << std::endl;
    }
}
