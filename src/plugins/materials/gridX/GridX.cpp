/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "GridX.hpp"
#include <cmath>

Material::GridX::GridX() : AMaterial(), _color2(Math::Vector3D(0, 0, 0)) {}

Material::GridX::GridX(Math::Vector3D color1, Math::Vector3D color2) : AMaterial(color1), _color2(color2) {}

Math::Vector3D Material::GridX::compute(Math::Point3D point)
{
    if (point.x < 0)
        point.x = -point.x + 1;
    int dx = (int)(point.x) % 2;

    if (dx != 0)
        return _color;
    return _color2;
}

void Material::GridX::setColor(Math::Vector3D color)
{
    _color = color;
    _color2 = Math::Vector3D(color.x * 0.5, color.y * 0.5, color.z * 0.5);
}
