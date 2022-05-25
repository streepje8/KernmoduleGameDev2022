#pragma once
#include <string>
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
};
