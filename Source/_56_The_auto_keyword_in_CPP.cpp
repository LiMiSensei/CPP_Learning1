//
// Created by LiMi on 2026/8/23.
//

#include "../Header/_56_The_auto_keyword_in_CPP.h"

#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>


std::string GetName() {
    return "_";
}

std::string GetName1() {
    return "_";
}

namespace _56 {
    class Device {
    };

    class DeviceManages {
    private:
        std::unordered_map<std::string, std::vector<Device *> > m_Device;

    public:
        const std::unordered_map<std::string, std::vector<Device *> >& GetDevice() const {
            return m_Device;
        }
    };
}

void _56_The_auto_keyword_in_CPP::main() {
    //传统指针操作等复杂语法。但其实我们有个更简便的方法
    //我们只需输入auto加上变量名，系统就会自动推断类型
    int a = 10;
    auto b = a;
    auto c = 10L;
    //这种情况下C++ 会表现出弱类型语言的特征


    auto d = GetName();
    //这是由于它被赋值为getName函数的返回值y·而该函数返回的就是字符串类型

    std::string d1 = GetName1(); //自动将char* 转为 string

    std::vector<std::string> strings;
    strings.push_back("Hello");
    strings.push_back("Apple");
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it) {
        std::cout << *it << std::endl;
        //实际上迭代器用得不多，这种场景下更推荐使用foreach循环或范围for循环
    }

    //=====================================
    using DeviceMap = std::unordered_map<std::string, std::vector<_56::Device *> >;
    typedef std::unordered_map<std::string, std::vector<_56::Device *> > DeviceMap;

    _56::DeviceManages dm;
    const DeviceMap& device = dm.GetDevice();

    std::cin.get();
}
