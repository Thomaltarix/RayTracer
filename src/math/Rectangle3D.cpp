/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"
#include "MathError.hpp"

Math::Rectangle3D::Rectangle3D() : origin(Math::Point3D()), width(Math::Vector3D(1, 0, 0)), height(Math::Vector3D(0, 1, 0)) {}

Math::Rectangle3D::Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &width, const Math::Vector3D &height)
    : origin(origin), width(width), height(height) {}

Math::Point3D Math::Rectangle3D::pointAt(double u, double v) const
{
    if (u < 0 || u > 1 || v < 0 || v > 1) {
        throw Math::MathError("u and v must be between 0 and 1");
    }
    return origin + width * u + height * v;
}
