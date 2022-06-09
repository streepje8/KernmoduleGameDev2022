#pragma once
#include "Scene.h"
class SceneManager
{
	private:
		Scene* currentScene;
	public:
		static SceneManager& GetInstance();
		void OpenScene(Scene* scene);
		Scene* GetCurrentScene();
};

