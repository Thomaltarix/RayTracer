/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** plane
*/

#include "Plane.hpp"

Primitive::Plane::Plane() : APrimitive()
{
    _axis = RayTracer::Axis3D();
}

Primitive::Plane::Plane(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis) : APrimitive(pos, material)
{
    _axis = axis;
}

Primitive::Plane::Plane(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis) : APrimitive(x, y, z, material)
{
    _axis = axis;
}

bool Primitive::Plane::hits(const Math::Ray &ray)
{
    double coef = 0;

    switch (_axis.getAxis()) {
        case RayTracer::Axis::X:
            coef = (_pos.x - ray.getOrigin().x) / ray.getDirection().x;
            break;
        case RayTracer::Axis::Y:
            coef = (_pos.y - ray.getOrigin().y) / ray.getDirection().y;
            break;
        case RayTracer::Axis::Z:
            coef = (_pos.z - ray.getOrigin().z) / ray.getDirection().z;
            break;
    }
    if (coef < 0)
        return false;
    return true;
}

Math::Vector3D Primitive::Plane::getNormalAt(const Math::Point3D &point)
{
    (void) point;
    Math::Vector3D normal = Math::Vector3D(0, 0, 0);

    switch (_axis.getAxis()) {
        case RayTracer::Axis::X:
            normal = Math::Vector3D(1, 0, 0);
            break;
        case RayTracer::Axis::Y:
            normal = Math::Vector3D(0, 1, 0);
            break;
        case RayTracer::Axis::Z:
            normal = Math::Vector3D(0, 0, 1);
            break;
    }
    return normal;
}
