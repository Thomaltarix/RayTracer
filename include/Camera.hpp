/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "Ray.hpp"
#include "Rectangle3D.hpp"

namespace RayTracer {
    class Camera {
    public:
        Math::Point3D origin;
        Math::Rectangle3D screen;

        Camera();
        Camera(const Math::Point3D &origin, const Math::Rectangle3D &screen);
        ~Camera() = default;

        [[nodiscard]] Math::Ray ray(double u, double v) const;
    };
}
