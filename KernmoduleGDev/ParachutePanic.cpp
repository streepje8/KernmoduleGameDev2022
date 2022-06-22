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

	//Add components
	player->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\player.png"));
	player->AddComponentAndManage(new Rigidbody2D());
	auto boxcol = new BoxCollider2D();
	player->AddComponentAndManage(new PlayerController());
	player->AddComponentAndManage(boxcol);

	//Setup variable values
	player->transform->position = Vector3(0, -160, 0);
	player->transform->scale = Vector3(0.4,0.4,1);
	boxcol->width = 149;
	boxcol->height = 215;
	player->GetComponentFromObject<Rigidbody2D>()->useGravity = false;
	gameScene->Instantiate(player);

	//Make enemy
	auto enemy = OICVAR(GameObject, new GameObject(), gameScene);
	
	//Add components
	enemy->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\enemy.png"));
	enemy->AddComponentAndManage(new Rigidbody2D());
	auto eboxcol = new BoxCollider2D();
	enemy->AddComponentAndManage(eboxcol);

	//Setup variable values
	enemy->transform->position = Vector3(0, 100, 0);
	enemy->transform->scale = Vector3(0.3, 0.3, 1);
	eboxcol->width = 10;
	eboxcol->height = 10;
	enemy->GetComponentFromObject<Rigidbody2D>()->mass = 20;
	gameScene->Instantiate(enemy);

	SceneManager::GetInstance().OpenScene(gameScene);
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}