#include "EngineHook.h"
#include "Engine.h"

void EngineHook::OutOfScope()
{
	Engine::GetInstance().EndFunction();
}
