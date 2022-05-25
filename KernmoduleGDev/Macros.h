#pragma once
#include <memory>
#include <typeinfo>
#include "Engine.h"
#include "EngineHook.h"
#define FUNCBEGIN(name) Engine::GetInstance().BeginFunction(#name, typeid(this)); EngineHook h; std::unique_ptr<EngineHook, void(*)(EngineHook*)> functionEndDetector(&h, [](EngineHook* c) { c->OutOfScope(); });