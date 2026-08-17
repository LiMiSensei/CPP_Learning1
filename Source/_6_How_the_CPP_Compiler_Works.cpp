//
// Created by LiMi on 2026/8/18.
//

#include "../Header/_6_How_the_CPP_Compiler_Works.h"

int Mulity(int a, int b) {
    return a * b;
}
void _6_How_the_CPP_Compiler_Works::main() {
    // 编译 -》 链接
    // 代码预处理-》词法分析-》语法解析 （语法抽象树）
    // 编译过程还会生成各种辅助数据，比如专门放常量的内存空间

    //预处理生成文件：
    //#include 粘贴复制代码
    //#define 替换代码
    //#if 是否参与编译

    //仅汇编列表.asm
    // 预处理 比如常量折叠 5* 2
    // ？函数签名通过函数签名找到函数
}