//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_62_Threads_in_CPP.h"

#include <iostream>
#include <ostream>
#include <thread>

namespace _62 {
    static bool s_Finished = false;

    void DoWork() {
        using namespace std::literals::chrono_literals;
        std::cout << "Started thread id="
                << std::this_thread::get_id() << std::endl;
        while (!s_Finished) {
            std::cout << "DoWork()..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }
}

void _62_Threads_in_CPP::main() {
    // 简单来说就是？ 哎呀这个词有点专业
    // 看过这些教程的观众都知道，它们都是采用单线程模式运行的
    // 例如，我们使用了std::cin.get来请求输入
    // 但在等待输入时，我们只能干等着吗？ 要是能同时做点别的就好了
    // 在等待用户输入的过程中 我们希望其他任务能同步进行

    std::thread worker(_62::DoWork);

    std::cin.get();
    _62::s_Finished = true;

    worker.join(); //等待线程执行完成 本质上就是暂停当前线程执行，直到目标线程完成任务

    std::cout << "Finished" << std::endl;
}
