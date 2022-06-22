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
	AddForce(GetAirResistanceForce());
	transform->position = transform->position + (*velocity * Time.deltaTime);
}

//Using the formula from https://www.softschools.com/formulas/physics/air_resistance_formula/85/
//Fa = ((air density * drag * area) / 2) * (velocity^2)
//The air density and drag are taken from google
Vector3 Rigidbody2D::GetAirResistanceForce() {
	return (*velocity ^ 2) * -((1.225f * CalculateDragCoefficient() * CalculateFacingArea()) / 2);
}

//Interpolate between the width face and the height face
float Rigidbody2D::CalculateFacingArea() {
	Vector3 right = Vector3(1, 0, 0);
	float angle = Math::Abs((transform->rotation * velocity->normalize()).dot(&right));
	return  (collider->width * angle) + (collider->height * (1-angle));
}

//Interpolate between cube and angled cube values found on https://en.wikipedia.org/wiki/Drag_coefficient
float Rigidbody2D::CalculateDragCoefficient() {
	float angle = Math::Abs(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 90) - 45) / 45.0f; 
	return (0.8f * angle) + (1.05f * (1 - angle));
}

void Rigidbody2D::AddForce(Vector3 force)
{
	Vector3 newVelocity = *velocity + (force / mass);
	velocity->x = newVelocity.x;
	velocity->y = newVelocity.y;
	velocity->z = newVelocity.z;
}
