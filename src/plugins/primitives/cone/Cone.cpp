/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "Cone.hpp"
#include "math/QuadraticEquation.hpp"
#include "math/MathError.hpp"
#include "math/DegToRad.hpp"
#include <cmath>

Primitive::Cone::Cone() : APrimitive() {}

Primitive::Cone::Cone(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material,
     const RayTracer::Axis3D &axis, double angle) : APrimitive(pos, material)
{
    _angle = angle;
    _axis = axis.getVector();
}

Primitive::Cone::Cone(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material,
     const RayTracer::Axis3D &axis, double angle) : APrimitive(x, y, z, material)
{
    _angle = angle;
    _axis = axis.getVector();
}

Primitive::Cone::Cone(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material,
     const Math::Vector3D &axis, double angle) : APrimitive(pos, material)
{
    _angle = angle;
    _axis = axis;
}

Primitive::Cone::Cone(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material,
     const Math::Vector3D &axis, double angle) : APrimitive(x, y, z, material)
{
    _angle = angle;
    _axis = axis;
}

bool Primitive::Cone::hits(const Math::Ray &ray)
{
    Math::Vector3D dir = ray.getDirection();
    Math::Vector3D oc;
    oc = ray.getOrigin() - _pos;

    double cos2 = cos(_angle) * cos(_angle);
    double sin2 = sin(_angle) * sin(_angle);

    double a = dir.dot(dir) * cos2 - pow(dir.dot(_axis), 2) * sin2;
    double b = 2 * (dir.dot(oc) * cos2 - dir.dot(_axis) * oc.dot(_axis) * sin2);
    double c = oc.dot(oc) * cos2 - pow(oc.dot(_axis), 2) * sin2;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;
    return true;

}

Math::Point3D Primitive::Cone::hitPoint(const Math::Ray &ray)
{
    Math::Vector3D dir = ray.getDirection();
    Math::Vector3D oc;
    oc = ray.getOrigin() - _pos;

    double cos2 = cos(_angle) * cos(_angle);
    double sin2 = sin(_angle) * sin(_angle);

    double a = dir.dot(dir) * cos2 - pow(dir.dot(_axis), 2) * sin2;
    double b = 2 * (dir.dot(oc) * cos2 - dir.dot(_axis) * oc.dot(_axis) * sin2);
    double c = oc.dot(oc) * cos2 - pow(oc.dot(_axis), 2) * sin2;
    double x0, x1;
    if (!Math::solveQuadraticEquation(a, b, c, x0, x1)) {
        throw Math::MathNoSolutionError("No intersection with cone");
    }
    if (x0 < 0 && x1 < 0) {
        throw Math::MathNoSolutionError("No intersection with cone");
    }
    return ray.getOrigin() + ray.getDirection() * std::min(x0, x1);
}

Math::Vector3D Primitive::Cone::getNormalAt(const Math::Point3D &point)
{
    Math::Vector3D PC;
    PC = point - _pos;
    double cos2 = cos(_angle) * cos(_angle);
    Math::Vector3D normal = PC - (_axis * PC.dot(_axis) * cos2);

    return normal;
}

void Primitive::Cone::translate(double x, double y, double z)
{
    _pos.x += x;
    _pos.y += y;
    _pos.z += z;
}

void Primitive::Cone::translate(const Math::Vector3D &vec)
{
    _pos.x += vec.x;
    _pos.y += vec.y;
    _pos.z += vec.z;
}

void Primitive::Cone::rotate(const Math::Vector3D &axis, double angle)
{
    double radAngle = Math::degToRad(angle);

    _axis = _axis.rotate(axis, radAngle);
}

void Primitive::Cone::rotate(const RayTracer::Axis3D &axis, double angle)
{
    double radAngle = Math::degToRad(angle);

    _axis = _axis.rotate(axis.getVector(), radAngle);
}
