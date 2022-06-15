#pragma once
#include "CommonIncludes.h"
#include "Engine.h"

class Component
{
	private:
		
	public:
		bool enabled = true;
		bool stackable = true;
		void* gameObject;
		Transform* transform;
		template<typename T>
		T* GetComponent()
		{
			return gameObject->GetComponentFromObject();
		};
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
		
		~Component() {
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

