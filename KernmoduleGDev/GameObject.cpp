#include "GameObject.h"
#include <typeinfo>
#include "MemoryManager.h"
Component* GameObject::AddComponentAndManage(Component* c)
{
	this->AddComponent((Component*)MemoryManager::GetInstance().AllocateOwned(c,this)->pointer);
	return c;
}
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
	components = OCVAR(List<Component*>,new List<Component*>());
	transform = OCVAR(Transform,new Transform());
}
