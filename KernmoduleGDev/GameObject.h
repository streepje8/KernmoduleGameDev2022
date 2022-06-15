#pragma once
#include "CommonIncludes.h"
#include "Component.h"

class GameObject
{
	private:
		List<Component*>* components;
	public:
		template<typename T>
		T* GetComponentFromObject();
		template<typename T>
		List<T*> GetComponents();
		List<Component*>* GetAllComponents() {
			return components;
		}
		Component* AddComponent(Component* c);
		Transform* transform;
		GameObject();
		~GameObject();
};

template <typename T>
T* GameObject::GetComponentFromObject()
{
	for (int i = 0; i < components->count(); i++)
	{
		if (instanceof<T*>(components->get(i)))
		{
			return (T*)components->get(i);
		}
	}
}

template <typename T>
List<T*> GameObject::GetComponents()
{
	List<T*> found = List<T*>();
	for (int i = 0; i < components->count(); i++)
	{
		if (instanceof<T*>(components->get(i)))
		{
			T* component = (T*)components->get(i);
			found.add(component);
		}
	}
	return found;
}

