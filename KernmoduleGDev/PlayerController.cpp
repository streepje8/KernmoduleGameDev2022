#include "PlayerController.h"
#include "StreepEngine.h"

void PlayerController::Start()
{
	transform->position = transform->position + Vector3(200, 200,0);
}

void PlayerController::Update()
{
	Vector3 positionalChange = Vector3(Input.GetAxis("horizontal") * 500, 0, 0);
	positionalChange = positionalChange * Time::GetInstance().deltaTime;
	transform->position = transform->position + positionalChange;
}
