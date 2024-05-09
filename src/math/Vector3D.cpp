/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
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

Math::Vector3D &Math::Vector3D::operator*=(const Math::Vector3D &vector3D)
{
    this->x *= vector3D.x;
    this->y *= vector3D.y;
    this->z *= vector3D.z;
    return (*this);
}

Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &vector3D) const
{
    if (vector3D.x == 0 || vector3D.y == 0 || vector3D.z == 0)
        throw MathDivideByZeroError("Division by 0");
    return Math::Vector3D(this->x / vector3D.x, this->y / vector3D.y,
        this->z / vector3D.z);
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
