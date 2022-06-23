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

Vector3 Vector3::operator-(Vector3 v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(Vector3 v)
{
	return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator*=(Vector3 v)
{
	return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator+=(Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-=(Vector3 v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator^(int v)
{
	//New xyz
	float Nx = 1;
	float Ny = 1;
	float Nz = 1;
	for (int i = 0; i < v; i++) {
		Nx *= x;
		Ny *= y;
		Nz *= z;
	}
	return Vector3(Nx, Ny, Nz);
}

Vector3 Vector3::operator*(float v)
{
	return Vector3(x * v, y * v, z * v);
}

Vector3 Vector3::operator*=(float v)
{
	return Vector3(x * v, y * v, z * v);
}

Vector3 Vector3::operator/(float v)
{
	return Vector3(x / v, y / v, z / v);
}

Vector3 Vector3::operator/=(float v)
{
	return Vector3(x / v, y / v, z / v);
}


float Vector3::magnitude()
{
	return Math::Sqrt(x*x+y*y+z*z);
}

//Below three functions have been taken from https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Vector3.cs

float Vector3::dot(Vector3* other)
{
	return x * other->x + y * other->y + z * other->z;
}

Vector3 Vector3::cross(Vector3* other)
{
	return Vector3(y * other->z - z * other->y,
		z * other->x - x * other->z,
		x * other->y - y * other->x);
}

Vector3 Vector3::Reflect(Vector3* inNormal)
{
	float factor = -2.0f * this->dot(inNormal);
	return Vector3(factor * inNormal->x + x,
		factor * inNormal->y + y,
		factor * inNormal->z + z);
}

Vector3 Vector3::normalize() {
	return *this / Math::Clamp(this->magnitude(),Math::Epsilon,99999999);
}

Vector3 Vector3::clamp(Vector3* minValues, Vector3* maxValues)
{
	return Vector3(Math::Clamp(x,minValues->x,maxValues->x), Math::Clamp(y, minValues->y, maxValues->y), Math::Clamp(z, minValues->z, maxValues->z));
}

sf::Vector2f Vector3::to_SFVector2f()
{
	if (z != 0) 
	{
		return sf::Vector2f(this->x / this->z, this->y / this->z);
	}
	else {
		return sf::Vector2f(0, 0); //edge case for division by zero
	}
}

sf::Vector2f Vector3::to_SFVector2f_dropZ()
{
	return sf::Vector2f(this->x, this->y);
}

sf::Vector3f Vector3::to_SFVector3f()
{
	return sf::Vector3f(this->x,this->y,this->z);
}
