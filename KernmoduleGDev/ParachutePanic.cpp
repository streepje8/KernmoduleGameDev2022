#include "ParachutePanic.h"
#include "Debug.h"
#include "Macros.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Math.h"
#include "SceneManager.h"
#include "ShapeRenderer.h"

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Parachute Panic";
	this->windowTitle = "Parachute Panic Game";
	Scene* gameScene = NVAR(Scene);
	auto player = ONVAR(GameObject, gameScene);
	player->AddComponent((ShapeRenderer*)MemoryManager::GetInstance().AllocateOwned(ShapeRenderer(ShapeRenderer::ShapeType::TRIANGLE, Vector3(100, 5, 5)), player)->pointer);
	gameScene->Instantiate(player);
	SceneManager::GetInstance().OpenScene(gameScene);
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}