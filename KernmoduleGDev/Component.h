#pragma once
#include "MemoryManager.h"
#include "Transform.h"
#include "Engine.h"

class Component : public MemoryStorable
{
	private:
		
	public:
		bool enabled = true;
		bool stackable = true;
		void* gameObject;
		Transform* transform;

		virtual void Awake() {
		};
		virtual void Start() {
		};
		virtual void Update() {
		};

		virtual void OnCollision() {
		};		
		
		virtual void OnDestroy() {
		};
		virtual void OnApplicationQuit() {
		};

		virtual ~Component()
		{
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

