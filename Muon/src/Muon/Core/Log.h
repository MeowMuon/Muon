#pragma once

#include "Core.h"

#include <memory>
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Muon
{
	class MUON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

	template<typename T>
	inline auto format_as(const T& obj) { return obj.ToString(); }

}

//Core logging macros
#define MU_CORE_LOG_TEMP(...) Muon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MU_CORE_LOG_INFO(...) Muon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MU_CORE_LOG_WARN(...) Muon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MU_CORE_LOG_ERROR(...) Muon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MU_CORE_LOG_FATAL(...) Muon::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client logging macros
#define MU_LOG_TEMP(...) Muon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MU_LOG_INFO(...) Muon::Log::GetClientLogger()->info(__VA_ARGS__)
#define MU_LOG_WARN(...) Muon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MU_LOG_ERROR(...) Muon::Log::GetClientLogger()->error(__VA_ARGS__)
#define MU_LOG_FATAL(...) Muon::Log::GetClientLogger()->critical(__VA_ARGS__)

//MU_LOG
#define MU_LOG_CORE(TYPE, ...) MU_CORE_##TYPE(__VA_ARGS__)
#define MU_LOG(TYPE, ...) MU_##TYPE(__VA_ARGS__)
