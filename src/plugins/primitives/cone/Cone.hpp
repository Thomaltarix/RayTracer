/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "APrimitive.hpp"
#include "transformations/ICanTranslate.hpp"
#include "3DAxis.hpp"

namespace Primitive {
    /**
     * @brief The Cone class represents a cone primitive in a ray tracer.
     */
    class Cone : public RayTracer::APrimitive, public RayTracer::ICanTranslate {
    public:
        /**
         * @brief Default constructor for the Cone class.
         */
        Cone();

        /**
         * @brief Constructor for the Cone class.
         * @param pos The position of the cone.
         * @param material The material of the cone.
         * @param axis The axis of the cone.
         * @param angle The angle of the cone.
         */
        Cone(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X, double angle = 0);

        /**
         * @brief Constructor for the Cone class.
         * @param x The x-coordinate of the position of the cone.
         * @param y The y-coordinate of the position of the cone.
         * @param z The z-coordinate of the position of the cone.
         * @param material The material of the cone.
         * @param axis The axis of the cone.
         * @param angle The angle of the cone.
         */
        Cone(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const RayTracer::Axis3D &axis = RayTracer::Axis::X, double angle = 0);

        Cone(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const Math::Vector3D &axis = Math::Vector3D(1, 0, 0), double angle = 0);

        Cone(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr, const Math::Vector3D &axis = Math::Vector3D(1, 0, 0), double angle = 0);

        /**
         * @brief Default destructor for the Cone class.
         */
        ~Cone() = default;

        /**
         * @brief Checks if a ray intersects with the cone.
         * @param ray The ray to check for intersection.
         * @return True if the ray intersects with the cone, false otherwise.
         */
        bool hits(const Math::Ray &ray) override;

        /**
         * @brief Gets the point where the ray intersects with the cone.
         * @param ray The ray to check for intersection.
         * @return The point where the ray intersects with the cone.
         */
        Math::Point3D hitPoint(const Math::Ray &ray) override;

        /**
         * @brief Calculates the normal vector at a given point on the cone.
         * @param point The point on the cone to calculate the normal vector for.
         * @return The normal vector at the given point.
         */
        Math::Vector3D getNormalAt(const Math::Point3D &point) override;

        /**
         * @brief Translates the cone by a given vector.
         * @param translation The vector to translate the cone by.
         */
        void translate(const Math::Vector3D &translation) override;

        /**
         * @brief Translates the cone by a given vector.
         * @param x The x-coordinate to translate the cone by.
         * @param y The y-coordinate to translate the cone by.
         * @param z The z-coordinate to translate the cone by.
         */
        void translate(double x, double y, double z) override;

    private:
        Math::Vector3D _axis; /** The axis of the cone*/
        double _angle; /** The angle of the cone*/
    };
}