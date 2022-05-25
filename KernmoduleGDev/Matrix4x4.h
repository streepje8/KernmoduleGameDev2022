#pragma once
#include "Vector3.h"
struct Matrix4x4
{
public:
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
	float m30;
	float m31;
	float m32;
	float m33;
	Matrix4x4 operator*(Matrix4x4 v);
	Vector3 operator*(Vector3 v);
	static Matrix4x4 Identity();
	static Matrix4x4 Scale(Vector3 s);
	static Matrix4x4 Translate(Vector3 t);
	static Matrix4x4 Rotate(Vector3 r);
	static Matrix4x4 Transform(Vector3 pos, Vector3 rot, Vector3 scale);
	std::string to_string();
	Matrix4x4();
	Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
};

