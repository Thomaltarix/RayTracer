/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitive
*/

#pragma once

#include "../../../include/primitives/IPrimitive.hpp"
#include "../../../include/materials/IMaterial.hpp"
#include "../../../include/math/Point3D.hpp"
#include "../../../include/math/Ray.hpp"

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
         * @brief Constructs an APrimitive object with the given position and material.
         * @param pos The position of the primitive.
         * @param material The material of the primitive.
         */
        APrimitive(const Math::Point3D &pos, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr);

        /**
         * @brief Constructs an APrimitive object with the given position as individual coordinates and material.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         * @param material The material of the primitive.
         */
        APrimitive(double x, double y, double z, const std::shared_ptr<RayTracer::IMaterial> &material = nullptr);

        /**
         * @brief Destroys the APrimitive object.
         */
        ~APrimitive() override;

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
        void setPos(Math::Point3D point);

        /**
         * @brief Sets the material of the primitive.
         * @param material The material of the primitive.
         */
        void setMaterial(std::shared_ptr<RayTracer::IMaterial> material);

        /**
         * @brief Gets the position of the primitive.
         * @return The position of the primitive.
         */
        Math::Point3D getPos();

        /**
         * @brief Gets the material of the primitive.
         * @return The material of the primitive.
         */
        std::shared_ptr<RayTracer::IMaterial> getMaterial();

        /**
         * @brief Gets the normal vector at a given point on the primitive's surface.
         * @param point The point on the primitive's surface.
         * @return The normal vector at the given point.
         */
        virtual Math::Vector3D getNormalAt(const Math::Point3D &point) = 0;

    protected:

        /**< The position of the primitive. */
        Math::Point3D _pos;

        /**< The material of the primitive. */
        std::shared_ptr<RayTracer::IMaterial> _material;
    };
}
