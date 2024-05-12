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
         * @brief Calculates the light intensity at a given point.
         * @param point The point at which to calculate the light intensity.
         * @param material The material of the object at the point.
         * @param primitives The list of primitives in the scene.
         * @param normal The normal of the object at the point.
         * @return The light intensity as a Vector3.
         */
        virtual Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material,
        const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives, Math::Vector3D normal) = 0;
    };
}
