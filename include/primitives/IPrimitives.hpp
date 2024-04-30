/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IPrimitives
*/

#pragma once

#include "Ray.hpp"
#include "Point3D.hpp"

namespace RayTracer {
    /**
     * @class IPrimitives
     * @brief Interface for ray-traceable primitives.
     */
    class IPrimitives {
    public:
        /**
         * @brief Virtual destructor for IPrimitives.
         */
        virtual ~IPrimitives() = default;

        /**
         * @brief Checks if a ray hits the primitive.
         * @param ray The ray to check for hits.
         * @return True if the ray hits the primitive, false otherwise.
         */
        virtual bool hits(const Math::Ray &ray) = 0;

        /**
         * @brief Sets the position of the primitive.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         */
        virtual void setPos(float x, float y, float z) = 0;

        /**
         * @brief Sets the position of the primitive.
         * @param point The position as a Point3D object.
         */
        virtual void setPos(Math::Point3D point) = 0;

        /**
         * @brief Gets the position of the primitive.
         * @return The position of the primitive as a Point3D object.
         */
        virtual Math::Point3D getPos() = 0;

        /**
         * @brief Gets the normal vector at a given point on the primitive.
         * @param point The point on the primitive.
         * @return The normal vector at the given point.
         */
        virtual Math::Vector3D getNormalAt(const Math::Vector3D &point) = 0;
    };
}
