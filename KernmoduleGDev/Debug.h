#pragma once
#include <string>
#include "Vector3.h"
class Debug
{
public:
	static void Log(std::string message);
	static void Log(float message);
	static void Log(int message);
	static void Log(Vector3& message);
	static void Log(Vector3* message);
	static void LogWarning(std::string message);
	static void LogError(std::string message);
	static void Log(std::string* message);
	static void LogWarning(std::string* message);
	static void LogError(std::string* message);
private:
	static const std::string currentDateTime();
};

