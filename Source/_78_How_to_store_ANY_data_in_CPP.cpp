//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_78_How_to_store_ANY_data_in_CPP.h"

#include <any>
#include <string>

void _78_How_to_store_ANY_data_in_CPP::main() {
    //今天我们要深入探讨在C++中用单一变量存储各种数据类型的神奇操作。
    //现在我们来到最后，终于可以宣布：通过std：any我们能存储任意类型数据啦！

    std::any data;
    data = 2;
    data = "Hello";
    data = std::string("World");
    //正因如此，对于大多数应用场景，std::variant其实比std:any更靠谱

    std::string s = std::any_cast<std::string>(data);
    //Variant就是一个类型安全的联合体，它会把所有数据都存在一个联合体里。
    //。不了解这个概念的话，右上角有讲解联合体的视频可以看

}
