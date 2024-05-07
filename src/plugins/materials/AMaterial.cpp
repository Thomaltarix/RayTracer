/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.hpp"

RayTracer::AMaterial::AMaterial()
{
    _color = Math::Vector3D(128, 128, 128);
}

RayTracer::AMaterial::AMaterial(Math::Vector3D color)
{
    _color = color;
}

Math::Vector3D RayTracer::AMaterial::compute()
{
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
