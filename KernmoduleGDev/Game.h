#pragma once
#include "CommonIncludes.h"
#include "Debug.h"
#include "SceneManager.h"
#include "RenderPipeline.h"

class Game : public MemoryStorable
{
	public:
		std::string name;
		std::string windowTitle;
		bool ExitOnEscape;
		RenderPipeline* renderer;
		virtual void Setup() {};
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void Render() {};
		virtual void Stop() {};
		Game();
		virtual ~Game()
		{
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

