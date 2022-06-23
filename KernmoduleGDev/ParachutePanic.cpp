#include "ParachutePanic.h"
#include "StreepEngine.h"

#include "PlayerController.h"
#include "CoinController.h"

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Cashbot";
	this->windowTitle = "Cashbot - Become the richest robot in the world!";
	Debug::Log("\n   _____           _____ _    _ ____   ____ _______ \n"
"  / ____|   /\\    / ____| |  | |  _ \\ / __ \\__   __|\n"
" | |       /  \\  | (___ | |__| | |_) | |  | | | |   \n"
" | |      / /\\ \\  \\___ \\|  __  |  _ <| |  | | | |   \n"
" | |____ / ____ \\ ____) | |  | | |_) | |__| | | |   \n"
"  \\_____/_/    \\_\\_____/|_|  |_|____/ \\____/  |_|   \n"
"                                                   ");
	Debug::Log("=====================================================================================");
	Debug::Log("Cashbot, build on top of sfml. All other code is written by streepje8 (aka wessel)");
	Debug::Log("All art was kindly provided by hierisluuk (aka luuk), my friend");
	Debug::Log("The font was taken from Google fonts and uses an Open font license.");
	Debug::Log("=====================================================================================");
	CreateAndOpenGameScene();
	inGame = true;
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);
}

void ParachutePanic::Update()
{
	if (inGame) {
		if (scoreDisplay->lives < 1) {
			Debug::Log("[o-o] <(Ah man! Better luck next time!)");
			CreateAndOpenLossScene();
			inGame = false;
		}
		if (scoreDisplay->coinsCollected > 19) {
			Debug::Log("[^_^] <(This is the best day of my life!)");
			CreateAndOpenWinScene();
			inGame = false;
		}
	}
}

void ParachutePanic::Stop()
{
	Debug::Log("See you next time!");
}

void ParachutePanic::CreateAndOpenLossScene() {
	Scene* lossScene = NVAR(Scene);

	//Make win text
	auto losstxt = OICVAR(GameObject, new GameObject(), lossScene);

	//Add components
	auto textRend = new TextRenderer(".\\GameAssets\\fonts\\BebasNeue-Regular.ttf");
	losstxt->AddComponentAndManage(textRend);

	//Setup variable values
	losstxt->transform->position = Vector3(45, 30, 0);
	losstxt->transform->scale = Vector3(0.25, 0.25, 1);
	textRend->SetText("You Lost!");
	textRend->SetColor(sf::Color(255, 0, 0, 255));
	textRend->fontSize = 400;
	textRend->isBold = true;
	lossScene->Instantiate(losstxt);

	SceneManager::GetInstance().OpenScene(lossScene);
}

void ParachutePanic::CreateAndOpenWinScene() {
	Scene* winScene = NVAR(Scene);

	//Make win text
	auto wintxt = OICVAR(GameObject, new GameObject(), winScene);

	//Add components
	auto textRend = new TextRenderer(".\\GameAssets\\fonts\\BebasNeue-Regular.ttf");
	wintxt->AddComponentAndManage(textRend);

	//Setup variable values
	wintxt->transform->position = Vector3(45, 30, 0);
	wintxt->transform->scale = Vector3(0.25, 0.25, 1);
	textRend->SetText("You won!");
	textRend->SetColor(sf::Color(0,255,0,255));
	textRend->fontSize = 400;
	textRend->isBold = true;
	winScene->Instantiate(wintxt);

	SceneManager::GetInstance().OpenScene(winScene);
}


void ParachutePanic::CreateAndOpenGameScene() {
	Scene* gameScene = NVAR(Scene);

	//Make background
	auto background = OICVAR(GameObject, new GameObject(), gameScene);

	//Add components
	background->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\background.png"));

	//Setup variable values
	background->transform->position = Vector3(0, 0, 0);
	background->transform->scale = Vector3(800.0f / 1920.0f, 400.0f / 1080.0f, 1);
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
	player->transform->scale = Vector3(0.4, 0.4, 1);
	boxcol->width = 149;
	boxcol->height = 215;
	player->GetComponentFromObject<Rigidbody2D>()->useGravity = false;
	gameScene->Instantiate(player);

	//Make score display component since the coin requires it
	scoreDisplay = new ScoreDisplay();

	//Make coin
	auto coin = OICVAR(GameObject, new GameObject(), gameScene);

	//Add components
	coin->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\coin.png"));
	coin->AddComponentAndManage(new Rigidbody2D());
	coin->AddComponentAndManage(new CoinController(scoreDisplay));
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
	scoredisp->AddComponentAndManage(scoreDisplay);

	//Setup variable values
	scoredisp->transform->position = Vector3(100, 200, 0);
	scoredisp->transform->scale = Vector3(0.25, 0.25, 1);
	textRend->SetText("loading...");
	textRend->fontSize = 200;
	textRend->isUnderlined = true;
	gameScene->Instantiate(scoredisp);

	SceneManager::GetInstance().OpenScene(gameScene);
}
