#include "Scene.h"

Scene::Scene()
{
	objects = OCVAR(List<GameObject*>, new List<GameObject*>());
}

void Scene::Instantiate(GameObject* go)
{
	objects->add(go);
	List<Component*>* components = go->GetAllComponents();
	for (int j = 0; j < components->count(); j++) {
		components->get(j)->Start();
	}
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
