/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Directional.hpp
*/

#pragma once

#include "ALight.hpp"

namespace Light {
    class Directional : public RayTracer::ALight {
    public:
        Directional();
        Directional(float intensity);
        Directional(float intensity, Math::Vector3D direction);
        Directional(Math::Vector3D direction);
        ~Directional() = default;

        Math::Vector3D getDirection() const;
        void setDirection(Math::Vector3D direction);
        bool InShadow(Math::Point3D point) override;
        Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<RayTracer::IMaterial> &material) override;
    private:
        Math::Vector3D _direction;
    };
}