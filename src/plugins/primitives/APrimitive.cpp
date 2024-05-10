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
    _material = nullptr;
}

RayTracer::APrimitive::APrimitive(const Math::Point3D &pos, const std::shared_ptr<IMaterial> &material)
{
    _pos = pos;
    _material = material;
}

RayTracer::APrimitive::APrimitive(double x, double y, double z, const std::shared_ptr<IMaterial> &material)
{
    _pos = Math::Point3D(x, y, z);
    _material = material;
}

RayTracer::APrimitive::~APrimitive()
{
    _material = nullptr;
}

void RayTracer::APrimitive::setPos(double x, double y, double z)
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

Math::Point3D RayTracer::APrimitive::getPos()
{
    return _pos;
}

std::shared_ptr<RayTracer::IMaterial> RayTracer::APrimitive::getMaterial()
{
    return _material;
}

bool RayTracer::APrimitive::hits(const Math::Ray &ray)
{
    return false;
}

Math::Point3D RayTracer::APrimitive::hitPoint(const Math::Ray &ray)
{
    return Math::Point3D(0, 0, 0);
}

Math::Vector3D RayTracer::APrimitive::getNormalAt(const Math::Point3D &point)
{
    return Math::Vector3D(0, 0, 0);
}
