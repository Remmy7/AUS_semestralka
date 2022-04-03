/*#pragma once

#include "../structures/_logger/logger.h"

namespace gui
{
	class FileLogConsumer
		: public structures::ILogConsumer
	{
	public:
		FileLogConsumer(const std::string& filePath);
		void logMessage(structures::LogType type, const std::string& message);
		void logDuration(size_t size, std::chrono::milliseconds duration, const std::string& message);
	};
}*/