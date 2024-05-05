/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "Camera.hpp"

RayTracer::Camera::Camera()
{
    origin = Math::Point3D();
    screen = Math::Rectangle3D(Math::Point3D(-0.5, -0.5, 1), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 1, 0));
}

RayTracer::Camera::Camera(const Math::Point3D &origin, const Math::Rectangle3D &screen)
{
    this->origin = origin;
    this->screen = screen;
}

Math::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPoint = screen.pointAt(u, v);
    Math::Vector3D direction = {screenPoint.x - origin.x, screenPoint.y - origin.y, screenPoint.z - origin.z};
    return {origin, direction};
}
