#include "Matrix4x4.h"
#include "Vector3.h"
#include "Math.h"
#include <iostream>
#include "Debug.h"
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
	return Vector3(
		(m00*v.x+m10*v.y+m20*v.z+m30) / w,
		(m01*v.x+m11*v.y+m21*v.z+m31) / w,
		(m02*v.x+m12*v.y+m22*v.z+m32) / w
	);
}

Matrix4x4 Matrix4x4::Identity() {
	Matrix4x4 mat = Matrix4x4();
	mat.m00 = 1;
	mat.m11 = 1;
	mat.m22 = 1;
	mat.m33 = 1;
	return mat;
}

Matrix4x4 Matrix4x4::Scale(float s)
{
	Matrix4x4 mat = Matrix4x4(*this);
	mat.m00 = m00 * s;
	mat.m01 = m01 * s;
	mat.m02 = m02 * s;
	mat.m03 = m03 * s;
	mat.m10 = m10 * s;
	mat.m11 = m11 * s;
	mat.m12 = m12 * s;
	mat.m13 = m13 * s;
	mat.m20 = m20 * s;
	mat.m21 = m21 * s;
	mat.m22 = m22 * s;
	mat.m23 = m23 * s;
	mat.m30 = m30 * s;
	mat.m31 = m31 * s;
	mat.m32 = m32 * s;
	mat.m33 = m33 * s;
	return mat;
}

Matrix4x4 Matrix4x4::Scale(Vector3& s)
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat.m00 = s.x;
	mat.m11 = s.y;
	mat.m22 = s.z;
	return mat;
}

Matrix4x4 Matrix4x4::Translate(Vector3& t)
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat.m03 = t.x;
	mat.m13 = t.y;
	mat.m23 = t.z;
	return mat;
}

Matrix4x4 Matrix4x4::Rotate(Vector3& r)
{
	r = r * Math::DEG_TO_RAD;
	Matrix4x4 roty = Matrix4x4::Identity();
	roty.m00 = Math::Cos(r.y);
	roty.m02 = Math::Sin(r.y);
	roty.m20 = -Math::Sin(r.y);
	roty.m22 = Math::Cos(r.y);
	Matrix4x4 rotx = Matrix4x4::Identity();
	rotx.m11 = Math::Cos(r.x);
	rotx.m12 = -Math::Sin(r.x);
	rotx.m21 = Math::Sin(r.x);
	rotx.m22 = Math::Cos(r.x);
	Matrix4x4 rotz = Matrix4x4::Identity();
	rotz.m00 = Math::Cos(r.z);
	rotz.m01 = -Math::Sin(r.z);
	rotz.m10 = Math::Sin(r.z);
	rotz.m11 = Math::Cos(r.z);
	return roty * rotx * rotz;
}

Matrix4x4 Matrix4x4::Transform(Vector3& pos, Vector3& rot, Vector3& scale)
{
	return Translate(pos) * Rotate(rot) * Scale(scale);
}

