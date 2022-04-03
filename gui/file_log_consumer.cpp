/*#include "file_log_consumer.h"

gui::FileLogConsumer::FileLogConsumer(const std::string& filePath) :
	fileStream_(filePath)
{
	if (!fileStream_.is_open()) {
		throw std::logic_error("Can not open file!");
	}
}

void gui::FileLogConsumer::logMessage(structures::LogType type, const std::string& message) {
	fileStream_ << structures::logTypeToString(type) << ";" << message << std::endl;
}

void gui::FileLogConsumer::logDuration(size_t size, std::chrono::milliseconds duration, const std::string& message) {
	fileStream_ << size << ";" << duration.count() << ";" << message << std::endl;
}*/