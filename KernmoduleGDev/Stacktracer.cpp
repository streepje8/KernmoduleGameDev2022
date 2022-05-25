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
	/*
	if ((trace.size() < backuptrace.size() - 2) && (backuptrace.size() > 0)) {
		backuptrace.pop();
	}
	*/
	std::string currentTrace = "at: ";
	currentTrace.append(origin.name());
	currentTrace.append("::");
	currentTrace.append(name);
	trace.push(currentTrace);
	backuptrace = std::stack<std::string>(trace);
	/*
	if (trace.size() == backuptrace.size()) {
		backuptrace.pop();
		backuptrace.push(trace.top());
	}
	if (backuptrace.size() < trace.size()) {
		backuptrace.push(trace.top());
	}
	*/
}

void Stacktracer::printTrace(bool backup) 
{
	std::stack<std::string> copyboi = std::stack<std::string>(backup ? backuptrace : trace);
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
	printTrace(true);
}

void Stacktracer::printException(std::exception_ptr e)
{
	std::cout << "Exception occured: " << what(e) << std::endl;
	printTrace(true);
}

std::string Stacktracer::what(const std::exception_ptr& eptr = std::current_exception())
{
	if (!eptr) { throw std::bad_exception(); }

	try { std::rethrow_exception(eptr); }
	catch (const std::exception& e) { return e.what(); }
	catch (const std::string& e) { return e; }
	catch (const char* e) { return e; }
	catch (...) { return "who knows"; }
}