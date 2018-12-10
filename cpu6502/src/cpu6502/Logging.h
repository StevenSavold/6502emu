#include <spdlog/spdlog.h>
#include "Core.h"


class _6502_API Log {
private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreInstance() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientInstance() { return s_ClientLogger; }

};

#define _6502_LOG_TRACE(...) ::Log::GetCoreInstance( )->trace(__VA_ARGS__)
#define _6502_LOG_INFO(...)  ::Log::GetCoreInstance( )->info(__VA_ARGS__)
#define _6502_LOG_WARN(...)  ::Log::GetCoreInstance( )->warn(__VA_ARGS__)
#define _6502_LOG_ERROR(...) ::Log::GetCoreInstance( )->error(__VA_ARGS__)
#define _6502_LOG_FATAL(...) ::Log::GetCoreInstance( )->critical(__VA_ARGS__)

#define PERIPHERAL_LOG_TRACE(...) ::Log::GetClientInstance( )->trace(__VA_ARGS__)
#define PERIPHERAL_LOG_INFO(...)  ::Log::GetClientInstance( )->info(__VA_ARGS__)
#define PERIPHERAL_LOG_WARN(...)  ::Log::GetClientInstance( )->warn(__VA_ARGS__)
#define PERIPHERAL_LOG_ERROR(...) ::Log::GetClientInstance( )->error(__VA_ARGS__)
#define PERIPHERAL_LOG_FATAL(...) ::Log::GetClientInstance( )->critical(__VA_ARGS__)
