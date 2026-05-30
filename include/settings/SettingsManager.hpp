#pragma once

#include <string>
#include <unordered_map>

namespace rxfg
{
    class SettingsManager
    {
    public:
        static bool Initialize();
        static bool Save();

        static void SetString(const std::string& key, const std::string& value);
        static std::string GetString(const std::string& key, const std::string& defaultValue = "");

        static void SetBool(const std::string& key, bool value);
        static bool GetBool(const std::string& key, bool defaultValue = false);

    private:
        static std::unordered_map<std::string, std::string> m_Settings;
    };
}
