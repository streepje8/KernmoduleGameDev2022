#pragma once
#include "List.h"
#include "MemoryManager.h"
#include <string>
#include "RenderPipeline.h"
class Game
{
	public:
		std::string name;
		std::string windowTitle;
		bool ExitOnEscape;
		RenderPipeline renderer;
		virtual void Setup() {};
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void Render() {};
		virtual void Stop() {};
		Game();
		~Game() {
			MemoryManager::GetInstance().CleanOwner(this);
		}
};

