/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** sphere
*/

#pragma once

#include "APrimitive.hpp"
#include "math/Point3D.hpp"
#include "math/Ray.hpp"
#include "transformations/ICanTranslate.hpp"
#include "transformations/ICanScale.hpp"

namespace Primitive {
    /**
     * @brief The Sphere class represents a sphere primitive in a ray tracer.
     */
    class Sphere : public RayTracer::APrimitive, public RayTracer::ICanTranslate, public RayTracer::ICanScale {
    public:
        /**
         * @brief Default constructor for the Sphere class.
        */
        Sphere();

        /**
         * @brief Constructs a Sphere object with the given position, radius, and material.
         * @param radius The radius of the sphere.
         * @param material The material of the sphere.
         */
        Sphere(const Math::Point3D &pos, double radius, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr);

        /**
         * @brief Constructs a Sphere object with the given position, radius, and material.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         * @param radius The radius of the sphere.
         * @param material The material of the sphere.
         */
        Sphere(double x, double y, double z, double radius, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr);

        /**
         * @brief Destroys the Sphere object.
         */
        ~Sphere() = default;

        /**
         * @brief Checks if a ray intersects with the sphere.
         *
         * @param ray The ray to check for intersection.
         * @return True if the ray intersects with the sphere, false otherwise.
         */
        bool hits(const Math::Ray &ray) override;

        /**
         * @brief Gets the point where the ray hits the sphere.
         * @param ray The ray to check for hits.
         * @return The point where the ray hits the sphere.
         */
        Math::Point3D hitPoint(const Math::Ray &ray) override;

        /**
         * @brief Gets the normal at a given point on the sphere.
         * @param point The point to get the normal at.
         * @return The normal at the given point.
         */
        Math::Vector3D getNormalAt(const Math::Point3D &point) override;

        /**
         * @brief Gets the radius of the sphere.
         * @return The radius of the sphere.
         */
        double getRadius() const;

        /**
         * @brief Sets the radius of the sphere.
         * @param radius The new radius of the sphere.
         */
        void setRadius(double radius);

        /**
         * @brief Translates the sphere by the given vector.
         * @param vec The vector to translate the sphere by.
         */
        void translate(const Math::Vector3D &vec) override;

        /**
         * @brief Translates the sphere by the given x, y, and z values.
         * @param x The x value to translate by.
         * @param y The y value to translate by.
         * @param z The z value to translate by.
         */
        void translate(double x, double y, double z) override;

        /**
         * @brief Scales the sphere by the given multiplier.
         * If the multiplier is less than 1, the sphere will shrink.
         * If the multiplier is greater than 1, the sphere will grow.
         * If the multiplier is 1, the sphere will not change size.
         * @attention This only changes the radius of the sphere.
         * @param multiplier The value to scale the sphere by.
         */
        void scale(double multiplier) override;

    private:
        double _radius; /**< The radius of the sphere. */
    };
}
