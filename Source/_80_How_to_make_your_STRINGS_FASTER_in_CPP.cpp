//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_80_How_to_make_your_STRINGS_FASTER_in_CPP.h"

#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
static uint32_t s_AllocCount = 0;


#if 0
void PritName(const std::string& name) {
    std::cout << name << std::endl;
}

#else
void PritName(std::string_view name) {
    std::cout << name << std::endl;
}
#endif
void _80_How_to_make_your_STRINGS_FASTER_in_CPP::main() {
    //关键问题在于它们会动态分配内存
    //如果各位不太清楚为什么内存分配会影响性能

    std::string name = "Yan Chernikov";

#if 0
    std::string firstName = name.substr(0, 3);
    std::string lastName = name.substr(4, 9);

#else
    std::string_view firstName = name.substr(0, 3);
    std::string_view lastName = name.substr(4, 9);
#endif

    PritName(firstName);
    PritName(lastName);
    std::cout << s_AllocCount << " allocations" << std::endl;
    std::cin.get();
}
