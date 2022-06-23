#include "PlayerController.h"
#include "StreepEngine.h"

void PlayerController::Start()
{
	rb = GetComponent<Rigidbody2D>();
	direction = 1;
}

void PlayerController::Update()
{
	Vector3 positionalChange = Vector3(Input.GetAxis("horizontal") * 50, 0, 0);
	direction = Math::Sign(Input.GetAxis("horizontal"));
	transform->scale = Vector3(direction * 0.4, 0.4, 1);
	positionalChange = positionalChange * Time.deltaTime;
	rb->AddForce(positionalChange);
	Vector3 newPos = transform->position + (*(rb->velocity) * Time.deltaTime * rb->pixelsPerMetre);
	if (newPos.x >= 400 || newPos.x <= -400) {
		rb->velocity->x *= -1;
		rb->velocity->y *= -1;
		rb->velocity->z *= -1;
	}
}
