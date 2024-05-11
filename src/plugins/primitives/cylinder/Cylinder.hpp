/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"
#include "transformations/ICanTranslate.hpp"
#include "3DAxis.hpp"

namespace Primitive {
    /**
     * @brief The Cylinder class represents a cylinder primitive in a ray tracer.
     */
    class Cylinder : public RayTracer::APrimitive, public RayTracer::ICanTranslate {
    public:
        /**
         * @brief Default constructor for the Cylinder class.
         */
        Cylinder();

        /**
         * @brief Constructor for the Cylinder class.
         * @param pos The position of the cylinder.
         * @param material The material of the cylinder.
         * @param axis The axis of the cylinder.
         * @param radius The radius of the cylinder.
         */
        Cylinder(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X, double radius = 0);

        /**
         * @brief Constructor for the Cylinder class.
         * @param x The x-coordinate of the position of the cylinder.
         * @param y The y-coordinate of the position of the cylinder.
         * @param z The z-coordinate of the position of the cylinder.
         * @param material The material of the cylinder.
         * @param axis The axis of the cylinder.
         * @param radius The radius of the cylinder.
         */
        Cylinder(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X, double radius = 0);

        /**
         * @brief Default destructor for the Cylinder class.
         */
        ~Cylinder() = default;

        /**
         * @brief Checks if a ray intersects with the cylinder.
         * @param ray The ray to check for intersection.
         * @return True if the ray intersects with the cylinder, false otherwise.
         */
        bool hits(const Math::Ray &ray) override;

        /**
         * @brief Gets the point where the ray intersects with the cylinder.
         * @param ray The ray to check for intersection.
         * @return The point where the ray intersects with the cylinder.
         */
        Math::Point3D hitPoint(const Math::Ray &ray) override;

        /**
         * @brief Calculates the normal vector at a given point on the cylinder.
         * @param point The point on the cylinder to calculate the normal vector for.
         * @return The normal vector at the given point.
         */
        Math::Vector3D getNormalAt(const Math::Point3D &point) override;

        /**
         * @brief Translates the cylinder by a given vector.
         * @param translation The vector to translate the cylinder by.
         */
        void translate(const Math::Vector3D &translation) override;

        /**
         * @brief Translates the cylinder by a given vector.
         * @param x The x-coordinate to translate the cylinder by.
         * @param y The y-coordinate to translate the cylinder by.
         * @param z The z-coordinate to translate the cylinder by.
         */
        void translate(double x, double y, double z) override;

    private:
        /** < The axis of the cylinder. */
        Math::Vector3D _axis;
        /** < The radius of the cylinder. */
        double _radius;

        /**
         * @brief Calculates the intersection points between a ray and the cylinder.
         * @param ray The ray to intersect with the cylinder.
         * @return A pair of doubles representing the distances from the ray origin to the intersection points.
         */
        std::pair<double, double> getIntersectionPoints(const Math::Ray &ray);
    };
}
