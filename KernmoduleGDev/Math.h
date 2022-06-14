#pragma once
#include "Vector3.h"
class Math
{
public:
	static float DegToRad(float degrees);
	static float RadToDeg(float radians);
	static float Clamp(float value, float min, float max);
	float Clamp01(float value);
	static float Lerp(float start, float end, float t);
	static float InverseLerp(float start, float end, float value);
	static float Smoothstep(float start, float end, float t);
	static float Round(float i);
	static int RountToInt(float i);
	static float Floor(float i);
	static int FloorToInt(float i);
	static float Ceil(float i);
	static int CielToInt(float i);
	static float Min(float a, float b);
	static float Max(float a, float b);
	static float Abs(float a);
	static float Cos(float a);
	static float Sin(float a);
	static float Tan(float a);
	static float ACos(float a);
	static float ASin(float a);
	static float ATan(float a);
	static float ACosh(float a);
	static float ASinh(float a);
	static float ATan2(float a, float b);
	static float Sqrt(float a);
	static float MOD(float a, float b);
	static Vector3 NormalizeAngleVector(Vector3 v);
	static constexpr double PI = 3.14159265358979323846;
	static constexpr double TWO_PI = 6.28318530717958647692;
	static constexpr double RAD_TO_DEG = 57.2957795131;
	static constexpr double DEG_TO_RAD = 0.01745329251;
	static constexpr float Epsilon = 0.000001F;
};