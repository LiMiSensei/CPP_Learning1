//
// Created by LiMi on 2026/8/25.
//

#include "_81_VISUAL_BENCHMARKING_in_CPP_how_to_measure_performance_visually.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include <ostream>


namespace std::chrono::_V2 {
    struct system_clock;
}

namespace _81 {
    struct Timer {
        std::chrono::time_point<std::chrono::_V2::system_clock> m_StartTimepoint;


        Timer() {
            m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }


        ~Timer() {
            Stop();
        }

        void Stop() {
            auto endTimepoint = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch();
            auto duration = end - start;
            double ms = duration.count() * 0.001;

            std::cout << duration << "(";
            std::cout << ms << "ms)\n";
        }
    };
}

void Function1() {
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello World" << "\n";
    }
}

void Function2() {
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello World" << std::sqrt(i) << "\n";
    }
}

void _81_VISUAL_BENCHMARKING_in_CPP_how_to_measure_performance_visually::main() {
    {
        _81::Timer timer;
        Function1();
        Function2();
    }
    //Chrome Tracing
}
