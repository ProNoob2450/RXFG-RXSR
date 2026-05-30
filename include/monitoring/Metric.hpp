#pragma once

#include <string>

namespace rxfg
{
    struct Metric
    {
        std::string id;
        std::string name;
        double value = 0.0;
        std::string unit;
    };
}
