#include "CoinController.h"


void CoinController::Start()
{
	rb = GetComponent<Rigidbody2D>();
	col = GetComponent<BoxCollider2D>();
}

void CoinController::Update()
{
	transform->rotation = transform->rotation * Quaternion::Euler(0,0,5 * Time.deltaTime); //spin the coin 0-0

	timer += Time.deltaTime;
	if (timer > 1) {
		timer = 0;
		direction = Math::Rand(-2, 2);
	}

	rb->AddForce(Vector3(direction * 30.0f,-fallSpeed, 0) * Time.deltaTime);
	if (transform->position.y < -410) {
		transform->position = Vector3(Math::Rand(-380, 380), 450, 0);
		transform->rotation = Quaternion::Euler(0, 0, 0);
		SpawnCoin();
		Debug::Log("[x-x] <(Ouch, i missed one!)");
		if (!(Math::RountToInt(Math::Rand(0, 10)) == 5)) { //have a 1 in 10 chance of not destroying the object
			SceneManager::GetInstance().GetCurrentScene()->Destroy(GameOBJ);
		}
		sdp->lives--;
	}
	Vector3 newPos = transform->position + (*(rb->velocity) * Time.deltaTime * rb->pixelsPerMetre);
	if (newPos.x >= 380 || newPos.x <= -380) {
		direction *= -1;
	}
}

void CoinController::OnCollision()
{
	//Old code just recycles the active code, new code has to spawn a new one for the assignment
	if (col->lastCollidedWith->name == "player") {
		transform->position = Vector3(Math::Rand(-380, 380), 450, 0);
		transform->rotation = Quaternion::Euler(0, 0, 0);
		SpawnCoin();
		sdp->coinsCollected++;
		Debug::Log("$$$ [0-0] <(Cha ching!)");
		if (!(Math::RountToInt(Math::Rand(0, 10)) == 5)) { //have a 1 in 10 chance of not destroying the object
			SceneManager::GetInstance().GetCurrentScene()->Destroy(GameOBJ);
		}
	}
}

void CoinController::SpawnCoin() {
	Scene* gameScene = SceneManager::GetInstance().GetCurrentScene();
	//Make coin
	auto coin = OICVAR(GameObject, new GameObject(), gameScene);
	coin->name = "coin";

	//Add components
	coin->AddComponentAndManage(new SpriteRenderer(".\\GameAssets\\sprites\\coin.png"));
	coin->AddComponentAndManage(new Rigidbody2D());
	coin->AddComponentAndManage(new CoinController(sdp));
	auto cboxcol = new BoxCollider2D();
	coin->AddComponentAndManage(cboxcol);

	//Setup variable values
	coin->transform->position = Vector3(Math::Rand(-380, 380), 420, 0);
	coin->transform->scale = Vector3(0.1, 0.1, 1);
	cboxcol->width = 512;
	cboxcol->height = 512;
	coin->GetComponentFromObject<Rigidbody2D>()->useGravity = false;
	gameScene->Instantiate(coin);
}