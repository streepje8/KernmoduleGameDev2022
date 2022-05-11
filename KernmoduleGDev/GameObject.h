#pragma once
#include "Component.h"
#include "List.h"
#include "Transform.h"
class GameObject
{
private:
	List<Component> components = List<Component>();
public:
	template<typename T>
	T GetComponent();
	template<typename T>
	List<T> GetComponents();
	void AddComponent(Component c);
	Transform transform;
	GameObject();
};

template <typename T>
T GameObject::GetComponent<T>()
{
	for (int i = 0; i < components.count(); i++)
	{
		if (typeid(components[i]).name() == typeid(T).name())
		{
			return (T)components[i];
		}
	}
}

template <typename T>
List<T> GameObject::GetComponents<T>()
{
	List<T> components = List<T>();
	for (int i = 0; i < components.count(); i++)
	{
		if (typeid(components[i]).name() == typeid(T).name())
		{
			components.add(components[i]);
		}
	}
	return components;
}

