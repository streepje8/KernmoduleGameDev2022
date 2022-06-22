#pragma once
#include <string>
#include <typeinfo>

class Engine
{
	public:
		static Engine& GetInstance();
		Engine();
		void BeginFunction(std::string name, const type_info& origin);
		void EndFunction();
};

