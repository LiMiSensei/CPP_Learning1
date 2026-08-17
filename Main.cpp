#include <iostream>
#include <windows.h>

#include "Header/_10_CPP_Header_Files.h"
#include "Header/_11_How_to_DEBUG_CPP_in_VISUAL_STUDIO.h"
#include "Header/_1_Welcome_to_CPP.h"
#include "Header/_2_How_to_Setup_CPP_on_Windows.h"
#include "Header/_3_How_to_Setu_CPP_on_Mac.h"
#include "Header/_4_How_to_Setup_CPP_on_Linux.h"
#include "Header/_5_How_CPP_Works.h"
#include "Header/_6_How_the_CPP_Compiler_Works.h"
#include "Header/_7_How_the_CPP_Linker_Works.h"
#include "Header/_8_Variables_in_CPP.h"
#include "Header/_9_Functions_in_CPP.h"

int main() {

    // 设置控制台代码页为 UTF-8
    //SetConsoleOutputCP(CP_UTF8);
    // 设置区域信息，支持 UTF-8
    //setlocale(LC_ALL, ".UTF-8");
    // 设置本地化，使用系统默认编码（通常是 GBK 中文系统）
    // std::locale::global(std::locale(""));
    // std::wcout.imbue(std::locale());
    if (false) {
        _1_Welcome_to_CPP();
        _2_How_to_Setup_CPP_on_Windows::main();
        _3_How_to_Setu_CPP_on_Mac::main();
        _4_How_to_Setup_CPP_on_Linux::main();
        _5_How_CPP_Works::main();
        _6_How_the_CPP_Compiler_Works::main();
        _7_How_the_CPP_Linker_Works::main();
        _8_Variables_in_CPP::main();
        _9_Functions_in_CPP::main();
        _10_CPP_Header_Files::main();
    }



    _11_How_to_DEBUG_CPP_in_VISUAL_STUDIO::main();


    return 0;
}
