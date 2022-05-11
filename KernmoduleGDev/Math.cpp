#include "Math.h"
#include <cmath>

float Math::DegToRad(float degrees)
{
    return degrees * PI_DIV_ONE_EIGHTY;
}

float Math::RadToDeg(float radians)
{
    return radians * ONE_EIGHTY_DIV_PI;
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
