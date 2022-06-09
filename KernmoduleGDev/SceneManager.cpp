#include "SceneManager.h"

SceneManager& SceneManager::GetInstance()
{
	static SceneManager instance;
	return instance;
}

void SceneManager::OpenScene(Scene* scene)
{
	currentScene = scene;
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}
