/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
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
    return Math::Vector3D(this->x / vector3D.x, this->y / vector3D.y,
        this->z / vector3D.z);
}

Math::Vector3D &Math::Vector3D::operator/=(const Math::Vector3D &vector3D)
{
    this->x /= vector3D.x;
    this->y /= vector3D.y;
    this->z /= vector3D.z;
    return (*this);
}

double Math::Vector3D::DotProduct(const Math::Vector3D &vector3D) const
{
    return this->x * vector3D.x + this->y * vector3D.y + this->z * vector3D.z;
}

double Math::Vector3D::Length() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
