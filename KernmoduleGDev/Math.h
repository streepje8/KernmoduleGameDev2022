#pragma once
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
	static constexpr double PI = 3.14159265358979323846;
	static constexpr double TWO_PI = 6.28318530717958647692;
	static constexpr double ONE_EIGHTY_DIV_PI = 57.2957795131;
	static constexpr double PI_DIV_ONE_EIGHTY = 0.01745329251;
};

