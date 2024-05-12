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
    _doesShadowcast = false;
}

RayTracer::ALight::ALight(float intensity)
{
    _intensity = intensity;
    _doesShadowcast = false;
}

RayTracer::ALight::ALight(float intensity, bool doesShadowcast)
{
    _intensity = intensity;
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

    return Math::Vector3D(color.x * _intensity, color.y * _intensity, color.z * _intensity);
}

bool RayTracer::ALight::InShadow(Math::Point3D point)
{
    (void)point;

    return false;
}
