/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

RayTracer::AMaterial::AMaterial()
{
    _color = Math::Vector3D(0, 0, 0);
    _reflectsLight = false;
}

RayTracer::AMaterial::AMaterial(Math::Vector3D color)
{
    _color = color;
    _reflectsLight = false;
}

Math::Vector3D RayTracer::AMaterial::compute(Math::Point3D point)
{
    (void)point;
    return _color;
}

Math::Vector3D RayTracer::AMaterial::getColor() const
{
    return _color;
}

void RayTracer::AMaterial::setColor(Math::Vector3D color)
{
    _color = color;
}

bool RayTracer::AMaterial::reflectsLight()
{
    return _reflectsLight;
}
