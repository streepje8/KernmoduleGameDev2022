//C# converted to cpp from https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Quaternion.cs
//And some more code from https://gist.github.com/aeroson/043001ca12fe29ee911e
#include "Quaternion.h"
#include "Math.h"
#include "Debug.h"

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

Quaternion Quaternion::Identity()
{
    return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

Vector3 Quaternion::ToEulerRad(Quaternion rotation)
{
    float sqw = rotation.w * rotation.w;
    float sqx = rotation.x * rotation.x;
    float sqy = rotation.y * rotation.y;
    float sqz = rotation.z * rotation.z;
    float unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
    float test = rotation.x * rotation.w - rotation.y * rotation.z;
    Vector3 v = Vector3(0.0f,0.0f,0.0f);

    if (test > 0.4995f * unit)
    { // singularity at north pole
        v.y = 2.f * Math::ATan2(rotation.y, rotation.x);
        v.x = Math::PI / 2.f;
        v.z = 0;
        return Math::NormalizeAngleVector(v * Math::RAD_TO_DEG);
    }
    if (test < -0.4995f * unit)
    { // singularity at south pole
        v.y = -2.f * Math::ATan2(rotation.y, rotation.x);
        v.x = -Math::PI / 2;
        v.z = 0;
        return Math::NormalizeAngleVector(v * Math::RAD_TO_DEG);
    }
    Quaternion q = Quaternion(rotation.w, rotation.z, rotation.x, rotation.y);
    v.y = Math::ATan2(2.f * q.x * q.w + 2.f * q.y * q.z, 1 - 2.f * (q.z * q.z + q.w * q.w));     // Yaw
    v.x = Math::ASin(2.f * (q.x * q.z - q.w * q.y));                             // Pitch
    v.z = Math::ATan2(2.f * q.x * q.y + 2.f * q.z * q.w, 1 - 2.f * (q.y * q.y + q.z * q.z));      // Roll
    return Math::NormalizeAngleVector(v * Math::RAD_TO_DEG);
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
    return Quaternion::FromEulerRad(Math::NormalizeAngleVector(Vector3(x,y,z)) * Math::DEG_TO_RAD);
}

Quaternion Quaternion::FromEulerRad(Vector3 v)
{
    float yaw = v.x;
    float pitch = v.y;
    float roll = v.z;
    float rollOver2 = roll * 0.5f;
    float sinRollOver2 = (float)Math::Sin((float)rollOver2);
    float cosRollOver2 = (float)Math::Cos((float)rollOver2);
    float pitchOver2 = pitch * 0.5f;
    float sinPitchOver2 = (float)Math::Sin((float)pitchOver2);
    float cosPitchOver2 = (float)Math::Cos((float)pitchOver2);
    float yawOver2 = yaw * 0.5f;
    float sinYawOver2 = (float)Math::Sin((float)yawOver2);
    float cosYawOver2 = (float)Math::Cos((float)yawOver2);
    Quaternion result;
    result.x = cosYawOver2 * cosPitchOver2 * cosRollOver2 + sinYawOver2 * sinPitchOver2 * sinRollOver2;
    result.y = cosYawOver2 * cosPitchOver2 * sinRollOver2 - sinYawOver2 * sinPitchOver2 * cosRollOver2;
    result.z = cosYawOver2 * sinPitchOver2 * cosRollOver2 + sinYawOver2 * cosPitchOver2 * sinRollOver2;
    result.w = sinYawOver2 * cosPitchOver2 * cosRollOver2 - cosYawOver2 * sinPitchOver2 * sinRollOver2;
    return result;
}
