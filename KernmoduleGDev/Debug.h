#pragma once
#include <string>
class Debug
{
public:
	static void Log(std::string message);
	static void LogWarning(std::string message);
	static void LogError(std::string message);
	static void Log(std::string* message);
	static void LogWarning(std::string* message);
	static void LogError(std::string* message);
private:
	static const std::string currentDateTime();
};

