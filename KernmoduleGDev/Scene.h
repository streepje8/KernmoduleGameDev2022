#pragma once
#include "MemoryManager.h"
#include "GameObject.h"
class Scene {
private:
	List<GameObject*>* objects;

public:
	Scene();
	void Instantiate(GameObject* go);
	void Destroy(GameObject* go);
	List<GameObject*>* GetObjects();
	~Scene() {
		MemoryManager::GetInstance().CleanOwner(this);
	};
	
};