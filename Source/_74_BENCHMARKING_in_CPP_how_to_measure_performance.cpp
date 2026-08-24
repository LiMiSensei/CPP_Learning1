//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_74_BENCHMARKING_in_CPP_how_to_measure_performance.h"

#include <chrono>
#include <iostream>

namespace _74 {
    struct Timer {
        std::chrono::time_point<std::chrono::system_clock> m_StartTimepoint;


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

void _74_BENCHMARKING_in_CPP_how_to_measure_performance::main() {
    //或者你正在尝试刚学到的新技术 但想比较它与旧方法的性能差异 在C++中该如何实现？
    struct Vector2 {
        float x, y;
    };
    {
        _74::Timer timer;
        int value = 8;

        for (int i = 0; i < 100000; i++) {
            value += 2;
        }
        std::cout << value << std::endl;
    }


    {
        std::array<std::shared_ptr<Vector2> ,1000> shared_ptrs;
        _74::Timer timer;
        for (int i = 0; i < shared_ptrs.size(); i++) {
            shared_ptrs[i] = std::make_shared<Vector2>();
        }
    }

    {
        std::array<std::shared_ptr<Vector2> ,1000> shared_ptrs;
        _74::Timer timer;
        for (int i = 0; i < shared_ptrs.size(); i++) {
            shared_ptrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }
    {
        std::array<std::unique_ptr<Vector2> ,1000> shared_ptrs;
        _74::Timer timer;
        for (int i = 0; i < shared_ptrs.size(); i++) {
            shared_ptrs[i] = std::make_unique<Vector2>();
        }
    }
}
