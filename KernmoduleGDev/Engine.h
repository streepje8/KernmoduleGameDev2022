#pragma once
#include "CommonIncludes.h"

class Engine
{
	public:
		static Engine& GetInstance();
		Engine();
		void BeginFunction(std::string name, const type_info& origin);
		void EndFunction();
};

