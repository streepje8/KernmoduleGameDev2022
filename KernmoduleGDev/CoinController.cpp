#include "CoinController.h"


void CoinController::Start()
{
	rb = GetComponent<Rigidbody2D>();
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
	if (transform->position.y < -420) {
		transform->position = Vector3(Math::Rand(-380, 380), 420, 0);
		transform->rotation = Quaternion::Euler(0, 0, 0);
		sdp->lives--;
	}
	Vector3 newPos = transform->position + (*(rb->velocity) * Time.deltaTime * rb->pixelsPerMetre);
	if (newPos.x >= 380 || newPos.x <= -380) {
		direction *= -1;
	}
}

void CoinController::OnCollision()
{
	transform->position = Vector3(Math::Rand(-380, 380),420,0);
	transform->rotation = Quaternion::Euler(0, 0, 0);
	sdp->coinsCollected++;
}
