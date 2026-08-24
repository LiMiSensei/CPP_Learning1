//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_75_STRUCTURED_BINDINGS_in_CPP.h"

#include <string>
#include <tuple>

namespace _75 {

}

std::tuple<std::string,int> CreatePerson() {
    return {"",1};
}
std::tuple<std::string,int> CreatePerson1() {
    return {"",1};
}
void _75_STRUCTURED_BINDINGS_in_CPP::main() {
    //今天我们要全面讲解C++中的结构化绑定特性 这是C++17版本独有的新特性
    auto person = CreatePerson();
    auto& name = std::get<0>(person);
    auto age = std::get<1>(person);


    auto [name1, age1] = CreatePerson1();


    std::tuple<std::string , int> person1 = CreatePerson();
}
