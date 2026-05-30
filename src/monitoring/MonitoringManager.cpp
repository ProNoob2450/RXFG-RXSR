#include "monitoring/MonitoringManager.hpp"

namespace rxfg
{
    std::unordered_map<std::string, Metric> MonitoringManager::m_Metrics;

    void MonitoringManager::RegisterMetric(const Metric& metric)
    {
        m_Metrics[metric.id] = metric;
    }

    void MonitoringManager::UpdateMetric(const std::string& id, double value)
    {
        auto it = m_Metrics.find(id);

        if(it != m_Metrics.end())
        {
            it->second.value = value;
        }
    }

    std::vector<Metric> MonitoringManager::GetSnapshot()
    {
        std::vector<Metric> snapshot;

        for(const auto& [id, metric] : m_Metrics)
        {
            snapshot.push_back(metric);
        }

        return snapshot;
    }
}
