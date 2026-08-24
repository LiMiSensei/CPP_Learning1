//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_76_How_to_Deal_with_OPTIONAL_Data_in_CPP.h"

#include <fstream>
#include <iostream>
#include <optional>
#include <string>

namespace _76 {
}

std::string ReadFileAsString(const std::string& filepath, bool& outSuccess) {
    std::ifstream stream(filepath);
    if (stream) {
        //read file
        stream.close();
        std::string result;
        outSuccess = true;
        return result;
    }
    outSuccess = false;
    return std::string();
}

std::optional<std::string> ReadFileAsString1(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        //read file
        std::string result;
        stream.close();
        return result;
    }
    return {};
}

void _76_How_to_Deal_with_OPTIONAL_Data_in_CPP::main() {
    //当数据可能存在也可能不存在时的情况
    //或者数据缺失。这时std：:optional就派上用场了
    bool outSuccess;
    std::string data = ReadFileAsString("./Test.txt", outSuccess);

    std::optional<std::string> data1 = ReadFileAsString1("Test.txt");
    std::string value = data1.value_or("Not present");
    std::optional<int> count;
    int c = count.value_or(100);
    std::cout << c << std::endl;
    if (data1.has_value()) {
        std::cout << "The data is: " << data1.value() << std::endl;
    } else {
        std::cout << "File could not be opened!: " << std::endl;
    }
}
