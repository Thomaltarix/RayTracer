/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** sphere
*/

#pragma once

#include "APrimitive.hpp"

namespace Primitive {
    /**
     * @brief The Sphere class represents a sphere primitive in a ray tracer.
     */
    class Sphere : public RayTracer::APrimitive {
    public:
        /**
         * @brief Default constructor for the Sphere class.
        */
        Sphere() = default;

        /**
         * @brief Constructs a Sphere object with the given radius and material.
         * @param radius The radius of the sphere.
         * @param material The material of the sphere.
         */
        Sphere(float radius, const std::shared_ptr<RayTracer::IMaterial> &material);

        /**
         * @brief Destroys the Sphere object.
         */
        ~Sphere() override = default;

        /**
         * @brief Checks if a ray intersects with the sphere.
         *
         * @param ray The ray to check for intersection.
         * @return True if the ray intersects with the sphere, false otherwise.
         */
        bool hits(const Math::Ray &ray) override;

        /**
         * @brief Gets the normal at a given point on the sphere.
         * @param point The point to get the normal at.
         * @return The normal at the given point.
         */
        Math::Vector3D getNormalAt(const Math::Vector3D &point) override;

    private:
        float radius; /**< The radius of the sphere. */
    };
}
