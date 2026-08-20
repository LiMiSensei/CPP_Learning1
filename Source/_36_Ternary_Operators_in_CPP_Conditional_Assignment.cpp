//
// Created by LiMi on 2026/8/20.
//

#include "../Header/_36_Ternary_Operators_in_CPP_Conditional_Assignment.h"

void _36_Ternary_Operators_in_CPP_Conditional_Assignment::main() {
    //本质上就是if语句的一种简化写法

    int s_Level1 = 1;
    int s_Level2 = 2;

    int s_Speed = s_Level1 < 5 ? s_Level1 : s_Level2;//有返回值优化PVO
}
