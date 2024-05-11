/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ILight
*/

#pragma once

#include "Vector3D.hpp"
#include "Point3D.hpp"
#include "materials/IMaterial.hpp"
#include "primitives/IPrimitive.hpp"
#include <memory>
#include <vector>

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
         * @param primitives The list of primitives in the scene.
         * @return The light intensity as a Vector3.
         */
        virtual Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material,
        const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives) = 0;

        /**
         * @brief Checks if a given point is in shadow.
         * @param point The point to check for shadow.
         * @return True if the point is in shadow, false otherwise.
         */
        virtual bool InShadow(Math::Point3D point) = 0;
    };
}
