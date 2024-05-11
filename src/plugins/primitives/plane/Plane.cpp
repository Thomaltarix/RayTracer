/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** plane
*/

#include "Plane.hpp"
#include "math/DegToRad.hpp"

Primitive::Plane::Plane() : APrimitive()
{
    RayTracer::Axis3D x_axis = RayTracer::Axis3D();
    _axis = x_axis.getVector();
}

Primitive::Plane::Plane(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis) : APrimitive(pos, material)
{
    _axis = axis.getVector();
}

Primitive::Plane::Plane(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const Math::Vector3D &axis) : APrimitive(pos, material)
{
    _axis = axis;
}

Primitive::Plane::Plane(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis) : APrimitive(x, y, z, material)
{
    _axis = axis.getVector();
}

Primitive::Plane::Plane(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const Math::Vector3D &axis) : APrimitive(x, y, z, material)
{
    _axis = axis;
}

bool Primitive::Plane::hits(const Math::Ray &ray)
{
    double coef = 0;

    coef = (_pos - ray.getOrigin()).dot(_axis) / ray.getDirection().dot(_axis);
    if (coef < 0)
        return false;
    return true;
}

Math::Point3D Primitive::Plane::hitPoint(const Math::Ray &ray)
{
    double coef = 0;

    coef = (_pos - ray.getOrigin()).dot(_axis) / ray.getDirection().dot(_axis);
    return ray.getOrigin() + ray.getDirection() * coef;
}

Math::Vector3D Primitive::Plane::getNormalAt(const Math::Point3D &point)
{
    (void) point;
    return _axis;
}

void Primitive::Plane::translate(double x, double y, double z)
{
    _pos.x += x;
    _pos.y += y;
    _pos.z += z;
}

void Primitive::Plane::translate(const Math::Vector3D &vec)
{
    _pos.x += vec.x;
    _pos.y += vec.y;
    _pos.z += vec.z;
}

void Primitive::Plane::scale(double multiplier)
{
    (void) multiplier;
}

void Primitive::Plane::rotate(const RayTracer::Axis3D &axis, double angle)
{
    double radAngle = Math::degToRad(angle);

    switch (axis.getAxis())
    {
        case RayTracer::Axis::X:
            _axis = _axis.rotateX(radAngle);
            break;
        case RayTracer::Axis::Y:
            _axis = _axis.rotateY(radAngle);
            break;
        case RayTracer::Axis::Z:
            _axis = _axis.rotateZ(radAngle);
            break;
        default:
            break;
    }
}
