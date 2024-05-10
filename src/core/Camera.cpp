/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "core/Camera.hpp"
#include <cmath>

RayTracer::Camera::Camera()
{
    _origin = Math::Point3D();
    _screen = Math::Rectangle3D(Math::Point3D(-0.5, 1, -0.5), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 0, 1));
}

RayTracer::Camera::Camera(const Math::Point3D &origin, const Math::Rectangle3D &screen)
{
    _origin = origin;
    _screen = screen;
}

#include <iostream>

RayTracer::Camera::Camera(const Math::Point3D &origin, const Math::Vector3D &rotation, std::size_t width, std::size_t height, double fov)
{
    _origin = origin;
    _width = width;
    _height = height;
    double aspectRatio = (double)width / (double)height;
    std::cout << "Aspect ratio: " << aspectRatio << std::endl;
    _screen = Math::Rectangle3D(Math::Point3D((-1 * aspectRatio) / 2, 1, (-1 * (1 / aspectRatio)) / 2) + origin, Math::Vector3D(aspectRatio, 0, 0), Math::Vector3D(0, 0, 1 / aspectRatio));

}

Math::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPoint = _screen.pointAt(u, v);
    Math::Vector3D direction = {screenPoint.x - _origin.x, screenPoint.y - _origin.y, screenPoint.z - _origin.z};
    return {_origin, direction};
}
