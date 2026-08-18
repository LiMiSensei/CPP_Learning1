//
// Created by LiMi on 2026/8/19.
//

#include "../Header/_20_How_to_Write_a_CPP_Class.h"

#include <iostream>

class Log {
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo;
public:
    void SetLevel(int LogLevel) {
        m_LogLevel = LogLevel;
    }
    void Warn(const char * msg) {
        if (m_LogLevel >= LogLevelWarning) {
            std::cout <<"[WARNING:]" << msg << std::endl;
        }

    }
    void Error(const char * msg) {
        if (m_LogLevel >= LogLevelError) {
            std::cout <<"[ErrorING:]" << msg << std::endl;
        }

    }
    void Info(const char * msg) {
        if (m_LogLevel >= LogLevelInfo) {
            std::cout <<"[InfoING:]" << msg << std::endl;
        }

    }
};

void _20_How_to_Write_a_CPP_Class::main() {
    //日志类用于管理日志消息
    //因为控制台就像是应用程序的信息集散中心

    Log log;
    log.SetLevel(log.LogLevelError);
    log.Warn("Hello World");
    log.Info("Hello World");
    log.Error("Hello World");
    std::cin.get();
}
