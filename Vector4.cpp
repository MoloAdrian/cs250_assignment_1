#include "Vector4.h"
#include "MathUtilities.h"
#include <math.h>

// Default constructor, initializes x,y,z to zeroes, w to defined value
Vector4::Vector4(void)
{
    Zero();
}
// Copy constructor, copies every component from the other Vector4
Vector4::Vector4(const Vector4& rhs)
{
    *this = rhs;
}
// Non-Default constructor, self explanatory
Vector4::Vector4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww)
{
}
// Assignment operator, does not need to handle self assignment
Vector4& Vector4::operator=(const Vector4& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;

    return *this;
}
// Unary negation operator, negates all components and returns a copy
Vector4 Vector4::operator-(void) const
{
    return Vector4(-x, -y, -z, -w);
}  
// Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A from
// Vector B, or multiply a vector with a scalar, or divide a vector by that scalar
Vector4 Vector4::operator+(const Vector4& rhs) const
{
    Vector4 result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    result.z = z + rhs.z;
    result.w = w + rhs.w;

    return result;
}
Vector4 Vector4::operator-(const Vector4& rhs) const
{
    Vector4 result;
    result.x = x - rhs.x;
    result.y = y - rhs.y;
    result.z = z - rhs.z;
    result.w = w - rhs.w;

    return result;
}
Vector4 Vector4::operator*(const float rhs) const
{
    Vector4 result;
    result.x = rhs * x;
    result.y = rhs * y;
    result.z = rhs * z;
    result.w = rhs * w;

    return result;
}
Vector4 Vector4::operator/(const float rhs) const
{
    Vector4 result;
    result.x = x / rhs;
    result.y = y / rhs;
    result.z = z / rhs;
    result.w = w / rhs;

    return result;
}
// Same as above, just stores the result in the original vector
Vector4& Vector4::operator+=(const Vector4& rhs)
{
    *this = *this + rhs;
    return *this;
}
Vector4& Vector4::operator-=(const Vector4& rhs)
{
    *this = *this - rhs;
    return *this;
}
Vector4& Vector4::operator*=(const float rhs)
{
    *this = *this * rhs;
    return *this;
}
Vector4& Vector4::operator/=(const float rhs)
{
    *this = *this / rhs;
    return *this;
}
// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Vector4::operator==(const Vector4& rhs) const
{
    return isEqual(x, rhs.x) && isEqual(y, rhs.y) && isEqual(z, rhs.z) && isEqual(w, rhs.w);
}
bool Vector4::operator!=(const Vector4& rhs) const  
{
    return !(*this == rhs);
}
// Computes the dot product with the other vector. Treat it as 3D vector.
float Vector4::Dot(const Vector4& rhs) const
{
    return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;
}
// Computes the cross product with the other vector. Treat it as a 3D vector.
Vector4 Vector4::Cross(const Vector4& rhs) const
{
    Vector4 result;

    result.x = y*rhs.z - rhs.y*z;
    result.y = z*rhs.x - x*rhs.z;
    result.z = x*rhs.y - y*rhs.x;

    return result;
}
// Computes the true length of the vector
float Vector4::Length(void) const
{
    return sqrtf(x*x + y*y + z*z + w*w);
}
// Computes the squared length of the vector
float Vector4::LengthSq(void) const
{
    return pow(Length(),2);
}
// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
void Vector4::Normalize(void)
{
    if(Length() != 0)
        *this = *this/Length();
}
// Sets x,y,z to zeroes, w to defined value
void Vector4::Zero(void)
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}