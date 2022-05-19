#pragma once
#include "List.h"
#include "MemoryManager.h"
class Game
{
	public:
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void Render() {};
		virtual void Stop() {};
		~Game() {
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

