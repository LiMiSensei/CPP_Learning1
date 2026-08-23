//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_63_Timing_in_CPP.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace _63 {
    void Function() {
        for (int i = 0; i < 100; i++) {
            std::cout << "Hello World\n";// << std::endl;//会消耗三分之一
        }
    }

    struct Timer {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        std::chrono::duration<float> duration;

        Timer() {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer() {
            end = std::chrono::high_resolution_clock::now();
            duration = (end - start);
            std::cout << duration.count() * 1000.0f <<"ms"<< std::endl;
        }
    };
}

void _63_Timing_in_CPP::main() {
#define time std::chrono::high_resolution_clock::now()
    using namespace std::literals::chrono_literals;
    // 那么，我们该如何测量完成某项操作或执行特定任务所需的时间？
    //std::chrono::time_point<std::chrono::system_clock> start = time;
    {
        _63::Timer timer;
        _63::Function();
        //std::this_thread::sleep_for(1s);
    }
    //std::chrono::duration<float> end = time - start;
    //std::cout << end << std::endl;
}
