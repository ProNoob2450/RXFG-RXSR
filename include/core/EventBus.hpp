#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace rxfg
{
    class EventBus
    {
    public:
        using Callback = std::function<void()>;

        static void Subscribe(const std::string& eventName, Callback callback);
        static void Emit(const std::string& eventName);

    private:
        static std::unordered_map<std::string, std::vector<Callback>> m_Events;
    };
}
