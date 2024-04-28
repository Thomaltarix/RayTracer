/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IPrimitives
*/

#pragma once

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
         * @brief Checks if a ray intersects with the primitive.
         *
         * @param ray The ray to check intersection with.
         * @param t The parameter representing the intersection point along the ray.
         * @return True if the ray intersects with the primitive, false otherwise.
         */
        // virtual bool intersect(const Ray &ray, float &t) = 0;

        /**
         * @brief Sets the position of the primitive.
         *
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         */
        // virtual void setPos(float x, float y, float z) = 0;

        /**
         * @brief Sets the position of the primitive.
         *
         * @param point The position as a Point3 object.
         */
        // virtual void setPos(Point3 point) = 0;

        /**
         * @brief Gets the position of the primitive.
         *
         * @return The position of the primitive as a Point3 object.
         */
        // virtual Point3 getPos() = 0;

        /**
         * @brief Gets the normal vector at a given point on the primitive.
         *
         * @param point The point on the primitive.
         * @return The normal vector at the given point.
         */
        // virtual Vector3 getNormalAt(const Vector3 &point) = 0;
    };
}
