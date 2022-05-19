#pragma once
#include <exception>
#include <string>
#include "List.h"
#include <stack>
class Stacktracer
{
	private:
		std::stack<std::string> trace;	
		//Stacktracer();
	public:
		static Stacktracer& GetTracer();
		void startTrace();
		std::string stopTrace();
		void appendTrace(std::string name, const type_info& origin);
		void popTrace();
		void printTrace();
		void printException(std::exception e);
};

