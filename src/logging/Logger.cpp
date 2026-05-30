#include "logging/Logger.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>

namespace
{
    std::mutex g_LogMutex;
    std::ofstream g_LogFile;
}

namespace rxfg
{
    void Logger::Initialize()
    {
        std::filesystem::create_directories("logs");
        g_LogFile.open("logs/rxfg.log", std::ios::app);
    }

    void Logger::Trace(const std::string& message) { Write(LogLevel::Trace, message); }
    void Logger::Info(const std::string& message) { Write(LogLevel::Info, message); }
    void Logger::Warning(const std::string& message) { Write(LogLevel::Warning, message); }
    void Logger::Error(const std::string& message) { Write(LogLevel::Error, message); }
    void Logger::Critical(const std::string& message) { Write(LogLevel::Critical, message); }

    void Logger::Write(LogLevel level, const std::string& message)
    {
        std::lock_guard<std::mutex> lock(g_LogMutex);

        const char* levelString = "INFO";

        switch(level)
        {
            case LogLevel::Trace: levelString = "TRACE"; break;
            case LogLevel::Info: levelString = "INFO"; break;
            case LogLevel::Warning: levelString = "WARN"; break;
            case LogLevel::Error: levelString = "ERROR"; break;
            case LogLevel::Critical: levelString = "CRITICAL"; break;
        }

        std::string output = std::string("[") + levelString + "] " + message;

        std::cout << output << std::endl;

        if(g_LogFile.is_open())
        {
            g_LogFile << output << std::endl;
            g_LogFile.flush();
        }
    }
}
