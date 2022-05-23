#pragma once
#include <string>
#include "Enginehook.h"
class Engine
{
	public:
		static Engine& GetInstance();
		Engine();
		void BeginFunction(std::string name, const type_info& origin, EngineHook hook);
		void EndFunction();
};

