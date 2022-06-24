#pragma once
#include <memory>
#include "CommonIncludes.h"
#include "GameObject.h"

#define NVAR(type) (type*)MemoryManager::GetInstance().AllocateOwned(new type(),this)->pointer //Owned new var by this
#define OCVAR(type, instance) (type*)MemoryManager::GetInstance().AllocateOwned(instance, this)->pointer //Copies an owned instance on to the heap
#define OICVAR(type, instance, owner) (type*)(MemoryManager::GetInstance().AllocateOwned(instance, owner)->pointer) //Copies an instance owned by x to the heap

#define VAR(type, instance) (type*)((OCVAR(StorableWrapper<type>, new StorableWrapper<type>(instance)))->wrappedobj)

#define GetComponent ((GameObject*)gameObject)->GetComponentFromObject
#define GameOBJ ((GameObject*)gameObject)

#define Time TimeManager::GetInstance()
#define Input InputManager::GetInstance()

#define KeyCode sf::Keyboard::Key

#define FUNCBEGIN(name) Engine::GetInstance().BeginFunction(#name, typeid(this)); EngineHook h; std::unique_ptr<EngineHook, void(*)(EngineHook*)> functionEndDetector(&h, [](EngineHook* c) { c->OutOfScope(); });