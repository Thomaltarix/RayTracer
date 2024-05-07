/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Directional.hpp
*/

#pragma once

#include "ALight.hpp"

namespace Light {
    class Directional : public ALight {
    public:
        Directional();
        Directional(float intensity);
        Directional(float intensity, RayTracer::Vector3 direction);
        Directional(RayTracer::Vector3 direction);
        ~Directional() = default;

        RayTracer::Vector3 getDirection() const;
        void setDirection(RayTracer::Vector3 direction);
        bool InShadow(Math::Point3D point) override;
        Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material) override;
    private:
        RayTracer::Vector3 _direction;
    };
}