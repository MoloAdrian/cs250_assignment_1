#include "Point4.h"
#include "MathUtilities.h"

// Default constructor, sets x,y,z to zero and w to the defined value
Point4::Point4(void)
{
    Zero();
}
// Copy constructor, copies every component from the other Point4
Point4::Point4(const Point4& rhs)
{
    *this = rhs;
}
// Non-Default constructor, self-explanatory
Point4::Point4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww)
{

}
// Assignment operator, copies every component from the other Point4
Point4& Point4::operator=(const Point4& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;

    return *this;
}
// Unary negation operator, negates every component and returns a copy
Point4 Point4::operator-(void) const
{
    return Point4(-x, -y, -z, -w);
}
// Binary subtraction operator, Subtract two Point4s and you get a Vector4
Vector4 Point4::operator-(const Point4& rhs) const
{
    Vector4 result;

    result.x = x - rhs.x;
    result.y = y - rhs.y;
    result.z = z - rhs.z;
    result.w = w - rhs.w;

    return result;
}
// Basic vector math operations with points, you can add a Vector4 to a Point4, or
// subtract a Vector4 from a Point4
Point4 Point4::operator+ (const Vector4& rhs) const
{
    Point4 result;

    result.x = rhs.x + x;
    result.y = rhs.y + y;
    result.z = rhs.z + z;
    result.w = rhs.w + w;

    return result;
}
Point4 Point4::operator- (const Vector4& rhs) const
{
    Point4 result;

    result.x = x - rhs.x;
    result.y = y - rhs.y;
    result.z = z - rhs.z;
    result.w = w - rhs.w;

    return result;
}
// Same as previous two operators, just modifies the original instead of returning a
// copy
Point4& Point4::operator+=(const Vector4& rhs)
{
    *this = *this + rhs;
    return *this;
}
Point4& Point4::operator-=(const Vector4& rhs)
{
    *this = *this - rhs;
    return *this;
}
// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Point4::operator==(const Point4& rhs) const
{
    return isEqual(x, rhs.x) && isEqual(y, rhs.y) && isEqual(z, rhs.z) && isEqual(w, rhs.w);
}
bool Point4::operator!=(const Point4& rhs) const
{
    return !(*this == rhs);
}
// Sets x,y,z to zeroes, w to defined value
void Point4::Zero(void)
{
    x = 0;
    y = 0;
    z = 0;
    w = 1;
}
