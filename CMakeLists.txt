cmake_minimum_required(VERSION 4.3)
project(learningDemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(learningDemo main.cpp
        Source/_1_Welcome_to_CPP.cpp
        Header/_1_Welcome_to_CPP.h
        Source/_2_How_to_Setup_CPP_on_Windows.cpp
        Header/_2_How_to_Setup_CPP_on_Windows.h
        Source/_3_How_to_Setu_CPP_on_Mac.cpp
        Header/_3_How_to_Setu_CPP_on_Mac.h
        Source/_4_How_to_Setup_CPP_on_Linux.cpp
        Header/_4_How_to_Setup_CPP_on_Linux.h
        Source/_5_How_CPP_Works.cpp
        Header/_5_How_CPP_Works.h
        Source/_6_How_the_CPP_Compiler_Works.cpp
        Header/_6_How_the_CPP_Compiler_Works.h
        Source/_7_How_the_CPP_Linker_Works.cpp
        Header/_7_How_the_CPP_Linker_Works.h
        Source/_8_Variables_in_CPP.cpp
        Header/_8_Variables_in_CPP.h
        Source/_9_Functions_in_CPP.cpp
        Header/_9_Functions_in_CPP.h
        Source/_10_CPP_Header_Files.cpp
        Header/_10_CPP_Header_Files.h
        Source/_11_How_to_DEBUG_CPP_in_VISUAL_STUDIO.cpp
        Header/_11_How_to_DEBUG_CPP_in_VISUAL_STUDIO.h)
