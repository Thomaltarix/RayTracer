/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** 3DAxis
*/

#include "3DAxis.hpp"

RayTracer::Axis3D::Axis3D(Axis axis)
{
    _axis = axis;
}

RayTracer::Axis RayTracer::Axis3D::getAxis() const
{
    return _axis;
}

void RayTracer::Axis3D::setAxis(RayTracer::Axis axis)
{
    _axis = axis;
}
