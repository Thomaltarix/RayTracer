/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include "Point3D.hpp"
#include "MathError.hpp"
#include <cmath>

Math::Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Math::Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Math::Vector3D::Vector3D(const Math::Vector3D &vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
}

Math::Vector3D::Vector3D(const Math::Vector3D &&vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
}

Math::Vector3D &Math::Vector3D::operator=(const Math::Vector3D &vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
    return (*this);
}

Math::Vector3D &Math::Vector3D::operator=(const Math::Point3D &point3D)
{
    this->x = point3D.x;
    this->y = point3D.y;
    this->z = point3D.z;
    return (*this);
}

Math::Vector3D &Math::Vector3D::operator=(const Math::Vector3D &&vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &vector3D) const
{
    return Math::Vector3D(this->x + vector3D.x, this->y + vector3D.y,
        this->z + vector3D.z);
}

Math::Vector3D &Math::Vector3D::operator+=(const Math::Vector3D &vector3D)
{
    this->x += vector3D.x;
    this->y += vector3D.y;
    this->z += vector3D.z;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &vector3D) const
{
    return Math::Vector3D(this->x - vector3D.x, this->y - vector3D.y,
        this->z - vector3D.z);
}

Math::Vector3D Math::Vector3D::operator-(const Math::Point3D &point3D) const
{
    return Math::Vector3D(this->x - point3D.x, this->y - point3D.y,
        this->z - point3D.z);
}

Math::Vector3D &Math::Vector3D::operator-=(const Math::Vector3D &vector3D)
{
    this->x -= vector3D.x;
    this->y -= vector3D.y;
    this->z -= vector3D.z;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &vector3D) const
{
    return Math::Vector3D(this->x * vector3D.x, this->y * vector3D.y,
        this->z * vector3D.z);
}

Math::Vector3D Math::Vector3D::operator*(const double value) const
{
    return Math::Vector3D(this->x * value, this->y * value, this->z * value);
}

Math::Vector3D &Math::Vector3D::operator*=(const Math::Vector3D &vector3D)
{
    this->x *= vector3D.x;
    this->y *= vector3D.y;
    this->z *= vector3D.z;
    return (*this);
}

Math::Vector3D &Math::Vector3D::operator*=(const double value)
{
    this->x *= value;
    this->y *= value;
    this->z *= value;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &vector3D) const
{
    if (vector3D.x == 0 || vector3D.y == 0 || vector3D.z == 0)
        throw MathDivideByZeroError("Division by 0");
    return Math::Vector3D(this->x / vector3D.x, this->y / vector3D.y,
        this->z / vector3D.z);
}

Math::Vector3D Math::Vector3D::operator/(const double scalar) const
{
    if (scalar == 0)
        throw MathDivideByZeroError("Division by 0");
    return Math::Vector3D(this->x / scalar, this->y / scalar, this->z / scalar);
}

Math::Vector3D &Math::Vector3D::operator/=(const Math::Vector3D &vector3D)
{
    if (vector3D.x == 0 || vector3D.y == 0 || vector3D.z == 0)
        throw MathDivideByZeroError("Division by 0");
    this->x /= vector3D.x;
    this->y /= vector3D.y;
    this->z /= vector3D.z;
    return (*this);
}

double Math::Vector3D::dot(const Math::Vector3D &vector3D) const
{
    return this->x * vector3D.x + this->y * vector3D.y + this->z * vector3D.z;
}

double Math::Vector3D::Length() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Math::Vector3D Math::Vector3D::rotateX(double angle) const
{
    return Math::Vector3D(
        this->x, this->y * cos(angle) - this->z * sin(angle),
        this->y * sin(angle) + this->z * cos(angle));
}

Math::Vector3D Math::Vector3D::rotateY(double angle) const
{
    return Math::Vector3D(
        this->x * cos(angle) + this->z * sin(angle), this->y,
        -this->x * sin(angle) + this->z * cos(angle));
}

Math::Vector3D Math::Vector3D::rotateZ(double angle) const
{
    return Math::Vector3D(
        this->x * cos(angle) - this->y * sin(angle),
        this->x * sin(angle) + this->y * cos(angle), this->z);
}

Math::Vector3D Math::Vector3D::normalize() const
{
    double length = this->Length();
    if (length == 0)
        throw MathDivideByZeroError("Division by 0");
    return Math::Vector3D(this->x / length, this->y / length, this->z / length);
}