#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

class Vector3
{
	public:
		float x = 0;
		float y = 0;
		float z = 0;
		Vector3();
		Vector3(float x, float y, float z);
		std::string to_string();
		Vector3 operator+(Vector3 v);
		Vector3 operator-(Vector3 v);
		Vector3 operator*(Vector3 v);
		Vector3 operator*=(Vector3 v);
		Vector3 operator+=(Vector3 v);
		Vector3 operator-=(Vector3 v);
		Vector3 operator^(int v);
		Vector3 operator*(float v);
		Vector3 operator/(float v);
		float magnitude();
		float dot(Vector3* other);
		Vector3 cross(Vector3* other);
		Vector3 Reflect(Vector3* inNormal);
		Vector3 normalize();
		sf::Vector2f to_SFVector2f();
		sf::Vector2f to_SFVector2f_dropZ();
		sf::Vector3f to_SFVector3f();
};
