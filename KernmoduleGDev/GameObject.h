#pragma once
#include "Component.h"
#include "List.h"
#include "Transform.h"
class GameObject
{
	private:
		List<Component*> components;
	public:
		template<typename T>
		T* GetComponent();
		template<typename T>
		List<T*> GetComponents();
		Component* AddComponent(Component* c);
		Transform* transform;
		GameObject();
};

template <typename T>
T* GameObject::GetComponent()
{
	for (int i = 0; i < components.count(); i++)
	{
		if (typeid(components[i]).name() == typeid(T).name())
		{
			return (T*)components[i];
		}
	}
}

template <typename T>
List<T*> GameObject::GetComponents()
{
	List<T*> components = List<T*>();
	for (int i = 0; i < components.count(); i++)
	{
		if (typeid(components[i]).name() == typeid(T).name())
		{
			components.add((T*)components[i]);
		}
	}
	return components;
}

