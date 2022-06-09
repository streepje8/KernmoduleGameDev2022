#include "GameObject.h"
#include <typeinfo>
#include "MemoryManager.h"
Component* GameObject::AddComponent(Component* c)
{
	c->gameObject = this;
	c->transform = transform;
	if (c->stackable) {
		components->add(c);
	}
	else {
		bool canAdd = true;
		for (int i = 0; i < components->count(); i++) {
			if (typeid(components->get(i)).name() == typeid(c).name()) {
				canAdd = false;
			}
		}
		if (canAdd)
			components->add(c);
	}
	return c;
}

GameObject::GameObject()
{
	components = (List<Component*>*)MemoryManager::GetInstance().AllocateOwned(List<Component*>(), this)->pointer;
	transform = (Transform*)MemoryManager::GetInstance().AllocateOwned(Transform(), this)->pointer;
}

GameObject::~GameObject()
{
	MemoryManager::GetInstance().CleanOwner(this);
}
