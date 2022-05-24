#pragma once
#include <memory>
#define FUNCBEGIN(name) Engine::GetInstance().BeginFunction(#name, typeid(this)); EngineHook h; std::unique_ptr<EngineHook, void(*)(EngineHook*)> functionEndDetector(&h, [](EngineHook* c) { c->OutOfScope(); });