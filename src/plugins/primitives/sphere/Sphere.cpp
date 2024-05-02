/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** sphere
*/

#include "Sphere.hpp"

Primitive::Sphere::Sphere() : APrimitive()
{
    _radius = 0;
}

Primitive::Sphere::Sphere(const Math::Point3D &pos, double radius,
    const std::shared_ptr<RayTracer::IMaterial> &material) : APrimitive(pos, material)
{
    _radius = radius;
}

Primitive::Sphere::Sphere(double x, double y, double z, double radius,
    const std::shared_ptr<RayTracer::IMaterial> &material) : APrimitive(x, y, z, material)
{
    _radius = radius;
}

bool Primitive::Sphere::hits(const Math::Ray &ray)
{
    Math::Vector3D oc = ray.getOrigin() - getPos();
    float a = ray.getDirection().dot(ray.getDirection());
    float b = 2.0 * oc.dot(ray.getDirection());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;
    return true;
}

Math::Vector3D Primitive::Sphere::getNormalAt(const Math::Vector3D &point)
{
    Math::Point3D center = getPos();

    return Math::Vector3D((point.x  - center.x) / radius,
        (point.y - center.y) / radius,
        (point.z - center.z) / radius);
}
