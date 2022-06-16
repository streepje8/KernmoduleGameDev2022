#pragma once
#include "GameObject.h"
#include "CommonIncludes.h"
#include "Debug.h"

class Scene : public MemoryStorable {
private:
	List<GameObject*>* objects;

public:
	Scene();
	void Instantiate(GameObject* go);
	void Destroy(GameObject* go);
	List<GameObject*>* GetObjects();	
};