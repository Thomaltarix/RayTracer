/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** plane
*/

#pragma once

#include "APrimitive.hpp"
#include "3DAxis.hpp"
#include "transformations/ICanTranslate.hpp"

namespace Primitive {
    /**
     * @brief The Plane class represents a plane primitive in a ray tracer.
     */
    class Plane : public RayTracer::APrimitive, public RayTracer::ICanTranslate {
    public:
        /**
         * @brief Default constructor for the Plane class.
         * @note The default constructor initializes the plane with the x-axis.
         */
        Plane();

        /**
         * @brief Constructs a Plane object with the given position and material.
         * @param pos The position of the plane.
         * @param material The material of the plane.
         * @param axis The axis along which the plane is defined.
        */
        Plane(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X);

        Plane(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X);

        /**
         * @brief Default destructor for the Plane class.
         */
        ~Plane() = default;

        /**
         * @brief Checks if a given ray intersects with the plane.
         * @param ray The ray to check for intersection.
         * @return True if the ray intersects with the plane, false otherwise.
         */
        bool hits(const Math::Ray &ray) override;

        /**
         * @brief Gets the point where the ray hits the plane.
         * @param ray The ray to check for hits.
         * @return The point where the ray hits the plane.
         */
        Math::Point3D hitPoint(const Math::Ray &ray) override;

        /**
         * @brief Calculates the normal vector at a given point on the plane.
         * @param point The point on the plane.
         * @return The normal vector at the given point.
         */
        Math::Vector3D getNormalAt(const Math::Point3D &point) override;

        /**
         * @brief Translates the plane by the given amounts along the x, y, and z axes.
         * @param x The amount to translate along the x-axis.
         * @param y The amount to translate along the y-axis.
         * @param z The amount to translate along the z-axis.
         */
        void translate(double x, double y, double z) override;

        /**
         * @brief Translates the plane by the given vector.
         * @param vec The vector by which to translate the plane.
         */
        void translate(const Math::Vector3D &vec) override;

    private:

        /**< The axis along which the plane is defined. */
        RayTracer::Axis3D _axis;
    };
}
