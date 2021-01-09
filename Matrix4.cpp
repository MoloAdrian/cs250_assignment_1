#include "Matrix4.h"
#include "MathUtilities.h"

// Default constructor should initialize to zeroes
Matrix4::Matrix4(void)
{
    Zero();
}
// Copy constructor, copies every entry from the other matrix.
Matrix4::Matrix4(const Matrix4& rhs)
{
    *this = rhs;
}
// Non-default constructor, self-explanatory
Matrix4::Matrix4(float mm00, float mm01, float mm02, float mm03,
float mm10, float mm11, float mm12, float mm13,
float mm20, float mm21, float mm22, float mm23,
float mm30, float mm31, float mm32, float mm33)
{
    m[0][0] = mm00;
    m[0][1] = mm01;
    m[0][2] = mm02;
    m[0][3] = mm03;
    m[1][0] = mm10;
    m[1][1] = mm11;
    m[1][2] = mm12;
    m[1][3] = mm13;
    m[2][0] = mm20;
    m[2][1] = mm21;
    m[2][2] = mm22;
    m[2][3] = mm23;
    m[3][0] = mm30;
    m[3][1] = mm31;
    m[3][2] = mm32;
    m[3][3] = mm33;
}
// Assignment operator, does not need to handle self-assignment
Matrix4& Matrix4::operator=(const Matrix4& rhs)
{
    for(int i = 0; i < 16; i++)
        v[i] = rhs.v[i];

    return *this;
}
// Multiplying a Matrix4 with a Vector4 or a Point4
Vector4 Matrix4::operator*(const Vector4& rhs) const
{
    Vector4 result;

    result.x = m[0][0]*rhs.x + m[0][1]*rhs.y + m[0][2]*rhs.z + m[0][3]*rhs.w;
    result.y = m[1][0]*rhs.x + m[1][1]*rhs.y + m[1][2]*rhs.z + m[1][3]*rhs.w;
    result.z = m[2][0]*rhs.x + m[2][1]*rhs.y + m[2][2]*rhs.z + m[2][3]*rhs.w;
    result.w = m[3][0]*rhs.x + m[3][1]*rhs.y + m[3][2]*rhs.z + m[3][3]*rhs.w;

    return result;
}
Point4 Matrix4::operator*(const Point4& rhs) const
{
    Point4 result;

    result.x = m[0][0]*rhs.x + m[0][1]*rhs.y + m[0][2]*rhs.z + m[0][3]*rhs.w;
    result.y = m[1][0]*rhs.x + m[1][1]*rhs.y + m[1][2]*rhs.z + m[1][3]*rhs.w;
    result.z = m[2][0]*rhs.x + m[2][1]*rhs.y + m[2][2]*rhs.z + m[2][3]*rhs.w;
    result.w = m[3][0]*rhs.x + m[3][1]*rhs.y + m[3][2]*rhs.z + m[3][3]*rhs.w;

    return result;
}
// Basic Matrix arithmetic operations
Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
    Matrix4 result;

    for(int i = 0; i < 16; i++)
        result.v[i] = v[i] + rhs.v[i];
    
    return result;
}
Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
    Matrix4 result;

    for(int i = 0; i < 16; i++)
        result.v[i] = v[i] - rhs.v[i];
    
    return result;
}
Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
    Matrix4 result;
    int count = 0;
    result.v[count++] = m[0][0]*rhs.m[0][0] + m[0][1]*rhs.m[1][0] + m[0][2]*rhs.m[2][0] + m[0][3]*rhs.m[3][0];
    result.v[count++] = m[0][0]*rhs.m[0][1] + m[0][1]*rhs.m[1][1] + m[0][2]*rhs.m[2][1] + m[0][3]*rhs.m[3][1];
    result.v[count++] = m[0][0]*rhs.m[0][2] + m[0][1]*rhs.m[1][2] + m[0][2]*rhs.m[2][2] + m[0][3]*rhs.m[3][2];
    result.v[count++] = m[0][0]*rhs.m[0][3] + m[0][1]*rhs.m[1][3] + m[0][2]*rhs.m[2][3] + m[0][3]*rhs.m[3][3];

    result.v[count++] = m[1][0]*rhs.m[0][0] + m[1][1]*rhs.m[1][0] + m[1][2]*rhs.m[2][0] + m[1][3]*rhs.m[3][0];
    result.v[count++] = m[1][0]*rhs.m[0][1] + m[1][1]*rhs.m[1][1] + m[1][2]*rhs.m[2][1] + m[1][3]*rhs.m[3][1];
    result.v[count++] = m[1][0]*rhs.m[0][2] + m[1][1]*rhs.m[1][2] + m[1][2]*rhs.m[2][2] + m[1][3]*rhs.m[3][2];
    result.v[count++] = m[1][0]*rhs.m[0][3] + m[1][1]*rhs.m[1][3] + m[1][2]*rhs.m[2][3] + m[1][3]*rhs.m[3][3];

    result.v[count++] = m[2][0]*rhs.m[0][0] + m[2][1]*rhs.m[1][0] + m[2][2]*rhs.m[2][0] + m[2][3]*rhs.m[3][0];
    result.v[count++] = m[2][0]*rhs.m[0][1] + m[2][1]*rhs.m[1][1] + m[2][2]*rhs.m[2][1] + m[2][3]*rhs.m[3][1];
    result.v[count++] = m[2][0]*rhs.m[0][2] + m[2][1]*rhs.m[1][2] + m[2][2]*rhs.m[2][2] + m[2][3]*rhs.m[3][2];
    result.v[count++] = m[2][0]*rhs.m[0][3] + m[2][1]*rhs.m[1][3] + m[2][2]*rhs.m[2][3] + m[2][3]*rhs.m[3][3];

    result.v[count++] = m[3][0]*rhs.m[0][0] + m[3][1]*rhs.m[1][0] + m[3][2]*rhs.m[2][0] + m[3][3]*rhs.m[3][0];
    result.v[count++] = m[3][0]*rhs.m[0][1] + m[3][1]*rhs.m[1][1] + m[3][2]*rhs.m[2][1] + m[3][3]*rhs.m[3][1];
    result.v[count++] = m[3][0]*rhs.m[0][2] + m[3][1]*rhs.m[1][2] + m[3][2]*rhs.m[2][2] + m[3][3]*rhs.m[3][2];
    result.v[count++] = m[3][0]*rhs.m[0][3] + m[3][1]*rhs.m[1][3] + m[3][2]*rhs.m[2][3] + m[3][3]*rhs.m[3][3];

    return result;
}
// Similar to the three above except they modify the original
Matrix4& Matrix4::operator+=(const Matrix4& rhs)
{
    *this = *this + rhs;
    return *this;
}
Matrix4& Matrix4::operator-=(const Matrix4& rhs)
{
    *this = *this - rhs;
    return *this;
}
Matrix4& Matrix4::operator*=(const Matrix4& rhs)
{
    *this = *this * rhs;
    return *this;
}
// Scale/Divide the entire matrix by a float
Matrix4 Matrix4::operator*(const float rhs) const
{
    Matrix4 result;
    
    for(int i = 0; i <16; i++)
        result.v[i] = v[i] * rhs;
    
    return result;
}
Matrix4 Matrix4::operator/(const float rhs) const
{
    Matrix4 result;
    
    for(int i = 0; i <16; i++)
        result.v[i] = v[i] / rhs;
    
    return result;
}
// Same as previous
Matrix4& Matrix4::operator*=(const float rhs)
{
    *this = *this*rhs;
    return *this;
}
Matrix4& Matrix4::operator/=(const float rhs)
{
    *this = *this/rhs;
    return *this;
}
// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Matrix4::operator==(const Matrix4& rhs) const
{
    for(int i = 0; i<16;i++)
    {
        if(isEqual(v[i], rhs.v[i]) == false)
            return false;
    }
    return true;
}
bool Matrix4::operator!=(const Matrix4& rhs) const
{
    return !(*this == rhs);
}
// Zeroes out the entire matrix
void Matrix4::Zero(void)
{
    for(int i = 0; i < 16; i++)
        v[i] = 0;
}
// Builds the identity matrix
void Matrix4::Identity(void)
{
    Zero();
    for(int i = 0; i < 4; i++)
        m[i][i] = 1;
}
