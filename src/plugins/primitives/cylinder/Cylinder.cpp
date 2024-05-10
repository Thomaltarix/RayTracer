/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <cmath>

Primitive::Cylinder::Cylinder() : APrimitive() {}

Primitive::Cylinder::Cylinder(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis, double radius)
    : APrimitive(pos, material), _axis(axis), _radius(radius) {}

Primitive::Cylinder::Cylinder(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis, double radius)
    : APrimitive(x, y, z, material), _axis(axis), _radius(radius) {}

bool Primitive::Cylinder::hits(const Math::Ray &ray)
{
    std::pair<double, double> points = getIntersectionPoints(ray);

    return (points.first >= 0 && points.first <= 1) || (points.second >= 0 && points.second <= 1);
}

Math::Point3D Primitive::Cylinder::hitPoint(const Math::Ray &ray)
{
    std::pair<double, double> points = getIntersectionPoints(ray);

    if (points.first >= 0 && points.first <= 1)
        return _pos + ray.getDirection() * points.first;
    if (points.second >= 0 && points.second <= 1)
        return _pos + ray.getDirection() * points.second;
    return Math::Point3D();
}

Math::Vector3D Primitive::Cylinder::getNormalAt(const Math::Point3D &point)
{
    if (_axis.getAxis() == RayTracer::Axis::X)
        return Math::Vector3D(0, point.y - _pos.y, point.z - _pos.z) / _radius;
    if (_axis.getAxis() == RayTracer::Axis::Y)
        return Math::Vector3D(point.x - _pos.x, 0, point.z - _pos.z) / _radius;
    if (_axis.getAxis() == RayTracer::Axis::Z)
        return Math::Vector3D(point.x - _pos.x, point.y - _pos.y, 0) / _radius;
    return Math::Vector3D();
}

std::pair<double, double> Primitive::Cylinder::getIntersectionPoints(const Math::Ray &ray)
{
    Math::Point3D pos = ray.getOrigin();
    Math::Vector3D dir = ray.getDirection();
    Math::Vector3D axis = _axis.getVector();

    // Compute the parameters for the ray-cylinder intersection
    Math::Vector3D oc;
    oc = ray.getOrigin() - _pos;
    double a = dir.dot(dir) - pow(dir.dot(axis), 2);
    double b = 2 * (oc.dot(dir) - oc.dot(axis) * dir.dot(axis));
    double c = oc.dot(oc) - pow(oc.dot(axis), 2) - pow(_radius, 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    // Check if the ray intersects the cylinder
    if (discriminant >= 0) {
        // Compute the two possible intersection points
        double p1 = (-b - sqrt(discriminant)) / (2 * a);
        double p2 = (-b + sqrt(discriminant)) / (2 * a);

        return std::make_pair(p1, p2);
    }
    return std::make_pair(-1, -1);
}
