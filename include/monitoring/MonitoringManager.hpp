#pragma once

#include "monitoring/Metric.hpp"

#include <unordered_map>
#include <vector>

namespace rxfg
{
    class MonitoringManager
    {
    public:
        static void RegisterMetric(const Metric& metric);
        static void UpdateMetric(const std::string& id, double value);
        static std::vector<Metric> GetSnapshot();

    private:
        static std::unordered_map<std::string, Metric> m_Metrics;
    };
}
