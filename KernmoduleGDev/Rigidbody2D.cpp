#include "Rigidbody2D.h"
#include "Macros.h"

void Rigidbody2D::Start()
{
	velocity = VAR(Vector3,new Vector3(0, 0, 0));
	collider = GetComponent<BoxCollider2D>();
}

void Rigidbody2D::Update()
{
	if(useGravity)
		AddForce((gravity * Time.deltaTime) * mass);
	AddForce(GetFrictionForce());
	velocity->x = Math::Clamp(velocity->x, -maxVelocity.x, maxVelocity.x);
	velocity->y = Math::Clamp(velocity->y, -maxVelocity.y, maxVelocity.y);
	velocity->z = Math::Clamp(velocity->z, -maxVelocity.z, maxVelocity.z);
	transform->position = transform->position + (*velocity * Time.deltaTime * pixelsPerMetre);
}

Vector3 Rigidbody2D::GetFrictionForce() { //This is not really realistic but it feels good enough to be convincing for the end user
	return (*velocity * -0.001) * friction * CalculateDragCoefficient() * CalculateFacingArea();
}

float Rigidbody2D::CalculateFacingArea() { //So the size of the object matters for the friction
	Vector3 right = Vector3(1, 0, 0);
	float angle = Math::Abs((transform->rotation * velocity->normalize()).dot(&right));
	return  ((collider->width / pixelsPerMetre) * angle) + ((collider->height / pixelsPerMetre) * (1-angle));
}

float Rigidbody2D::CalculateDragCoefficient() { //So the rotation of the object matters for the amount of (air) friction, since angled cubes have less friction
	float angle = Math::Abs(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 90) - 45) / 45.0f; 
	return (0.4f * angle) + (0.8f * (1 - angle));
}

void Rigidbody2D::AddForce(Vector3 force)
{
	Vector3 newVelocity = *velocity + (force / mass);
	velocity->x = newVelocity.x;
	velocity->y = newVelocity.y;
	velocity->z = newVelocity.z;
}
