/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Point3D
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "MathError.hpp"
#include <cmath>

Math::Point3D::Point3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Math::Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Math::Point3D::Point3D(const Math::Point3D &point3D)
{
    this->x = point3D.x;
    this->y = point3D.y;
    this->z = point3D.z;
}

Math::Point3D::Point3D(const Math::Point3D &&point3D)
{
    this->x = point3D.x;
    this->y = point3D.y;
    this->z = point3D.z;
}

Math::Point3D &Math::Point3D::operator=(const Math::Point3D &point3D)
{
    this->x = point3D.x;
    this->y = point3D.y;
    this->z = point3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator=(const Math::Vector3D &vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator=(const Math::Point3D &&point3D)
{
    this->x = point3D.x;
    this->y = point3D.y;
    this->z = point3D.z;
    return (*this);
}

Math::Point3D Math::Point3D::operator+(const Math::Point3D &point3D) const
{
    return Math::Point3D(this->x + point3D.x, this->y + point3D.y,
        this->z + point3D.z);
}

Math::Point3D Math::Point3D::operator+(const double &value) const
{
    return Math::Point3D(this->x + value, this->y + value, this->z + value);
}

Math::Point3D Math::Point3D::operator+(const Math::Vector3D &vector3D) const
{
    return Math::Point3D(this->x + vector3D.x, this->y + vector3D.y, this->z + vector3D.z);
}

Math::Point3D &Math::Point3D::operator+=(const Math::Point3D &point3D)
{
    this->x += point3D.x;
    this->y += point3D.y;
    this->z += point3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator+=(const double &value)
{
    this->x += value;
    this->y += value;
    this->z += value;
    return (*this);
}

Math::Point3D &Math::Point3D::operator+=(const Math::Vector3D &vector3D)
{
    this->x += vector3D.x;
    this->y += vector3D.y;
    this->z += vector3D.z;
    return (*this);
}

Math::Point3D Math::Point3D::operator-(const Math::Point3D &point3D) const
{
    return Math::Point3D(this->x - point3D.x, this->y - point3D.y,
        this->z - point3D.z);
}

Math::Point3D Math::Point3D::operator-(const double &value) const
{
    return Math::Point3D(this->x - value, this->y - value, this->z - value);
}

Math::Point3D Math::Point3D::operator-(const Math::Vector3D &vector3D) const
{
    return Math::Point3D(this->x - vector3D.x, this->y - vector3D.y, this->z - vector3D.z);
}

Math::Point3D &Math::Point3D::operator-=(const Math::Point3D &point3D)
{
    this->x -= point3D.x;
    this->y -= point3D.y;
    this->z -= point3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator-=(const double &value)
{
    this->x -= value;
    this->y -= value;
    this->z -= value;
    return (*this);
}

Math::Point3D &Math::Point3D::operator-=(const Math::Vector3D &vector3D)
{
    this->x -= vector3D.x;
    this->y -= vector3D.y;
    this->z -= vector3D.z;
    return (*this);
}

Math::Point3D Math::Point3D::operator*(const Math::Point3D &point3D) const
{
    return Math::Point3D(this->x * point3D.x, this->y * point3D.y,
        this->z * point3D.z);
}

Math::Point3D Math::Point3D::operator*(const double &value) const
{
    return Math::Point3D(this->x * value, this->y * value, this->z * value);
}

Math::Point3D &Math::Point3D::operator*=(const Math::Point3D &point3D)
{
    this->x *= point3D.x;
    this->y *= point3D.y;
    this->z *= point3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator*=(const double &value)
{
    this->x *= value;
    this->y *= value;
    this->z *= value;
    return (*this);
}

Math::Point3D Math::Point3D::operator/(const Math::Point3D &point3D) const
{
    if (point3D.x == 0 || point3D.y == 0 || point3D.z == 0)
        throw Math::MathDivideByZeroError("Division by 0");
    return Math::Point3D(this->x / point3D.x, this->y / point3D.y,
        this->z / point3D.z);
}

Math::Point3D Math::Point3D::operator/(const double &value) const
{
    if (value == 0)
        throw Math::MathDivideByZeroError("Division by 0");
    return Math::Point3D(this->x / value, this->y / value, this->z / value);
}

Math::Point3D &Math::Point3D::operator/=(const Math::Point3D &point3D)
{
    if (point3D.x == 0 || point3D.y == 0 || point3D.z == 0)
        throw Math::MathDivideByZeroError("Division by 0");
    this->x /= point3D.x;
    this->y /= point3D.y;
    this->z /= point3D.z;
    return (*this);
}

Math::Point3D &Math::Point3D::operator/=(const double &value)
{
    if (value == 0)
        throw Math::MathDivideByZeroError("Division by 0");
    this->x /= value;
    this->y /= value;
    this->z /= value;
    return (*this);
}

double Math::Point3D::distance(const Math::Point3D &point3D) const
{
    return sqrt(pow(this->x - point3D.x, 2) + pow(this->y - point3D.y, 2) +
        pow(this->z - point3D.z, 2));
}

void Math::Point3D::rotate(const Math::Vector3D &rotation)
{
    double x = -rotation.x * M_PI / 180.0;
    double y = -rotation.y * M_PI / 180.0;
    double z = -rotation.z * M_PI / 180.0;
    double cosX = cos(x);
    double sinX = sin(x);
    double cosY = cos(y);
    double sinY = sin(y);
    double cosZ = cos(z);
    double sinZ = sin(z);

    Math::Point3D rotatedPoint;
    rotatedPoint.x = this->x * cosY * cosZ + this->y * (cosZ * sinX * sinY - cosX * sinZ) + this->z * (sinX * sinZ + cosX * cosZ * sinY);
    rotatedPoint.y = this->x * cosY * sinZ + this->y * (cosX * cosZ + sinX * sinY * sinZ) + this->z * (cosX * sinY * sinZ - cosZ * sinX);
    rotatedPoint.z = this->x * -sinY + this->y * cosY * sinX + this->z * cosX * cosY;

    this->x = rotatedPoint.x;
    this->y = rotatedPoint.y;
    this->z = rotatedPoint.z;
}

double Math::Point3D::dot(const Math::Vector3D &vector3D) const
{
    return this->x * vector3D.x + this->y * vector3D.y + this->z * vector3D.z;
}


bool Math::Point3D::operator==(const Math::Point3D &point3D) const
{
    return this->x == point3D.x && this->y == point3D.y && this->z == point3D.z;
}

bool Math::Point3D::operator!=(const Math::Point3D &point3D) const
{
    return this->x != point3D.x || this->y != point3D.y || this->z != point3D.z;
}
