/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitive
*/

#pragma once

#include "primitives/IPrimitive.hpp"

namespace RayTracer {
    /**
     * @brief The APrimitive class is an abstract base class for all primitives in the RayTracer.
     */
    class APrimitive : public IPrimitive {
    public:
        /**
         * @brief Constructs an APrimitive object.
         */
        APrimitive();

        /**
         * @brief Destroys the APrimitive object.
         */
        virtual ~APrimitive() = default;

        /**
         * @brief Checks if a ray hits the primitive.
         * @param ray The ray to check for hits.
         * @return True if the ray hits the primitive, false otherwise.
         */
        virtual bool hits(const Math::Ray &ray) = 0;

        /**
         * @brief Sets the position of the primitive using individual coordinates.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         */
        void setPos(double x, double y, double z) override;

        /**
         * @brief Sets the position of the primitive using a Point3D object.
         * @param point The position of the primitive.
         */
        void setPos(Math::Point3D point) override;

        /**
         * @brief Sets the material of the primitive.
         * @param material The material of the primitive.
         */
        void setMaterial(std::shared_ptr<IMaterial> material) override;

        /**
         * @brief Gets the position of the primitive.
         * @return The position of the primitive.
         */
        Math::Point3D getPos() override;

        /**
         * @brief Gets the material of the primitive.
         * @return The material of the primitive.
         */
        std::shared_ptr<IMaterial> getMaterial() override;

        /**
         * @brief Gets the normal vector at a given point on the primitive's surface.
         * @param point The point on the primitive's surface.
         * @return The normal vector at the given point.
         */
        virtual Math::Vector3D getNormalAt(const Math::Vector3D &point) = 0;

    protected:
        Math::Point3D _pos; /**< The position of the primitive. */
        std::shared_ptr<IMaterial> _material; /**< The material of the primitive. */
    };
}
