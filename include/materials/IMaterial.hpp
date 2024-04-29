/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IMaterial
*/

#pragma once

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
         * @brief Getters for the material properties.
         * @note These getters are not implemented yet.
         */

        /**
         * @brief Setters for the material properties.
         * @note These setters are not implemented yet.
         */

        /**
         * @brief Compute the color of the material and return a Vector with RGB values.
         * @return The computed color of the material.
         * @note If the material is reflective, refractive, etc., implement this method; otherwise, return the color of the material.
         */
        // virtual Vector4D compute() = 0;
    };
}
