#pragma once
#include "MemoryManager.h"
#include "GameObject.h"
class Scene {
private:
	List<GameObject*>* objects;

public:
	Scene();
	~Scene() {
		MemoryManager::GetInstance().CleanOwner(this);
	};
	
};