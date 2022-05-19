#pragma once
#include "Vector3.h"
class Quaternion
{ 
	public:
		float x;
		float y;
		float z;
		float w;
		
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		static Quaternion Identity();
		static Vector3 ToEulerRad(Quaternion rotation);
		Quaternion operator*(Quaternion q);
		Vector3 operator*(Vector3 v);
		bool operator==(Quaternion q);
		bool IsEqualUsingDot(float dot);
		Quaternion Normalize(Quaternion q);
		float Angle(Quaternion* a, Quaternion* b);
		float Angle(Quaternion a, Quaternion b);
		float Dot(Quaternion* a, Quaternion* b);
		float Dot(Quaternion a, Quaternion b);
};
