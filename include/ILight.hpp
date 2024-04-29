/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ILight
*/

#pragma once

namespace RayTracer {
    /**
     * @class ILight
     * @brief Interface for light sources in a RayTracer.
     */
    class ILight {
    public:
        /**
         * @brief Destructor for ILight.
         */
        virtual ~ILight() = default;

        /**
         * @brief Getters for the light properties.
         * @note These getters are not implemented yet.
         */

        /**
         * @brief Setters for the light properties.
         * @note These setters are not implemented yet.
         */

        /**
         * @brief Calculates the light intensity at a given point.
         * @param point The point at which to calculate the light intensity.
         * @param material The material of the object at the point.
         * @return The light intensity as a Vector3.
         */
        //Vector3 Illuminate(Point3D point, Material material);

        /**
         * @brief Checks if a given point is in shadow.
         * @param point The point to check for shadow.
         * @return True if the point is in shadow, false otherwise.
         */
        //bool InShadow(Point3D point);
    };
}
