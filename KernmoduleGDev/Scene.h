#pragma once
#include "GameObject.h"
#include "CommonIncludes.h"

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