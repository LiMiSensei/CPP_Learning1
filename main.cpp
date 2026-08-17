#include <iostream>

#include "Header/_1_Welcome_to_CPP.h"
#include "Header/_2_How_to_Setup_CPP_on_Windows.h"
#include "Header/_3_How_to_Setu_CPP_on_Mac.h"
#include "Header/_4_How_to_Setup_CPP_on_Linux.h"
#include "Header/_5_How_CPP_Works.h"

int main() {
    if (false) {
        _1_Welcome_to_CPP();
        _2_How_to_Setup_CPP_on_Windows::main();
        _3_How_to_Setu_CPP_on_Mac::main();
        _4_How_to_Setup_CPP_on_Linux::main();
    }
    _5_How_CPP_Works::main();



    return 0;
}
