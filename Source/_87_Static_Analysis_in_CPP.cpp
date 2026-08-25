//
// Created by LiMi on 2026/8/26.
//

#include "../Header/_87_Static_Analysis_in_CPP.h"

#include <cstdint>
#include <cstring>

namespace _87 {
    struct Entity {
    };

    Entity* LoadEntity() {
        return nullptr;
    }
}

void _87_Static_Analysis_in_CPP::main() {
    //今天我们要全面讲解C++中的静态分析技术
    // 这项技术能有效提升代码质量 这时候就需要静态分析工具出马了，它能帮你检查源代码，揪出潜在问题
    // 你仍然会借助拼写和语法检查工具 或是语意不通的句子都会被自动标注
    // 那何不借助这个贴心小工具，让它帮你把关检查，确保万无一失呢？
    // 那给编程语言配个类似的纠错小助手！不也是理所当然的吗？
    // 特别是当你对这门语言还不够驾轻就熟的时候，更何况是C++这种硬骨头
    // 这类似于代码审查，只不过审查者不是人，而是自动化工具
    // 今天我们要重点介绍PBSStudio，他们还特别赞助了本期视频
    const char* string = "Hello";
    char* strBuffer = new char[strlen(string) + 1];
    memcpy(strBuffer, string, strlen(string) + 1);

    uint32_t width = 800, height = 600;
    uint32_t* buffer = new uint32_t[width * height];
    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            buffer[x + y * width] = 0;
        }
    }
}
