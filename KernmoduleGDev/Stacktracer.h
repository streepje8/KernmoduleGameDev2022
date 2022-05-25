#pragma once
#include <exception>
#include <string>
#include "List.h"
#include <stack>
class Stacktracer
{
	private:
		std::stack<std::string> trace;	
		std::stack<std::string> backuptrace;
		std::string what(const std::exception_ptr& eptr);
		//Stacktracer();
	public:
		static Stacktracer& GetTracer();
		void startTrace();
		std::string stopTrace();
		void appendTrace(std::string name, const type_info& origin);
		void popTrace();
		void printTrace(bool backup = false);
		void printException(std::exception e);
		void printException(std::exception_ptr e);
};

