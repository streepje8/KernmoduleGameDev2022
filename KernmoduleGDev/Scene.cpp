#include "Scene.h"

Scene::Scene()
{
	objects = OCVAR(List<GameObject*>, new List<GameObject*>());
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
