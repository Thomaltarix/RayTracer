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
    Math::Point3D pos = ray.getOrigin();
    Math::Vector3D dir = ray.getDirection();

    // Compute the parameters for the ray-cylinder intersection
    Math::Vector3D oc = pos - ray.getOrigin();
    double a = dir.dot(dir) - pow(dir.dot(_axis), 2);
    double b = 2 * (oc.dot(dir) - oc.dot(_axis) * dir.dot(_axis));
    double c = oc.dot(oc) - pow(oc.dot(_axis), 2) - pow(_radius, 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    // Check if the ray intersects the cylinder
    if (discriminant >= 0) {
        // Compute the two possible intersection points
        double p1 = (-b - sqrt(discriminant)) / (2 * a);
        double p2 = (-b + sqrt(discriminant)) / (2 * a);

        // Check if the intersection points are within the bounds of the cylinder
        if (p1 >= 0 && p1 <= 1) {
            return true;
        }
        if (p2 >= 0 && p2 <= 1) {
            return true;
        }
    }
    return false;
}

Math::Vector3D Primitive::Cylinder::getNormalAt(const Math::Point3D &point)
{
}