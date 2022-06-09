#include "Scene.h"

Scene::Scene()
{
	objects = (List<GameObject*>*)MemoryManager::GetInstance().AllocateOwned(List<GameObject*>(), this)->pointer;
}

void Scene::Instantiate(GameObject* go)
{
	objects->add(go);
}

void Scene::Destroy(GameObject* go)
{
	if (objects->contains(go)) {
		objects->remove(go);
	}
}

List<GameObject*>* Scene::GetObjects()
{
	return objects;
}
