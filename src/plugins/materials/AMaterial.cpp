/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** AMaterial.cpp
*/

#include "AMaterial.cpp"

AMaterial::AMaterial()
{
    _color = Math::Vector3D(0, 0, 0);
}

AMaterial::AMaterial(Math::Vector3D color)
{
    _color = color;
}

AMaterial::~AMaterial() {}

Math::Vector3D AMaterial::compute()
{
    return _color;
}

Math::Vector3D AMaterial::getColor() const
{
    return _color;
}

void AMaterial::setColor(Math::Vector3D color)
{
    _color = color;
}
