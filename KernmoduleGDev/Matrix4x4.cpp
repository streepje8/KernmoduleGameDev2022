#include "Matrix4x4.h"
#include "Vector3.h"
#include "Math.h"
Matrix4x4 Matrix4x4::operator*(Matrix4x4 v)
{
	return Matrix4x4(
		m00*v.m00+m01*v.m10+m02*v.m20+m03*v.m30,
		m00*v.m01+m01*v.m11+m02*v.m21+m03*v.m31,
		m00*v.m02+m01*v.m12+m02*v.m22+m03*v.m32,
		m00*v.m03+m01*v.m13+m02*v.m23+m03*v.m33,
		m10*v.m00+m11*v.m10+m12*v.m20+m13*v.m30,
		m10*v.m01+m11*v.m11+m12*v.m21+m13*v.m31,
		m10*v.m02+m11*v.m12+m12*v.m22+m13*v.m32,
		m10*v.m03+m11*v.m13+m12*v.m23+m13*v.m33,
		m20*v.m00+m21*v.m10+m22*v.m20+m23*v.m30,
		m20*v.m01+m21*v.m11+m22*v.m21+m23*v.m31,
		m20*v.m02+m21*v.m12+m22*v.m22+m23*v.m32,
		m20*v.m03+m21*v.m13+m22*v.m23+m23*v.m33,
		m30*v.m00+m31*v.m10+m32*v.m20+m33*v.m30,
		m30*v.m01+m31*v.m11+m32*v.m21+m33*v.m31,
		m30*v.m02+m31*v.m12+m32*v.m22+m33*v.m32,
		m30*v.m03+m31*v.m13+m32*v.m23+m33*v.m33
	);
}

Vector3 Matrix4x4::operator*(Vector3 v)
{
	float w = m03*v.x+m13*v.y+m23*v.z+m33;
	new Vector3(
		(m00*v.x+m10*v.y+m20*v.z+m30) / w,
		(m01*v.x+m11*v.y+m21*v.z+m31) / w,
		(m02*v.x+m12*v.y+m22*v.z+m32) / w
	);
}

Matrix4x4 Identity() {
	Matrix4x4 mat = Matrix4x4();
	mat.m00 = 1;
	mat.m11 = 1;
	mat.m22 = 1;
	mat.m33 = 1;
	return mat;
}

Matrix4x4 Matrix4x4::Scale(Vector3 s)
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat.m00 = s.x;
	mat.m11 = s.y;
	mat.m22 = s.z;
	return mat;
}

Matrix4x4 Matrix4x4::Translate(Vector3 t)
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat.m03 = t.x;
	mat.m13 = t.y;
	mat.m23 = t.z;
	return mat;
}

Matrix4x4 Matrix4x4::Rotate(Vector3 r)
{
	Matrix4x4 rotz = Matrix4x4::Identity();
	rotz.m00 = Math::Cos(r.z);
	rotz.m01 = -Math::Sin(r.z);
	rotz.m10 = Math::Sin(r.z);
	rotz.m11 = Math::Cos(r.z);
	Matrix4x4 rotx = Matrix4x4::Identity();
	rotz.m11 = Math::Cos(r.y);
	rotz.m12 = -Math::Sin(r.y);
	rotz.m21 = Math::Sin(r.y);
	rotz.m22 = Math::Cos(r.y);
	Matrix4x4 roty = Matrix4x4::Identity();
	roty.m00 = Math::Cos(r.y);
	roty.m03 = Math::Sin(r.y);
	roty.m20 = -Math::Sin(r.y);
	roty.m23 = Math::Cos(r.y);
	return rotz * rotx * roty;
}

Matrix4x4 Matrix4x4::Transform(Vector3 pos, Vector3 rot, Vector3 scale)
{
	return Scale(scale) * Rotate(rot) * Translate(pos);
}

Matrix4x4::Matrix4x4() : m00(0), m01(0), m02(0), m03(0), m10(0), m11(0), m12(0), m13(0), m20(0), m21(0), m22(0), m23(0), m30(0), m31(0), m32(0), m33(0)
{}

Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) : 
	m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33)
{
}
