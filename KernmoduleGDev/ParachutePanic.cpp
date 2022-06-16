#include "ParachutePanic.h"
#include "PlayerController.h"
#include "StreepEngine.h"

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Parachute Panic";
	this->windowTitle = "Parachute Panic Game";
	Scene* gameScene = NVAR(Scene);

	//Make player
	auto player = OICVAR(GameObject, new GameObject(), gameScene);
	player->AddComponentAndManage(new SpriteRenderer("C:\\Users\\streepmsi\\Desktop\\DESKTOP_OLD\\Dogsmile.png")); //new ShapeRenderer(ShapeRenderer::ShapeType::TRIANGLE, Vector3(100, 100, 5))
	player->AddComponentAndManage(new PlayerController());
	auto boxcol = new BoxCollider2D();
	boxcol->width = 10;
	boxcol->height = 10;
	player->AddComponentAndManage(boxcol);
	gameScene->Instantiate(player);

	//Make enemy
	auto enemy = OICVAR(GameObject, new GameObject(), gameScene);
	enemy->transform->position = Vector3(200, 200, 0);
	enemy->AddComponentAndManage(new SpriteRenderer("C:\\Users\\streepmsi\\Desktop\\DESKTOP_OLD\\Dogsmile.png")); //new ShapeRenderer(ShapeRenderer::ShapeType::TRIANGLE, Vector3(100, 100, 5))
	auto eboxcol = new BoxCollider2D();
	eboxcol->width = 10;
	eboxcol->height = 10;
	enemy->AddComponentAndManage(eboxcol);
	gameScene->Instantiate(enemy);

	SceneManager::GetInstance().OpenScene(gameScene);
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}