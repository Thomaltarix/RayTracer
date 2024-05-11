/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "GridY.hpp"
#include <cmath>

Material::GridY::GridY() : AMaterial(), _color2(Math::Vector3D(0, 0, 0)) {}

Material::GridY::GridY(Math::Vector3D color1, Math::Vector3D color2) : AMaterial(color1), _color2(color2) {}

Math::Vector3D Material::GridY::compute(Math::Point3D point)
{
    if (point.y < 0)
        point.y = -point.y + 1;
    int dy = (int)(point.y) % 2;

    if (dy != 0)
        return _color;
    return _color2;
}

void Material::GridY::setColor(Math::Vector3D color)
{
    _color = color;
    _color2 = Math::Vector3D(color.x * 0.5, color.y * 0.5, color.z * 0.5);
}
