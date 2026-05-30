#include "logging/Logger.hpp"

int main()
{
    rxfg::Logger::Initialize();
    rxfg::Logger::Info("RXFG-RXSR starting up");

    return 0;
}
