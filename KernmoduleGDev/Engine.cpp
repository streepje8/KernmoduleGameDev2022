#include "Engine.h"
#include "Stacktracer.h"
#include "MemoryManager.h"
#include <memory>
#include "EngineHook.h"
Engine::Engine() {

}

void Engine::BeginFunction(std::string name, const type_info& origin,EngineHook hook)
{
	std::unique_ptr<EngineHook, void(*)(EngineHook*)> functionEndDetector(&hook, [](EngineHook* c) { c->OutOfScope(); });
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
