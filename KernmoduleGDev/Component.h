#pragma once
#include "MemoryManager.h"
#include "Engine.h"
#include "EngineHook.h"
#include <typeinfo>
class Component
{
	private:
		
	public:
		bool enabled = true;
		bool stackable = true;
		virtual void Awake() {
			EngineHook hook;
			Engine::GetInstance().BeginFunction("Awake", typeid(this),hook);
		};
		virtual void Start() {
			EngineHook hook;
			Engine::GetInstance().BeginFunction("Start", typeid(this), hook);
		};
		virtual void Update() {
			EngineHook hook;
			Engine::GetInstance().BeginFunction("Update", typeid(this), hook);
		};
		virtual void OnDestroy() {
			EngineHook hook;
			Engine::GetInstance().BeginFunction("OnDestroy", typeid(this), hook);
		};
		virtual void OnApplicationQuit() {
			EngineHook hook;
			Engine::GetInstance().BeginFunction("OnApplicationQuit", typeid(this), hook);
		};
		//GameObject gameObject;
		//Transform* transform;
		~Component() {
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

