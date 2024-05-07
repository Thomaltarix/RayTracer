/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IMaterial
*/

#pragma once

#include "Vector3D.hpp"

namespace RayTracer {
    /**
     * @class IMaterial
     * @brief Interface for materials in a RayTracer.
     */
    /**
     * @brief The IMaterial class represents an interface for materials in a Ray Tracer.
     */
    class IMaterial {
    public:
        /**
         * @brief Destructor for IMaterial.
         */
        virtual ~IMaterial() = default;

        /**
         * @brief Gets the color of the material.
         *
         * @return The color of the material.
         */
        virtual Math::Vector3D getColor() const = 0;

        /**
         * @brief Sets the color of the material.
         *
         * @param color The color of the material.
         */
        virtual void setColor(Math::Vector3D color) = 0;

        /**
         * @brief Compute the color of the material and return a Vector with RGB values -> should be RGBA values in the future.
         * @return The computed color of the material.
         * @note If the material is reflective, refractive, etc., implement this method; otherwise, return the color of the material.
         */
        virtual Math::Vector3D compute() = 0;
    };
}
