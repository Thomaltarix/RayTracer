/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

RayTracer::APrimitive::APrimitive()
{
    _pos = Math::Point3D(0, 0, 0);
}

void RayTracer::APrimitive::setPos(float x, float y, float z)
{
    _pos = Math::Point3D(x, y, z);
}

void RayTracer::APrimitive::setPos(Math::Point3D point)
{
    _pos = point;
}

void RayTracer::APrimitive::setMaterial(std::shared_ptr<IMaterial> material)
{
    _material = material;
}
