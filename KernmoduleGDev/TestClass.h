#pragma once
#include <string>
#include "MemoryManager.h"
class TestClass
{
	public:
		std::string* test;
		static TestClass& GetInstance();
};


