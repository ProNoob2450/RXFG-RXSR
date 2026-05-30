#pragma once

#include <string>

namespace rxfg
{
    enum class LogLevel
    {
        Trace,
        Info,
        Warning,
        Error,
        Critical
    };

    class Logger
    {
    public:
        static void Initialize();

        static void Trace(const std::string& message);
        static void Info(const std::string& message);
        static void Warning(const std::string& message);
        static void Error(const std::string& message);
        static void Critical(const std::string& message);

    private:
        static void Write(LogLevel level, const std::string& message);
    };
}
