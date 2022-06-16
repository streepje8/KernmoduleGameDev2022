#pragma once
#include "Debug.h"
class MemoryStorable
{
	public:
		virtual ~MemoryStorable() {} //Having a destructor prevents a debug assertion fail
};