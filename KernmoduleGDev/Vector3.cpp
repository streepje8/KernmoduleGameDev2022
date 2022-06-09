#include "Vector3.h"
#include "Math.h"

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

std::string Vector3::to_string()
{
	std::string str("[");
	str.append(std::to_string(x));
	str.append(", ");
	str.append(std::to_string(y));
	str.append(", ");
	str.append(std::to_string(z));
	str.append("]");
	return str;
}

Vector3 Vector3::operator+(Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator*(float v)
{
	return Vector3(x * v, y * v, z * v);
}

float Vector3::magnitude()
{
	return Math::Sqrt(x*x+y*y+z*z);
}

float Vector3::dot(Vector3* other)
{
	return 0.0f;
}

Vector3 Vector3::cross(Vector3* other)
{
	return Vector3();
}

sf::Vector2f Vector3::to_SFVector2f()
{
	return sf::Vector2f(this->x/this->z,this->y/this->z);
}

sf::Vector3f Vector3::to_SFVector3f()
{
	return sf::Vector3f(this->x,this->y,this->z);
}
