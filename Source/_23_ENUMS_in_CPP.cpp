//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_23_ENUMS_in_CPP.h"

#include <iostream>

enum Example : unsigned char {
    A = 0, B = 2, C = 6
};

class Log {
public:
    enum Level {
        Error =0, Warning, Info
    };

private:
    int m_LogLevel = Level::Info;
public:
    void setLogLevel(Level logLevel) {
        m_LogLevel = logLevel;
    }
};

void _23_ENUMS_in_CPP::main() {
    //枚举不过是整型的马甲
    Example value = Example::A;

    //int value = B;

    if (value == Example::A) {
    }

    Log log;
    log.setLogLevel(Log::Level::Error);
    log.setLogLevel(Log::Level::Warning);
    std::cin.get();
}
