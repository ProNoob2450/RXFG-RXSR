#include "core/EventBus.hpp"

namespace rxfg
{
    std::unordered_map<std::string, std::vector<EventBus::Callback>> EventBus::m_Events;

    void EventBus::Subscribe(const std::string& eventName, Callback callback)
    {
        m_Events[eventName].push_back(callback);
    }

    void EventBus::Emit(const std::string& eventName)
    {
        auto it = m_Events.find(eventName);

        if(it == m_Events.end())
            return;

        for(auto& callback : it->second)
        {
            callback();
        }
    }
}
