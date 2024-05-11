/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include "math/MathError.hpp"
#include "math/DegToRad.hpp"
#include <cmath>

Primitive::Cylinder::Cylinder() : APrimitive() {}

Primitive::Cylinder::Cylinder(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis, double radius) : APrimitive(pos, material), _radius(radius)
{
    _axis = axis.getVector();
}

Primitive::Cylinder::Cylinder(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material, const Math::Vector3D &axis, double radius)
    : APrimitive(pos, material),  _axis(axis), _radius(radius) {}

Primitive::Cylinder::Cylinder(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const RayTracer::Axis3D &axis, double radius) : APrimitive(x, y, z, material), _radius(radius)
{
    _axis = axis.getVector();
}

Primitive::Cylinder::Cylinder(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material, const Math::Vector3D &axis, double radius)
    : APrimitive(x, y, z, material),  _axis(axis), _radius(radius) {}

bool Primitive::Cylinder::hits(const Math::Ray &ray)
{
    std::pair<double, double> points = getIntersectionPoints(ray);

    return (points.first >= 0 || points.second >= 0);
}

Math::Point3D Primitive::Cylinder::hitPoint(const Math::Ray &ray)
{
    std::pair<double, double> points = getIntersectionPoints(ray);

    if (points.first < 0 && points.second < 0)
        throw Math::MathNoSolutionError("No intersection with sphere");
    return ray.getOrigin() + ray.getDirection() * std::min(points.first, points.second);
}

Math::Vector3D Primitive::Cylinder::getNormalAt(const Math::Point3D &point)
{
    Math::Point3D tmp = point - _pos;
    tmp = tmp - _axis * tmp.dot(_axis);
    Math::Vector3D normal;
    normal.x = tmp.x;
    normal.y = tmp.y;
    normal.z = tmp.z;
    return normal.normalize();
}

void Primitive::Cylinder::translate(const Math::Vector3D &vec)
{
    _pos += vec;
}

void Primitive::Cylinder::translate(double x, double y, double z)
{
    _pos.x += x;
    _pos.y += y;
    _pos.z += z;
}

void Primitive::Cylinder::scale(double factor)
{
    _radius *= factor;
}

void Primitive::Cylinder::rotate(const Math::Vector3D &vec, double angle)
{
    double radAngle = Math::degToRad(angle);

    _axis = _axis.rotate(vec, radAngle);
}

void Primitive::Cylinder::rotate(const RayTracer::Axis3D &axis, double angle)
{
    double radAngle = Math::degToRad(angle);

    _axis = _axis.rotate(axis.getVector(), radAngle);
}

std::pair<double, double> Primitive::Cylinder::getIntersectionPoints(const Math::Ray &ray)
{
    Math::Point3D pos = ray.getOrigin();
    Math::Vector3D dir = ray.getDirection();

    // Compute the parameters for the ray-cylinder intersection
    Math::Vector3D oc;
    oc = ray.getOrigin() - _pos;
    double a = dir.dot(dir) - pow(dir.dot(_axis), 2);
    double b = 2 * (oc.dot(dir) - oc.dot(_axis) * dir.dot(_axis));
    double c = oc.dot(oc) - pow(oc.dot(_axis), 2) - pow(_radius, 2);

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
