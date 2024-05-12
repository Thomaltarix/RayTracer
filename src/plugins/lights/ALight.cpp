/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ALight.cpp
*/

#include "ALight.hpp"

RayTracer::ALight::ALight()
{
    _intensity = 1.0f;
    _color = Math::Vector3D(255, 255, 255);
    _doesShadowcast = false;
}

RayTracer::ALight::ALight(float intensity)
{
    _intensity = intensity;
    _color = Math::Vector3D(255, 255, 255);
    _doesShadowcast = false;
}

RayTracer::ALight::ALight(float intensity, Math::Vector3D color, bool doesShadowcast)
{
    _intensity = intensity;
    _color = color;
    _doesShadowcast = doesShadowcast;
}

float RayTracer::ALight::getIntensity() const
{
    return _intensity;
}

void RayTracer::ALight::setIntensity(float intensity)
{
    _intensity = intensity;
}

bool RayTracer::ALight::doesShadowcast() const
{
    return _doesShadowcast;
}

void RayTracer::ALight::setShadowcast(bool doesShadowcast)
{
    _doesShadowcast = doesShadowcast;
}

Math::Vector3D RayTracer::ALight::Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material,
    const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives, Math::Vector3D normal)
{
    Math::Vector3D color = material->compute(point);
    (void)point;
    (void)primitives;
    (void)normal;

    return Math::Vector3D(color.x * _intensity * _color.x / 255,
        color.y * _intensity * _color.y / 255, color.z * _intensity * _color.z / 255);
}
