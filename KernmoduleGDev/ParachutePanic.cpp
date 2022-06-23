#include "ParachutePanic.h"
#include "StreepEngine.h"

#include "PlayerController.h"
#include "CoinController.h"

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Parachute Panic";
	this->windowTitle = "Parachute Panic Game";
	Scene* gameScene = NVAR(Scene);

	//Make background
	auto background = OICVAR(GameObject, new GameObject(), gameScene);

	//Add components
	background->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\background.png"));

	//Setup variable values
	background->transform->position = Vector3(0, 0, 0);
	background->transform->scale = Vector3(800.0f/1920.0f, 400.0f/1080.0f, 1);
	gameScene->Instantiate(background);

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

	//Make score display component since the coin requires it
	auto scoredisplay = new ScoreDisplay();

	//Make coin
	auto coin = OICVAR(GameObject, new GameObject(), gameScene);
	
	//Add components
	coin->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\coin.png"));
	coin->AddComponentAndManage(new Rigidbody2D());
	coin->AddComponentAndManage(new CoinController(scoredisplay));
	auto cboxcol = new BoxCollider2D();
	coin->AddComponentAndManage(cboxcol);

	//Setup variable values
	coin->transform->position = Vector3(0, 100, 0);
	coin->transform->scale = Vector3(0.1, 0.1, 1);
	cboxcol->width = 512;
	cboxcol->height = 512;
	coin->GetComponentFromObject<Rigidbody2D>()->useGravity = false;
	gameScene->Instantiate(coin);

	//Make Score display
	auto scoredisp = OICVAR(GameObject, new GameObject(), gameScene);

	//Add components
	auto textRend = new TextRenderer(".\\GameAssets\\fonts\\BebasNeue-Regular.ttf");
	scoredisp->AddComponentAndManage(textRend);
	scoredisp->AddComponentAndManage(scoredisplay);

	//Setup variable values
	scoredisp->transform->position = Vector3(100, 200, 0);
	scoredisp->transform->scale = Vector3(0.25, 0.25, 1);
	textRend->SetText("loading...");
	textRend->fontSize = 200;
	textRend->isUnderlined = true;
	gameScene->Instantiate(scoredisp);

	SceneManager::GetInstance().OpenScene(gameScene);
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}