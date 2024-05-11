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

Math::Vector3D RayTracer::Axis3D::getVector() const
{
    switch (_axis) {
        case Axis::X:
            return Math::Vector3D(1, 0, 0);
        case Axis::Y:
            return Math::Vector3D(0, 1, 0);
        case Axis::Z:
            return Math::Vector3D(0, 0, 1);
    }
    return Math::Vector3D();
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
