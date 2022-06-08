#include "Scene.h"

Scene::Scene()
{
	objects = (List<GameObject*>*)MemoryManager::GetInstance().AllocateOwned(List<GameObject*>(), this).pointer;
}
