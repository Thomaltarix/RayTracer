/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** 3DAxis
*/

#include "3DAxis.hpp"

RayTracer::Axis3D::Axis3D()
{
    _axis = RayTracer::Axis::X;
}

RayTracer::Axis3D::Axis3D(RayTracer::Axis axis)
{
    _axis = axis;
}

RayTracer::Axis RayTracer::Axis3D::GetAxis() const
{
    return _axis;
}

void RayTracer::Axis3D::SetAxis(RayTracer::Axis axis)
{
    _axis = axis;
}


