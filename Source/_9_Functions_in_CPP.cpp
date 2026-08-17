//
// Created by LiMi on 2026/8/18.
//

#include "../Header/_9_Functions_in_CPP.h"

#include <iostream>
#include <ostream>

int Multiply(int a, int b) {
    return a * b;
}

void _9_Functions_in_CPP::main() {
    //函数：特指不属于类的独立功能
    const int result = Multiply(5, 6);
    std::cout << result << std::endl;
    {
        const int result = Multiply(9, 10);
        std::cout << result << std::endl;
    }
    {
        const int result = Multiply(2, 12);
        std::cout << result << std::endl;
    }




    std::cin.get();
}
