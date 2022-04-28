#include "Vector3.h"
#include <string>

Vector3::Vector3(int x, int y, int z) {
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