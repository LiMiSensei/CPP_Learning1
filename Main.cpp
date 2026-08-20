#include <iostream>
#include <windows.h>

#include "Header/_10_CPP_Header_Files.h"
#include "Header/_11_How_to_DEBUG_CPP_in_VISUAL_STUDIO.h"
#include "Header/_12_CONDITIONS_and_BRANCHES_in_CPP_if_statements.h"
#include "Header/_13_BEST_Visual_Studio_Setup_for_CPP_Projects.h"
#include "Header/_14_Loops_in_CPP_for_loops_while_loops.h"
#include "Header/_15_Control_Flow_in_CPP_continue_break_return.h"
#include "Header/_16_POINTERS_in_CPP.h"
#include "Header/_17_REFERENCES_in_CPP.h"
#include "Header/_18_CLASSES_in_CPP.h"
#include "Header/_19_CLASSES_vs_STRUCTS_in_CPP.h"
#include "Header/_1_Welcome_to_CPP.h"
#include "Header/_20_How_to_Write_a_CPP_Class.h"
#include "Header/_21_Static_in_CPP.h"
#include "Header/_22_Static_for_Classes_and_Structs_in_CPP.h"
#include "Header/_24_Constructors_in_CPP.h"
#include "Header/_25_Destructors_in_CPP.h"
#include "Header/_26_Inheritance_in_CPP.h"
#include "Header/_27_Virtual_Functions_in_CPP.h"
#include "Header/_28_Interfaces_in_CPP_Pure_Virtual_Functions.h"
#include "Header/_2_How_to_Setup_CPP_on_Windows.h"
#include "Header/_30_Arrays_in_CPP.h"
#include "Header/_31_How_Strings_Work_in_CPP_and_ho_to_use_them.h"
#include "Header/_32_String_Literals_in_CPP.h"
#include "Header/_33_CONST_in_CPP.h"
#include "Header/_34_The_Mutable_Keyword_in_CPP.h"
#include "Header/_35_Member_Initializer_Lists_in_CPP_Constructor_Initializer_List.h"
#include "Header/_37_How_to_CREATE_INSTANTIATE_OBJECTS_in_CPP.h"
#include "Header/_3_How_to_Setu_CPP_on_Mac.h"
#include "Header/_40_OPERATORS_and_OPERATOR_OVERLOADING_in_CPP.h"
#include "Header/_42_Object_Lifetime_in_CPP_Stack_Scope_Lifetimes.h"
#include "Header/_43_SMART_POINTERS_in_CPP_std_unique_ptr_std_shared_ptr_std_weak_ptr.h"
#include "Header/_44_Copying_and_Copy_Constructors_in_CPP.h"
#include "Header/_4_How_to_Setup_CPP_on_Linux.h"
#include "Header/_5_How_CPP_Works.h"
#include "Header/_6_How_the_CPP_Compiler_Works.h"
#include "Header/_7_How_the_CPP_Linker_Works.h"
#include "Header/_8_Variables_in_CPP.h"
#include "Header/_9_Functions_in_CPP.h"

int main() {
    // 设置控制台代码页为 UTF-8
    SetConsoleOutputCP(CP_UTF8);
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
        _11_How_to_DEBUG_CPP_in_VISUAL_STUDIO::main();
        _12_CONDITIONS_and_BRANCHES_in_CPP_if_statements::main();
        _13_BEST_Visual_Studio_Setup_for_CPP_Projects::main();
        _14_Loops_in_CPP_for_loops_while_loops::main();
        _15_Control_Flow_in_CPP_continue_break_return::main();
        _16_POINTERS_in_CPP::main();
        _17_REFERENCES_in_CPP::main();
        _18_CLASSES_in_CPP::main();
        _19_CLASSES_vs_STRUCTS_in_CPP::main();
        _20_How_to_Write_a_CPP_Class::main();
        _21_Static_in_CPP::main();
        _22_Static_for_Classes_and_Structs_in_CPP::main();
        _24_Constructors_in_CPP::main();
        _25_Destructors_in_CPP::main();
        _26_Inheritance_in_CPP::main();
        _27_Virtual_Functions_in_CPP::main();
        _28_Interfaces_in_CPP_Pure_Virtual_Functions::main();
        _30_Arrays_in_CPP::main();
        _31_How_Strings_Work_in_CPP_and_ho_to_use_them::main();
        _32_String_Literals_in_CPP::main();
        _33_CONST_in_CPP::main();
        _34_The_Mutable_Keyword_in_CPP::main();
        _35_Member_Initializer_Lists_in_CPP_Constructor_Initializer_List::main();
        _37_How_to_CREATE_INSTANTIATE_OBJECTS_in_CPP::main();
        _40_OPERATORS_and_OPERATOR_OVERLOADING_in_CPP::main();
        _42_Object_Lifetime_in_CPP_Stack_Scope_Lifetimes::main();
        _43_SMART_POINTERS_in_CPP_std_unique_ptr_std_shared_ptr_std_weak_ptr::main();
    }


    _44_Copying_and_Copy_Constructors_in_CPP::main();


    return 0;
}
