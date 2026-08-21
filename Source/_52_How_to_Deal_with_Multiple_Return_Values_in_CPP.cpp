//
// Created by LiMi on 2026/8/22.
//

#include "../Header/_52_How_to_Deal_with_Multiple_Return_Values_in_CPP.h"

#include <string>
#include <tuple>

void _52_How_to_Deal_with_Multiple_Return_Values_in_CPP::main() {
    //我们来聊聊什么是tuple（元组）
    //特别是同类型的多变量返回时 我们会返回一个向量或者数组之类的东西
    std::tuple<std::string, std::string> tuplr;
    std::get<0>(tuplr);
}
