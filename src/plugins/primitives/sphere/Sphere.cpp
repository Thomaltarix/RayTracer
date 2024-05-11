/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** sphere
*/

#include "Sphere.hpp"
#include "math/QuadraticEquation.hpp"
#include "math/MathError.hpp"

Primitive::Sphere::Sphere() : APrimitive()
{
    _radius = 1;
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
    Math::Vector3D oc;
    oc = ray.getOrigin() - getPos();
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;
    return true;
}

Math::Point3D Primitive::Sphere::hitPoint(const Math::Ray &ray)
{
    Math::Vector3D oc;
    double x0, x1;

    oc = ray.getOrigin() - getPos();
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - _radius * _radius;
    if (!Math::solveQuadraticEquation(a, b, c, x0, x1)) {
        throw Math::MathNoSolutionError("No intersection with sphere");
    }
    if (x0 < 0 && x1 < 0) {
        throw Math::MathNoSolutionError("No intersection with sphere");
    }
    return ray.getOrigin() + ray.getDirection() * std::min(x0, x1);
}

Math::Vector3D Primitive::Sphere::getNormalAt(const Math::Point3D &point)
{
    Math::Point3D center = getPos();

    return Math::Vector3D((point.x  - center.x) / _radius,
        (point.y - center.y) / _radius,
        (point.z - center.z) / _radius);
}

double Primitive::Sphere::getRadius() const
{
    return _radius;
}

void Primitive::Sphere::setRadius(double radius)
{
    _radius = radius;
}

void Primitive::Sphere::translate(double x, double y, double z)
{
    _pos.x += x;
    _pos.y += y;
    _pos.z += z;
}

void Primitive::Sphere::translate(const Math::Vector3D &vec)
{
    _pos.x += vec.x;
    _pos.y += vec.y;
    _pos.z += vec.z;
}

void Primitive::Sphere::scale(double multiplier)
{
    _radius *= multiplier;
}