//Gestolen en geconvert van https://github.com/jMonkeyEngine/jmonkeyengine/blob/97e83fbee30cf2b78bb1617ab17a5b6167ae29f4/jme3-core/src/main/java/com/jme3/math/Matrix3f.java#L981
//En https://github.com/microsoft/referencesource/blob/master/System.Numerics/System/Numerics/Matrix4x4.cs
Matrix4x4 Matrix4x4::Inverse(Matrix4x4& v)
{
	Matrix4x4 inv = Matrix4x4(v);
	float det = v.determinant();
	float invDet = 1.0f / det;
	if(Math::Abs(det) <= Math::Epsilon) {
		return Matrix4x4::Identity();
	}
	
	//These vars do nothing, but they are for clarity
	float a = v.m00, b = v.m01, c = v.m02, d = v.m03;
	float e = v.m10, f = v.m11, g = v.m12, h = v.m13;
	float i = v.m20, j = v.m21, k = v.m22, l = v.m23;
	float m = v.m30, n = v.m31, o = v.m32, p = v.m33;

	float kp_lo = k * p - l * o;
	float jp_ln = j * p - l * n;
	float jo_kn = j * o - k * n;
	float ip_lm = i * p - l * m;
	float io_km = i * o - k * m;
	float in_jm = i * n - j * m;
	float gp_ho = g * p - h * o;
	float fp_hn = f * p - h * n;
	float fo_gn = f * o - g * n;
	float ep_hm = e * p - h * m;
	float eo_gm = e * o - g * m;
	float en_fm = e * n - f * m;
	float gl_hk = g * l - h * k;
	float fl_hj = f * l - h * j;
	float fk_gj = f * k - g * j;
	float el_hi = e * l - h * i;
	float ek_gi = e * k - g * i;
	float ej_fi = e * j - f * i;

	inv.m00 = +(f * kp_lo - g * jp_ln + h * jo_kn) * invDet;
	inv.m10 = -(e * kp_lo - g * ip_lm + h * io_km) * invDet;
	inv.m20 = +(e * jp_ln - f * ip_lm + h * in_jm) * invDet;
	inv.m30 = -(e * jo_kn - f * io_km + g * in_jm) * invDet;
	inv.m01 = -(b * kp_lo - c * jp_ln + d * jo_kn) * invDet;
	inv.m11 = +(a * kp_lo - c * ip_lm + d * io_km) * invDet;
	inv.m21 = -(a * jp_ln - b * ip_lm + d * in_jm) * invDet;
	inv.m31 = +(a * jo_kn - b * io_km + c * in_jm) * invDet;
	inv.m02 = +(b * gp_ho - c * fp_hn + d * fo_gn) * invDet;
	inv.m12 = -(a * gp_ho - c * ep_hm + d * eo_gm) * invDet;
	inv.m22 = +(a * fp_hn - b * ep_hm + d * en_fm) * invDet;
	inv.m32 = -(a * fo_gn - b * eo_gm + c * en_fm) * invDet;
	inv.m03 = -(b * gl_hk - c * fl_hj + d * fk_gj) * invDet;
	inv.m13 = +(a * gl_hk - c * el_hi + d * ek_gi) * invDet;
	inv.m23 = -(a * fl_hj - b * el_hi + d * ej_fi) * invDet;
	inv.m33 = +(a * fk_gj - b * ek_gi + c * ej_fi) * invDet;
	return inv;
}

//Taken from https://github.com/microsoft/referencesource/blob/master/System.Numerics/System/Numerics/Matrix4x4.cs
float Matrix4x4::determinant() {
	//Names are based on this matrix
	// a b c d
	// e f g h
	// i j k l
	// m n o p
	
	float kp_lo = m22 * m33 - m23 * m32;
	float jp_ln = m21 * m33 - m23 * m31;
	float jo_kn = m21 * m32 - m22 * m31;
	float ip_lm = m20 * m33 - m23 * m30;
	float io_km = m20 * m32 - m22 * m30;
	float in_jm = m20 * m31 - m23 * m30;

	return m00 * (m11 * kp_lo - m12 * jp_ln + m13 * jo_kn) -
		m01 * (m10 * kp_lo - m12 * ip_lm + m13 * io_km) +
		m02 * (m10 * jp_ln - m11 * ip_lm + m13 * in_jm) -
		m03 * (m10 * jo_kn - m11 * io_km + m12 * in_jm);
}

std::string Matrix4x4::to_string()
{
	std::string result = "[{";
	result.append(std::to_string(m00) + "," + std::to_string(m01) + "," + std::to_string(m02) + "," + std::to_string(m03) + "},");
	result.append("{" + std::to_string(m10) + "," + std::to_string(m11) + "," + std::to_string(m12) + "," + std::to_string(m13) + "},");
	result.append("{" + std::to_string(m20) + "," + std::to_string(m21) + "," + std::to_string(m22) + "," + std::to_string(m23) + "},");
	result.append("{" + std::to_string(m30) + "," + std::to_string(m31) + "," + std::to_string(m32) + "," + std::to_string(m33) + "}]");
	return result;
}

Matrix4x4::Matrix4x4() : m00(0), m01(0), m02(0), m03(0), m10(0), m11(0), m12(0), m13(0), m20(0), m21(0), m22(0), m23(0), m30(0), m31(0), m32(0), m33(0)
{}

Matrix4x4::Matrix4x4(const Matrix4x4& c)
//m00(c.m00), m01(c.m01), m02(c.m02), m03(c.m03), m10(c.m10), m11(c.m11), m12(c.m12), m13(c.m13), m20(c.m20), m21(c.m21), m22(c.m22), m23(c.m23), m30(c.m30), m31(c.m31), m32(c.m32), m33(c.m33)
// ^ Doesn't work for some reason
{
	m00 = c.m00;
	m01 = c.m01;
	m02 = c.m02;
	m03 = c.m03;
	m10 = c.m10;
	m11 = c.m11;
	m12 = c.m12;
	m13 = c.m13;
	m20 = c.m20;
	m21 = c.m21;
	m22 = c.m22;
	m23 = c.m23;
	m30 = c.m30;
	m31 = c.m31;
	m32 = c.m32;
	m33 = c.m33;
}

Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) : 
	m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33)
{
}
