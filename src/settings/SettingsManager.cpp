#include "settings/SettingsManager.hpp"

#include <filesystem>
#include <fstream>

namespace rxfg
{
    std::unordered_map<std::string, std::string> SettingsManager::m_Settings;

    bool SettingsManager::Initialize()
    {
        std::filesystem::create_directories("configs");
        return true;
    }

    bool SettingsManager::Save()
    {
        std::ofstream file("configs/settings.cfg");

        for(const auto& [key, value] : m_Settings)
        {
            file << key << '=' << value << '\n';
        }

        return true;
    }

    void SettingsManager::SetString(const std::string& key, const std::string& value)
    {
        m_Settings[key] = value;
    }

    std::string SettingsManager::GetString(const std::string& key, const std::string& defaultValue)
    {
        auto it = m_Settings.find(key);
        return it != m_Settings.end() ? it->second : defaultValue;
    }

    void SettingsManager::SetBool(const std::string& key, bool value)
    {
        m_Settings[key] = value ? "true" : "false";
    }

    bool SettingsManager::GetBool(const std::string& key, bool defaultValue)
    {
        auto it = m_Settings.find(key);

        if(it == m_Settings.end())
            return defaultValue;

        return it->second == "true";
    }
}
