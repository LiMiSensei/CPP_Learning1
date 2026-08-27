//
// Created by LiMi on 2026/8/27.
//

#include "../Header/_93_ITERATORS_in_CPP.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

void _93_ITERATORS_in_CPP::main() {
    //今天我们要全面讲解迭代器
    //说白了，迭代器就是用来遍历元素集合的工具
    //你可以自定义++运算符的功能
    //甚至是更复杂的set或map
    //处理像向量这样的简单数据结构时，很容易忘记迭代器
    //迭代器是一种用于遍历元素集合的机制

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < vec.size(); i++) {
        std::cout << "for" << vec[i] << std::endl;
    }
    for (auto i: vec) {
        std::cout << "iter:" << i << std::endl;
    }

    for (std::vector<int>::iterator it = vec.begin();
         it != vec.end(); it++) {
        //
        std::cout << "???:" << *it << std::endl;
    }
    using ScoreMap = std::pmr::unordered_map<std::string, int>;
    using ScoreMapIterator = ScoreMap::const_iterator;
    ScoreMap map;
    map["Cherno"] = 5;
    map["C++"] = 2;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
        auto &key = it->first;
        auto &value = it->second;

        std::cout << "key:" << key << " value:" << value << std::endl;
    }

    for (auto kv : map) {
        std::cout << "key:" << kv.first << " value:" << kv.second << std::endl;
    }

    for (auto[key, value] : map) {}
}
