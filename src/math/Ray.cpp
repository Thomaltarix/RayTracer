/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ray
*/

#include "Ray.hpp"

Math::Ray::Ray()
{
    _origin = Math::Vector3D();
    _direction = Math::Vector3D();
}

Math::Ray::Ray(const Math::Vector3D &origin, const Math::Vector3D &direction)
{
    _origin = origin;
    _direction = direction;
}

Math::Ray::Ray(const Math::Ray &ray)
{
    _origin = ray.getOrigin();
    _direction = ray.getDirection();
}

Math::Ray::Ray(const Math::Ray &&ray)
{
    _origin = ray.getOrigin();
    _direction = ray.getDirection();
}

Math::Ray &Math::Ray::operator=(const Math::Ray &ray)
{
    _origin = ray.getOrigin();
    _direction = ray.getDirection();
    return (*this);
}

Math::Ray &Math::Ray::operator=(const Math::Ray &&ray)
{
    _origin = ray.getOrigin();
    _direction = ray.getDirection();
    return (*this);
}

Math::Vector3D Math::Ray::getOrigin() const
{
    return _origin;
}

Math::Vector3D Math::Ray::getDirection() const
{
    return _direction;
}
