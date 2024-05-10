/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "core/Camera.hpp"
#include <cmath>
#include <iostream>

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

Math::Point3D rotatePoint(const Math::Point3D& point, const Math::Vector3D& rotation) {
    double x = -rotation.x * M_PI / 180.0;
    double y = -rotation.y * M_PI / 180.0;
    double z = -rotation.z * M_PI / 180.0;
    double cosX = cos(x);
    double sinX = sin(x);
    double cosY = cos(y);
    double sinY = sin(y);
    double cosZ = cos(z);
    double sinZ = sin(z);

    Math::Point3D rotatedPoint;
    rotatedPoint.x = point.x * cosY * cosZ + point.y * (cosZ * sinX * sinY - cosX * sinZ) + point.z * (sinX * sinZ + cosX * cosZ * sinY);
    rotatedPoint.y = point.x * cosY * sinZ + point.y * (cosX * cosZ + sinX * sinY * sinZ) + point.z * (cosX * sinY * sinZ - cosZ * sinX);
    rotatedPoint.z = point.x * -sinY + point.y * cosY * sinX + point.z * cosX * cosY;

    return rotatedPoint;
}

RayTracer::Camera::Camera(const Math::Point3D &origin, const Math::Vector3D &rotation, std::size_t width, std::size_t height, double fov)
{
    _origin = origin;
    _width = width;
    _height = height;
    double aspectRatio = (double)width / (double)height;
    std::cout << "Aspect ratio: " << aspectRatio << std::endl;

    double fovRad = fov * M_PI / 180.0;
    double screenHeight = 2.0 * tan(fovRad / 2.0);
    double screenWidth = aspectRatio * screenHeight;

    Math::Point3D bottomLeft = Math::Point3D((-1 * screenWidth) / 2, 1, (-1 * screenHeight) / 2) + origin;
    Math::Point3D right = Math::Point3D(screenWidth, 0, 0);
    Math::Point3D up = Math::Point3D(0, 0, screenHeight);

    bottomLeft = rotatePoint(bottomLeft - origin, rotation) + origin;
    right = rotatePoint(right, rotation);
    up = rotatePoint(up, rotation);

    Math::Vector3D right_vector = Math::Vector3D(right.x, right.y, right.z);
    Math::Vector3D up_vector = Math::Vector3D(up.x, up.y, up.z);

    _screen = Math::Rectangle3D(bottomLeft, right_vector, up_vector);
}

Math::Ray RayTracer::Camera::ray(double u, double v) const
{
    Math::Point3D screenPoint = _screen.pointAt(u, v);
    Math::Vector3D direction = {screenPoint.x - _origin.x, screenPoint.y - _origin.y, screenPoint.z - _origin.z};
    return {_origin, direction};
}
