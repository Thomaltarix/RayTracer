/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"
#include "MathError.hpp"

Math::Point3D Math::Rectangle3D::pointAt(double u, double v) const
{
    if (u < 0 || u > 1 || v < 0 || v > 1) {
        throw Math::MathError("u and v must be between 0 and 1");
    }
    return origin + width * u + height * v;
}
