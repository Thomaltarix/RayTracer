/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ray
*/

#pragma once

#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace Math {
    class Ray {
    public:
        Ray();
        Ray(const Point3D &origin, const Vector3D &direction);
        Ray(const Ray &ray);
        Ray(const Ray &&ray);
        ~Ray() = default;

        Ray &operator=(const Ray &ray);
        Ray &operator=(const Ray &&ray);

        [[nodiscard]] Point3D getOrigin() const;
        [[nodiscard]] Vector3D getDirection() const;

    private:
        Point3D _origin;
        Vector3D _direction;
    };
}
