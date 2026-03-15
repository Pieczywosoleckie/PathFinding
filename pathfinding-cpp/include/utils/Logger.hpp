#pragma once

#include <iostream>

class Logger {
public:
	static void DEBUG(const std::string& message);
	static void INFO(const std::string& message);
	static void ERROR(const std::string& message);
	static void WARNING(const std::string& message);
};