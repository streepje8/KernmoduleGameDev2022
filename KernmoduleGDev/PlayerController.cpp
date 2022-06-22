#include "PlayerController.h"
#include "StreepEngine.h"

void PlayerController::Start()
{
	rb = GetComponent<Rigidbody2D>();
}

void PlayerController::Update()
{
	Vector3 positionalChange = Vector3(Input.GetAxis("horizontal") * 500, 0, 0);
	positionalChange = positionalChange * Time.deltaTime;
	rb->AddForce(positionalChange);
}

void PlayerController::OnCollision()
{
	Debug::Log("You died");
}
