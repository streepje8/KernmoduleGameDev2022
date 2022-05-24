#include "Engine.h"
#include "Stacktracer.h"
#include "MemoryManager.h"
#include "EngineHook.h"
#include "Debug.h"
Engine::Engine() {

}

void Engine::BeginFunction(std::string name, const type_info& origin)
{
	Stacktracer::GetTracer().appendTrace(name, origin);
	MemoryManager::GetInstance().PushFunction();
}

Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;
}

void Engine::EndFunction()
{
	Stacktracer::GetTracer().popTrace();
	MemoryManager::GetInstance().PopFunction();
}
