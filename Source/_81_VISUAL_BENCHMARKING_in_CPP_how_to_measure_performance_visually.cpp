//
// Created by LiMi on 2026/8/25.
//

#include "../Header/_81_VISUAL_BENCHMARKING_in_CPP_how_to_measure_performance_visually.h"

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <thread>


namespace std::chrono::_V2 {
    struct system_clock;
}

namespace _81 {
#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) _81::InstrumentationTimer timer##__LINE__(name)
#ifdef _MSC_VER
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_FUNCTION() PROFILE_SCOPE(__PRETTY_FUNCTION__)
#endif
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif


    struct ProfileResult {
        std::string Name;
        long long Start, End;
        uint64_t ThreadID;
    };

    class Instrumentor {
    private:
        std::string m_SessionName;
        std::ofstream m_OutputStream;
        int m_ProfileCount;
        std::mutex m_Lock;
        bool m_ActiveSession;

    public:
        ~Instrumentor() {
            EndSession();
        }

        Instrumentor(const Instrumentor&) = delete;

        static void BeginSession(const std::string& name, const std::string& filepath = "Results.json") {
            GetInstance().BeginSessionImpl(name, filepath);
        }

        static void EndSession() {
            GetInstance().EndSessionImpl();
        }

        static void WriteProfile(const ProfileResult& result) {
            GetInstance().WriteProfileImlp(result);
        }

    private:
        Instrumentor()
            : m_SessionName("None"), m_ProfileCount(0), m_ActiveSession(false) {
            ;
        }

        static Instrumentor& GetInstance() {
            static Instrumentor instance;
            return instance;
        }

        void BeginSessionImpl(const std::string& name, const std::string& filepath = "Results.json") {
            if (m_ActiveSession) {
                EndSession();
            }
            m_ActiveSession = true;
            m_SessionName = name;

            m_OutputStream.open(m_SessionName + std::string("_") + filepath);
            WriteHeader();
        }

        void EndSessionImpl() {
            if (!m_ActiveSession) {
                return;
            }
            m_ActiveSession = false;
            m_ProfileCount = 0;

            WriteFooter();
            m_OutputStream.close();
        }

        void WriteHeader() {
            m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
            m_OutputStream.flush();
        }

        void WriteFooter() {
            m_OutputStream << "]}";
            m_OutputStream.flush();
        }

        void WriteProfileImlp(const ProfileResult& result) {
            std::lock_guard<std::mutex> lockGuard(m_Lock);

            if (m_ProfileCount++ > 0)
                m_OutputStream << ",";

            std::string name = result.Name;
            std::replace(name.begin(), name.end(), '"', '\'');

            m_OutputStream << "{";
            m_OutputStream << "\"cat\":\"function\",";
            m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
            m_OutputStream << "\"name\":\"" << name << "\",";
            m_OutputStream << "\"ph\":\"X\",";
            m_OutputStream << "\"pid\":\"" << m_SessionName << "\",";
            m_OutputStream << "\"tid\":" << result.ThreadID << ",";
            m_OutputStream << "\"ts\":" << result.Start;
            m_OutputStream << "}";

            m_OutputStream.flush();
        }
    };

    class InstrumentationTimer {
    private:
        const char* m_Name;

        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
        bool m_Stopped;

    public:
        explicit InstrumentationTimer(const char* name)
            : m_Name(name), m_Stopped(false) {
            m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        ~InstrumentationTimer() {
            if (!m_Stopped) {
                Stop();
            }
        }

        void Stop() {
            auto endTimepoint = std::chrono::high_resolution_clock::now();

            long long start = std::chrono::time_point_cast<std::chrono::microseconds>(
                m_StartTimepoint).time_since_epoch().count();
            long long end = std::chrono::time_point_cast<std::chrono::microseconds>(
                endTimepoint).time_since_epoch().count();

            uint64_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
            Instrumentor::WriteProfile({m_Name, start, end, threadID});

            m_Stopped = true;
        }
    };

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
//================================================================================
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

int Fibonacci(int x) {
    std::string name = std::string("Fibonacci ") + std::to_string(x);
    PROFILE_SCOPE(name.c_str());

    std::this_thread::sleep_for(std::chrono::microseconds(1)); // Compensate statistical temporal precision problem

    if (x < 3) return 1;
    int part1 = Fibonacci(x - 1);
    int part2 = Fibonacci(x - 2);
    return part1 + part2;
}

void RunBenchmarks() {
    PROFILE_FUNCTION();

    std::cout << "Running Benchmarks..." << std::endl;
    std::thread t1([]() { Fibonacci(9); });
    std::thread t2([]() { Fibonacci(10); });

    t1.join();
    t2.join();
}



void _81_VISUAL_BENCHMARKING_in_CPP_how_to_measure_performance_visually::main() {
    {
        _81::Instrumentor::BeginSession("Benchmark");
        RunBenchmarks();
        //_81::Timer timer;
        //Function1();
        //Function2();
    }
    //Chrome Tracing
}
