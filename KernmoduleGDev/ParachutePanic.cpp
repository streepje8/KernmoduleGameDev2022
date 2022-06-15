#include "ParachutePanic.h"
#include "PlayerController.h"
#include "StreepEngine.h"

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Parachute Panic";
	this->windowTitle = "Parachute Panic Game";
	Scene* gameScene = NVAR(Scene);
	auto player = ONVAR(GameObject, gameScene);
	player->AddComponent((ShapeRenderer*)MemoryManager::GetInstance().AllocateOwned(new ShapeRenderer(ShapeRenderer::ShapeType::TRIANGLE, Vector3(100, 100, 5)), player)->pointer);
	player->AddComponent((PlayerController*)MemoryManager::GetInstance().AllocateOwned(new PlayerController(), player)->pointer);
	gameScene->Instantiate(player);
	SceneManager::GetInstance().OpenScene(gameScene);
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}