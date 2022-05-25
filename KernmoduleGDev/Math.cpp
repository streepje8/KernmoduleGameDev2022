#include "Math.h"
#include <cmath>
#include "Vector3.h"

float Math::DegToRad(float degrees)
{
    return degrees * DEG_TO_RAD;
}

float Math::RadToDeg(float radians)
{
    return radians * RAD_TO_DEG;
}

float Math::Clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

float Math::Clamp01(float value)
{
    if (value < 0.0f) return 0.0f;
    if (value > 1.0f) return 1.0f;
    return value;
}

float Math::Lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

float Math::InverseLerp(float a, float b, float t)
{
    return (t - a) / (b - a);
}

float Math::Smoothstep(float a, float b, float t)
{
    Clamp((t - a) / (b - a), 0.0f, 1.0f);
    return t * t * (3 - 2 * t);
}

float Math::Round(float i)
{
    return Floor(i + 0.5f);
}

int Math::RountToInt(float i)
{
    return FloorToInt(i + 0.5f);
}

float Math::Floor(float i)
{
    return (float)(int)i;
}

int Math::FloorToInt(float i)
{
    return (int)i;
}

float Math::Ceil(float i)
{
    return std::ceil(i);
}

int Math::CielToInt(float i)
{
    return (int)std::ceil(i);
}

float Math::Min(float a, float b)
{
    if (a < b) return a;
    if (b < a) return b;
    return a;
}

float Math::Max(float a, float b)
{
    if (a > b) return a;
    if (b > a) return b;
    return a;
}

float Math::Abs(float a)
{
    return std::pow((a*a), 0.5f);
}

float Math::Cos(float a)
{
    return std::cos(a);
}

float Math::Sin(float a)
{
    return std::sin(a);
}

float Math::Tan(float a)
{
    return std::tan(a);
}

float Math::ACos(float a)
{
    return std::acos(a);
}

float Math::ASin(float a)
{
    return std::asin(a);
}

float Math::ATan(float a)
{
    return std::atan(a);
}

float Math::ACosh(float a)
{
    return std::acosh(a);
}

float Math::ASinh(float a)
{
    return std::asinh(a);
}

float Math::ATan2(float a, float b)
{
    return std::atan2(a,b);
}

float Math::Sqrt(float a)
{
    return std::pow(a, 0.5f);
}

Vector3 Math::NormalizeAngleVector(Vector3 v)
{
    return Vector3(std::fmod(v.x, 360), std::fmod(v.y,360), std::fmod(v.z, 360));
}
