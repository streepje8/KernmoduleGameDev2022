//C# converted to cpp from https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Quaternion.cs
//And some more code from https://gist.github.com/aeroson/043001ca12fe29ee911e
#include "Quaternion.h"
#include "Math.h"
#include "Debug.h"
#include <string>
#include <cmath>

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{}

Quaternion::Quaternion() //Same as Quaternion::Identity()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    this->w = 1.0f;
}

Quaternion Quaternion::operator*(Quaternion q)
{
    return Quaternion(
        this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y,
        this->w * q.y + this->y * q.w + this->z * q.x - this->x * q.z,
        this->w * q.z + this->z * q.w + this->x * q.y - this->y * q.x,
        this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z);
}

Quaternion Quaternion::operator*=(Quaternion q)
{
    return Quaternion(
        this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y,
        this->w * q.y + this->y * q.w + this->z * q.x - this->x * q.z,
        this->w * q.z + this->z * q.w + this->x * q.y - this->y * q.x,
        this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z);
}

Vector3 Quaternion::operator*(Vector3 v)
{
    float x = this->x * 2.f;
    float y = this->y * 2.f;
    float z = this->z * 2.f;
    float xx = this->x * x;
    float yy = this->y * y;
    float zz = this->z * z;
    float xy = this->x * y;
    float xz = this->x * z;
    float yz = this->y * z;
    float wx = this->w * x;
    float wy = this->w * y;
    float wz = this->w * z;

    Vector3 res = Vector3(0,0,0);
    res.x = (1.f - (yy + zz)) * v.x + (xy - wz) * v.y + (xz + wy) * v.z;
    res.y = (xy + wz) * v.x + (1.f - (xx + zz)) * v.y + (yz - wx) * v.z;
    res.z = (xz - wy) * v.x + (yz + wx) * v.y + (1.f - (xx + yy)) * v.z;
    return res;
}

bool Quaternion::operator==(Quaternion q)
{
    return IsEqualUsingDot(Dot(this, &q));
}

bool Quaternion::IsEqualUsingDot(float dot)
{
    return dot > 1.0f - Math::Epsilon;
}

Quaternion Quaternion::Normalize(Quaternion q)
{
    float mag = Math::Sqrt(Dot(q, q));

    if (mag < Math::Epsilon)
        return Quaternion::Identity();

    return Quaternion(q.x / mag, q.y / mag, q.z / mag, q.w / mag);
}

float Quaternion::Angle(Quaternion* a, Quaternion* b)
{
    float dot = Math::Min(Math::Abs(Dot(a, b)), 1.0F);
    return IsEqualUsingDot(dot) ? 0.0f : Math::RadToDeg(Math::ACos(dot) * 2.0f);
}

float Quaternion::Angle(Quaternion a, Quaternion b)
{
    return Quaternion::Angle(&a,&b);
}

float Quaternion::Dot(Quaternion* a, Quaternion* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

float Quaternion::Dot(Quaternion a, Quaternion b)
{
    return Dot(&a, &b);
}

Vector3 Quaternion::Euler()
{
    return Quaternion::ToEulerRad(*this) * Math::RAD_TO_DEG;
}

std::string Quaternion::to_string()
{
    std::string str = std::string();
    str.append("Q${");
    str.append(std::to_string(this->x));
    str.append(",");
    str.append(std::to_string(this->y));
    str.append(",");
    str.append(std::to_string(this->z));
    str.append(",");
    str.append(std::to_string(this->w));
    str.append("}");
    return str;
}

Quaternion Quaternion::Identity()
{
    return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

Vector3 Quaternion::ToEulerRad(Quaternion rotation)
{
    Vector3 result;
	
    // roll (x-axis rotation)
    double sinr_cosp = 2 * (rotation.w * rotation.x + rotation.y * rotation.z);
    double cosr_cosp = 1 - 2 * (rotation.x * rotation.x + rotation.y * rotation.y);
    result.z = Math::ATan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (rotation.w * rotation.y - rotation.z * rotation.x);
    if (std::abs(sinp) >= 1)
        result.y = std::copysign(Math::PI / 2, sinp); // use 90 degrees if out of range
    else
        result.y = Math::ASin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (rotation.w * rotation.z + rotation.x * rotation.y);
    double cosy_cosp = 1 - 2 * (rotation.y * rotation.y + rotation.z * rotation.z);
    result.x = Math::ATan2(siny_cosp, cosy_cosp);
    return Math::NormalizeAngleVector(result * Math::RAD_TO_DEG);
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
    return Quaternion::FromEulerRad(Math::NormalizeAngleVector(Vector3(x,y,z)) * Math::DEG_TO_RAD);
}

Quaternion Quaternion::FromEulerRad(Vector3 v)
{
    float yaw = v.x * 0.5f;
    float pitch = v.y * 0.5f;
    float roll = v.z * 0.5f;
	
    float sr = (float)Math::Sin((float)roll);
    float cr = (float)Math::Cos((float)roll);

    float sp = (float)Math::Sin((float)pitch);
    float cp = (float)Math::Cos((float)pitch);
	
    float sy = (float)Math::Sin((float)yaw);
    float cy = (float)Math::Cos((float)yaw);
    Quaternion result;
    result.w = cr * cp * cy + sr * sp * sy;
    result.x = sr * cp * cy - cr * sp * sy;
    result.y = cr * sp * cy + sr * cp * sy;
    result.z = cr * cp * sy - sr * sp * cy;
    return result;
}
