/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "GridZ.hpp"
#include <cmath>

Material::GridZ::GridZ() : AMaterial(), _color2(Math::Vector3D(0, 0, 0)) {}

Material::GridZ::GridZ(Math::Vector3D color1, Math::Vector3D color2) : AMaterial(color1), _color2(color2) {}

Math::Vector3D Material::GridZ::compute(Math::Point3D point)
{
    if (point.z < 0)
        point.z = -point.z + 1;
    int dz = (int)(point.z) % 2;

    if (dz != 0)
        return _color;
    return _color2;
}

void Material::GridZ::setColor(Math::Vector3D color)
{
    _color = color;
    _color2 = Math::Vector3D(color.x * 0.5, color.y * 0.5, color.z * 0.5);
}
