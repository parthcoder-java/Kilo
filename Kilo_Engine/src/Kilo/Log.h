#pragma once

#include<memory>
#include"Core.h"
#include<spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include<spdlog/fmt/ostr.h> 

namespace Kilo {
	class KILO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Logging Macros
#define KL_CORE_TRACE(...)    ::Kilo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KL_CORE_INFO(...)     ::Kilo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KL_CORE_WARN(...)     ::Kilo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KL_CORE_ERROR(...)    ::Kilo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KL_CORE_FATAL(...)    ::Kilo::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Logging Macros
#define KL_TRACE(...)         ::Kilo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KL_INFO(...)          ::Kilo::Log::GetClientLogger()->info(__VA_ARGS__)
#define KL_WARN(...)          ::Kilo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KL_ERROR(...)         ::Kilo::Log::GetClientLogger()->error(__VA_ARGS__)
#define KL_FATAL(...)         ::Kilo::Log::GetClientLogger()->critical(__VA_ARGS__)