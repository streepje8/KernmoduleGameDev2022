#include "BuildInRenderer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "List.h"
#include <SFML/Graphics.hpp>
#include "CommonUtil.h"
#include "Renderer.h"

void BuildInRenderer::Render(sf::RenderWindow* win)
{
	Scene* toRender = SceneManager::GetInstance().GetCurrentScene();
	List<GameObject*>* objects = toRender->GetObjects();
	for (int i = 0; i < objects->count(); i++) {
		GameObject* object = objects->get(i);
		List<Component*>* components = object->GetAllComponents();
		for (int j = 0; j < components->count(); j++) {
			Component* component = components->get(j);
			if (instanceof<Renderer>(component)) {
				Renderer* renderer = (Renderer*)component;
				renderer->Render(win);
			}
		}
	}
}
