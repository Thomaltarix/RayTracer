/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ALight.hpp
*/

#pragma once

#include "lights/ILight.hpp"

namespace RayTracer {

    /**
     * @brief The base class for all lights in the RayTracer.
     *
     * This class provides common functionality and properties for lights.
     */
    class ALight : public ILight {
    public:
        /**
         * @brief Default constructor.
         */
        ALight();

        /**
         * @brief Constructor that sets the intensity of the light.
         *
         * @param intensity The intensity of the light.
         */
        ALight(float intensity);

        /**
         * @brief Constructor that sets the intensity and color of the light.
         *
         * @param intensity The intensity of the light.
         * @param color The color of the light.
         * @param doesShadowcast Whether the light casts shadows or not.
         */
        ALight(float intensity, Math::Vector3D color, bool doesShadowcast = false);

        /**
         * @brief Destructor.
         */
        ~ALight() = default;

        /**
         * @brief Get the intensity of the light.
         *
         * @return The intensity of the light.
         */
        float getIntensity() const;

        /**
         * @brief Set the intensity of the light.
         *
         * @param intensity The intensity of the light.
         */
        void setIntensity(float intensity);

        /**
         * @brief Get the color of the light.
         *
         * @return The color of the light.
         */
        Math::Vector3D getColor() const;

        /**
         * @brief Set the color of the light.
         *
         * @param color The color of the light.
         */
        void setColor(Math::Vector3D color);

        /**
         * @brief Check if the light casts shadows.
         *
         * @return True if the light casts shadows, false otherwise.
         */
        bool doesShadowcast() const;

        /**
         * @brief Set whether the light casts shadows or not.
         *
         * @param doesShadowcast Whether the light casts shadows or not.
         */
        void setShadowcast(bool doesShadowcast);

        /**
         * @brief Illuminate a point with the light.
         *
         * @param point The point to illuminate.
         * @param material The material of the object at the point.
         * @param primitives The list of primitives in the scene.
         * @param normal The normal of the object at the point.
         * @return The illumination at the point.
         */
        Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material,
            const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives, Math::Vector3D normal) override;

    protected:
        float _intensity; /**< The intensity of the light. */
        Math::Vector3D _color; /**< The color of the light. */
        bool _doesShadowcast; /**< Whether the light casts shadows or not. */
    };
}
