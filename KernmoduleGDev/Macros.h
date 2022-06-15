#pragma once
#include <memory>
#include "CommonIncludes.h"
#define NVAR(type) (type*)MemoryManager::GetInstance().AllocateOwned<type>(this)->pointer; //Owned new var by this
#define OCVAR(type, instance) (type*)MemoryManager::GetInstance().AllocateOwned(instance, this)->pointer; //Copies an owned instance on to the heap
#define OICVAR(type, instance, owner) (type*)(MemoryManager::GetInstance().AllocateOwned(instance, owner)->pointer); //Copies an instance owned by x to the heap
#define ONVAR(type, owner) (type*)MemoryManager::GetInstance().AllocateOwned<type>(owner)->pointer; //Create owned var on the heap
#define FUNCBEGIN(name) Engine::GetInstance().BeginFunction(#name, typeid(this)); EngineHook h; std::unique_ptr<EngineHook, void(*)(EngineHook*)> functionEndDetector(&h, [](EngineHook* c) { c->OutOfScope(); });