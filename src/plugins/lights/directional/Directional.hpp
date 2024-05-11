/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Directional.hpp
*/

#pragma once

#include "ALight.hpp"

namespace Light {
    /**
     * @brief The Directional class represents a directional light source in the RayTracer.
     *
     * It inherits from the ALight class and provides functionality to set the direction of the light source,
     * calculate illumination at a given point, and check if a point is in shadow.
     */
    class Directional : public RayTracer::ALight {
    public:
        /**
         * @brief Default constructor for the Directional class.
         */
        Directional();

        /**
         * @brief Constructor for the Directional class.
         *
         * @param intensity The intensity of the light source.
         */
        Directional(float intensity);

        /**
         * @brief Constructor for the Directional class.
         *
         * @param intensity The intensity of the light source.
         * @param direction The direction of the light source.
         */
        Directional(float intensity, Math::Vector3D direction);

        /**
         * @brief Constructor for the Directional class.
         *
         * @param direction The direction of the light source.
         */
        Directional(Math::Vector3D direction);

        /**
         * @brief Default destructor for the Directional class.
         */
        ~Directional() = default;

        /**
         * @brief Get the direction of the light source.
         *
         * @return The direction vector of the light source.
         */
        Math::Vector3D getDirection() const;

        /**
         * @brief Set the direction of the light source.
         *
         * @param direction The new direction vector of the light source.
         */
        void setDirection(Math::Vector3D direction);

        /**
         * @brief Check if a given point is in shadow.
         *
         * @param point The point to check.
         * @return True if the point is in shadow, false otherwise.
         */
        bool InShadow(Math::Point3D point) override;

        /**
         * @brief Calculate the illumination at a given point.
         *
         * @param point The point to calculate illumination for.
         * @param material The material of the object at the point.
         * @param primitives The list of primitives in the scene.
         * @return The illumination vector at the given point.
         */
        Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<RayTracer::IMaterial> &material,
            const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives) override;

    private:
        Math::Vector3D _direction; /**< The direction vector of the light source. */
    };
}
