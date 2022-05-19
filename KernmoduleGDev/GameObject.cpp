#include "GameObject.h"
#include <typeinfo>
Component* GameObject::AddComponent(Component* c)
{
	//c->gameObject = this;
	//c->transform = transform;
	if (c->stackable) {
		components.add(c);
	}
	else {
		bool canAdd = true;
		for (int i = 0; i < components.count(); i++) {
			if (typeid(components.get(i)).name() == typeid(c).name()) {
				canAdd = false;
			}
		}
		if (canAdd)
			components.add(c);
	}
	return c;
}

GameObject::GameObject()
{
	components = List<Component*>();
	Transform pretrans = Transform();
	Transform* trans = &pretrans;
	AddComponent((Component*)trans);
	transform = trans;

}
