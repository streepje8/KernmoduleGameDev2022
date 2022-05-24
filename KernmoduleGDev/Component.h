#pragma once
#include "MemoryManager.h"
#include "Engine.h"
#include "EngineHook.h"
#include <typeinfo>
#include "Macros.h"
class Component
{
	private:
		
	public:
		bool enabled = true;
		bool stackable = true;
		virtual void Awake() {
			FUNCBEGIN(Awake);
		};
		virtual void Start() {
			FUNCBEGIN(Start);
		};
		virtual void Update() {
			FUNCBEGIN(Update);
		};
		virtual void OnDestroy() {
			FUNCBEGIN(OnDestroy);
		};
		virtual void OnApplicationQuit() {
			FUNCBEGIN(OnApplicationQuit);
		};
		//GameObject gameObject;
		//Transform* transform;
		~Component() {
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

