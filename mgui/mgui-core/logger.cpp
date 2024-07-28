#include "pch.h"
#include "logger.h"

namespace mgui {
	
	Logger global_logger = Logger{nullptr};
	
	void SetLogger(const Logger& logger)
	{
		global_logger = logger;
	}

	void Log(std::string info, LogLevel level)
	{
		if (!global_logger.log_event) return;
		global_logger.log_event(info, level);
	}
}