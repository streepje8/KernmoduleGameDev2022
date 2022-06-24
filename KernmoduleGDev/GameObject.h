#pragma once
#include "List.h"
#include "Transform.h"
#include "MemoryManager.h"
#include "MemoryStorable.h"
#include "Component.h"
#include <string>

class GameObject : public MemoryStorable
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
		Component* AddComponentAndManage(Component* c);
		Component* AddComponent(Component* c);
		Transform* transform;
		std::string name;
		GameObject();
		virtual ~GameObject()
		{
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

template <typename T>
T* GameObject::GetComponentFromObject()
{
	for (int i = 0; i < components->count(); i++)
	{
		T* componentpointer = dynamic_cast<T*>(components->get(i));
		if(componentpointer != nullptr)
			return componentpointer;
	}
	return nullptr;
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

