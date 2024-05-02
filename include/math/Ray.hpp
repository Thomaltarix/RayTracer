/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ray
*/

#pragma once

#include "Vector3D.hpp"

namespace Math {
    class Ray {
    public:
        Ray();
        Ray(const Vector3D &origin, const Vector3D &direction);
        Ray(const Ray &ray);
        Ray(const Ray &&ray);
        ~Ray() = default;

        Ray &operator=(const Ray &ray);
        Ray &operator=(const Ray &&ray);

        Vector3D getOrigin() const;
        Vector3D getDirection() const;

    private:
        Vector3D _origin;
        Vector3D _direction;
    };
}
