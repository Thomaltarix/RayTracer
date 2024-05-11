/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "Grid.hpp"
#include <cmath>

Material::Grid::Grid() : AMaterial(), _color2(Math::Vector3D(0, 0, 0)) {}

Material::Grid::Grid(Math::Vector3D color1) : AMaterial(color1)
{
    _color2 = Math::Vector3D(color1.x + 0.5, color1.y + 0.5, color1.z + 0.5);
}

Math::Vector3D Material::Grid::compute(Math::Point3D point)
{
    if (point.x < 0)
        point.x = -point.x + 1;
    if (point.y < 0)
        point.y = -point.y + 1;
    if (point.z < 0)
        point.z = -point.z + 1;
    int dx = (int)(point.x) % 2;
    int dy = (int)(point.y) % 2;
    int dz = (int)(point.z) % 2;
    int sum = dx + dy + dz;

    if (sum != 3 && sum != 0)
        return _color;
    return _color2;
}

void Material::Grid::setColor(Math::Vector3D color)
{
    _color = color;
    _color2 = Math::Vector3D(color.x * 0.5, color.y * 0.5, color.z * 0.5);
}
