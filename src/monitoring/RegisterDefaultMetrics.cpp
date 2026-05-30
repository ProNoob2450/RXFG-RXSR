#include "monitoring/MonitoringManager.hpp"

namespace rxfg
{
    void RegisterDefaultMetrics()
    {
        MonitoringManager::RegisterMetric({"cpu_usage", "CPU Usage", 0.0, "%"});
        MonitoringManager::RegisterMetric({"gpu_usage", "GPU Usage", 0.0, "%"});
        MonitoringManager::RegisterMetric({"ram_usage", "RAM Usage", 0.0, "MB"});
        MonitoringManager::RegisterMetric({"vram_usage", "VRAM Usage", 0.0, "MB"});
        MonitoringManager::RegisterMetric({"fps_native", "Native FPS", 0.0, "FPS"});
        MonitoringManager::RegisterMetric({"fps_generated", "Generated FPS", 0.0, "FPS"});
        MonitoringManager::RegisterMetric({"frame_latency", "Frame Latency", 0.0, "ms"});
    }
}
