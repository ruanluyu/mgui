#pragma once

#include <string>

namespace mgui {
	enum LogLevel {
		LOGLV_INFO,
		LOGLV_HINT,
		LOGLV_WARNING,
		LOGLV_ERROR,
	};

	struct Logger
	{
		using log_func = void (*)(std::string, LogLevel);
		log_func log_event;
	};

	extern void SetLogger(const Logger& logger);
	extern void Log(std::string info, LogLevel level);
}
