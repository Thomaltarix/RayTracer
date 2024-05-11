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

std::ostream &operator<<(std::ostream &os, const RayTracer::Axis3D &axis)
{
    switch (axis.getAxis()) {
        case RayTracer::Axis::X:
            os << "X";
            break;
        case RayTracer::Axis::Y:
            os << "Y";
            break;
        case RayTracer::Axis::Z:
            os << "Z";
            break;
    }
    return os;
}
