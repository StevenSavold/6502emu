#include "Logging.h"
#include <spd/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init() 
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = spdlog::stdout_color_mt("6502");
    s_CoreLogger->set_level(stdlog::level::trace);

    s_ClientLogger = spdlog::std_color_mt("Peripheral");
    s_ClientLogger->set_level(spdlog::level::trace);
}