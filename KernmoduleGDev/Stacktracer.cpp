#include "Stacktracer.h"
#include <iostream>

Stacktracer& Stacktracer::GetTracer()
{
	static Stacktracer instance;
	return instance;
}

void Stacktracer::startTrace()
{
	trace = std::stack<std::string>();
}

std::string Stacktracer::stopTrace()
{
	std::string result = "";
	for(int i = 0; i < trace.size(); i++) {
		result.append(trace.top());
		trace.pop();
		result.append("\n");
	}
	return result;
}

void Stacktracer::appendTrace(std::string name, const type_info& origin)
{
	std::string currentTrace = "at: ";
	currentTrace.append(origin.name());
	currentTrace.append("::");
	currentTrace.append(name);
	trace.push(currentTrace);
}

void Stacktracer::printTrace() 
{
	std::stack<std::string> copyboi = std::stack<std::string>(trace);
	for (int i = 0; i < copyboi.size(); i++) {
		std::cout << copyboi.top() << std::endl;
		copyboi.pop();
	}
}

void Stacktracer::popTrace() {
	trace.pop();
}

void Stacktracer::printException(std::exception e)
{
	std::cout << "Exception: " << e.what() << std::endl;
	printTrace();
}
