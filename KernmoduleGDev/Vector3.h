#pragma once
#include <string>
class Vector3
{
	public:
		int x = 0;
		int y = 0;
		int z = 0;
		Vector3();
		Vector3(int x, int y, int z);
		std::string to_string();
		Vector3 operator+(Vector3 v);
		Vector3 operator*(float v);
};
