/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "Rectangle3D.hpp"
#include "MathError.hpp"

Math::Point3D Rectangle3D::pointAt(double u, double v) const
{
    if (u < 0 || u > 1 || v < 0 || v > 1) {
        throw Math::MathError("u and v must be between 0 and 1");
    }
    return origin + width * u + height * v;
}
