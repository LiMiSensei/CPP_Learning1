//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_65_Sorting_in_CPP.h"

#include <algorithm>
#include <iostream>
#include <vector>

void _65_Sorting_in_CPP::main() {
    //今天我们就来深入讲解C++中的排序算法
    //我希望按数值大小或特定谓词条件来排序
    //怎样用C++实现自动排序？比如std：：vector时，完全无需自行实现排序算法
    //直接使用标准库的排序功能更高效 因此今天我们将重点讲解std：：sort

    std::vector<int> values = {1, 3, 4, 5, 7, 9};
    //std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a > b;
    });

    for (auto i: values) {
        std::cout << i << std::endl;
    }

    std::cin.get();
}
