cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Source/_1_Welcome_to_CPP.cpp
        Header/_1_Welcome_to_CPP.h
        Source/_2_How_to_Setup_CPP_on_Windows.cpp
        Header/_2_How_to_Setup_CPP_on_Windows.h
        Source/_3_How_to_Setu_CPP_on_Mac.cpp
        Header/_3_How_to_Setu_CPP_on_Mac.h
        Source/_4_How_to_Setup_CPP_on_Linux.cpp
        Header/_4_How_to_Setup_CPP_on_Linux.h
        Source/_5_How_CPP_Works.cpp
        Header/_5_How_CPP_Works.h)
