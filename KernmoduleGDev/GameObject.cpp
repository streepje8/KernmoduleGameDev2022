#include "GameObject.h"
#include <typeinfo>
void GameObject::AddComponent(Component c)
{
	c.gameObject = this;
	c.transform = transform;
	if (c.stackable) {
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
}

GameObject::GameObject()
{
	transform = Transform();

}
