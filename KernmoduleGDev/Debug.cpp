#include "Debug.h"
#include <iostream>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 

void Debug::Log(std::string message)
{
    Debug::Log(&message);
}

void Debug::Log(float message)
{
    Debug::Log(std::to_string(message));
}

void Debug::Log(int message)
{
    Debug::Log(std::to_string(message));
}

void Debug::Log(Vector3& message)
{
    Debug::Log(message.to_string());
}

void Debug::Log(Vector3* message)
{
    Debug::Log(message->to_string());
}

void Debug::LogWarning(std::string message)
{
    Debug::LogWarning(&message);
}

void Debug::LogError(std::string message)
{
    Debug::LogError(&message);
}

void Debug::Log(std::string* message)
{
    std::cout << "[INFO/" << Debug::currentDateTime() << "] " << message->c_str() << std::endl;
}

void Debug::LogWarning(std::string* message)
{
    std::cout << "[WARN/" << Debug::currentDateTime() << "] " << message->c_str() << std::endl;
}

void Debug::LogError(std::string* message)
{
    std::cout << "[ERROR/" << Debug::currentDateTime() << "] " << message->c_str() << std::endl;
}

const std::string Debug::currentDateTime() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    std::string s = "";
    s.append(std::to_string(newtime.tm_hour));
	s.append(":");
	s.append(std::to_string(newtime.tm_min));
	s.append(":");
	s.append(std::to_string(newtime.tm_sec));
    return s;
}