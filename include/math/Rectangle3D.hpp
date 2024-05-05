/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Rectangle3D
*/

#pragma once

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Math {
    class Rectangle3D {
    public:
        Math::Point3D origin;
        Math::Vector3D width;
        Math::Vector3D height;

        Rectangle3D() : origin(), width(), height() {}
        Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &width, const Math::Vector3D &height) :
                origin(origin), width(width), height(height) {}
        ~Rectangle3D() = default;

        /**
         * @brief Get the point at the given u and v coordinates relative to the rectangle.
         * @param u The u coordinate (0 <= u <= 1) relative to the width of the rectangle.
         * @param v The v coordinate (0 <= v <= 1) relative to the height of the rectangle.
         * @return The point at the given u and v coordinates.
         * @throw MathError if u or v are not between 0 and 1.
         */
        [[nodiscard]] Math::Point3D pointAt(double u, double v) const;
    };
}
