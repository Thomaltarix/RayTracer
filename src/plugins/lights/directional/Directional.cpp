/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Directional.cpp
*/

#include "Directional.hpp"

Light::Directional::Directional() : ALight()
{
    _direction = Math::Vector3D(0, 0, 0);
}

Light::Directional::Directional(float intensity) : ALight(intensity)
{
    _direction = Math::Vector3D(0, 0, 0);
}

Light::Directional::Directional(float intensity, Math::Vector3D direction) : ALight(intensity)
{
    _direction = direction;
}

Light::Directional::Directional(Math::Vector3D direction) : ALight()
{
    _direction = direction;
}

Math::Vector3D Light::Directional::getDirection() const
{
    return _direction;
}

void Light::Directional::setDirection(Math::Vector3D direction)
{
    _direction = direction;
}

bool Light::Directional::InShadow(Math::Point3D point)
{
    (void)point;
    return false;
}

#include <iostream>

Math::Vector3D Light::Directional::Illuminate(Math::Point3D point, const std::shared_ptr<RayTracer::IMaterial> &material,
    const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives)
{
    Math::Vector3D color = material->compute();
    Math::Ray lightRay = Math::Ray(point, _direction);

    for (auto &primitive : primitives) {
        if (primitive->hits(lightRay)) {
            //if (primitive->hitPoint(lightRay) != point)
            //    return Math::Vector3D(0, 0, 0);
            try {
                if (primitive->hitPoint(lightRay) != point)
                    return Math::Vector3D(0, 0, 0);
            } catch (const std::exception &e) {
                return Math::Vector3D(0, 0, 0);
            }
        }
    }
    return Math::Vector3D(color.x * _intensity, color.y * _intensity, color.z * _intensity);
}
