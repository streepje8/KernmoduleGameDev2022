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
		Vector3 operator*(float v);
		float magnitude();
		float dot(Vector3* other);
		Vector3 cross(Vector3* other);
		sf::Vector2f to_SFVector2f();
		sf::Vector3f to_SFVector3f();
};
