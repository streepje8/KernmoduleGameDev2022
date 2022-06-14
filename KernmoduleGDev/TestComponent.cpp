#include "TestComponent.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Debug.h"
#include "Math.h"
#include <string>

void TestComponent::Update()
{
	
	//transform->position = transform->position + Vector3(0.1, 0, 0);
	Debug::Log(Quaternion::Euler(0, 0, 2).Euler().to_string());
	//transform->rotation = Quaternion::Euler(0,0,2) * transform->rotation;
	//Debug::Log(std::to_string(Math::MOD(Quaternion::ToEulerRad(transform->rotation).z * Math::RAD_TO_DEG,360)));
}
