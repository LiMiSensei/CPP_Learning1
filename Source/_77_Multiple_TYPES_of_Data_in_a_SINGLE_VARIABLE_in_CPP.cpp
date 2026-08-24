//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_77_Multiple_TYPES_of_Data_in_a_SINGLE_VARIABLE_in_CPP.h"

#include <iostream>
#include <string>
#include <variant>

enum class ErrorCode {
    None = 0,
    NotFound = 1,
    NoAccess = 2,
};

std::variant<std::string, int> ReadFileAsString() {
    return {};
}

void _77_Multiple_TYPES_of_Data_in_a_SINGLE_VARIABLE_in_CPP::main() {
    //那么在C++17中怎么实现多类型数据存储呢？
    //答案就是标准库提供的std：:variant
    //我认为它和std::optional有异曲同工之妙
    //std:：variant可以让你预先定义所有可能的类型

    std::variant<std::string, int> data;
    std::cout << "sizeof:" << sizeof(data) << std::endl;
    data = "LiMi";
    std::cout << std::get<std::string>(data) << "\n";

    if (auto value = std::get_if<std::string>(&data)) {
        std::string& v = *value;
    }

    data = 2;
    std::cout << std::get<int>(data) << "\n";
}
