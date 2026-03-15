#include <Logger.hpp>




static void Logger::DEBUG(const std::string& message) {
	std::cout << "[DEBUG] " << message << std::endl;
}

static void Logger::INFO(const std::string& message) {
	std::cout << "[INFO] " << message << std::endl;
}

static void Logger::ERROR(const std::string& message) {
	std::cerr << "[ERROR] " << message << std::endl;
}

static void Logger::WARNING(const std::string& message) {
	std::cerr << "[WARNING] " << message << std::endl;
}