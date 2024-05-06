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
         * @brief Constructor that sets the intensity and shadow casting property of the light.
         *
         * @param intensity The intensity of the light.
         * @param doesShadowcast Whether the light casts shadows or not.
         */
        ALight(float intensity, bool doesShadowcast);

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
         * @return The illumination at the point.
         */
        Math::Vector3D Illuminate(Math::Point3D point, const std::shared_ptr<IMaterial> &material) override;

        /**
         * @brief Check if a point is in shadow.
         *
         * @param point The point to check.
         * @return True if the point is in shadow, false otherwise.
         */
        bool InShadow(Math::Point3D point) override;

    protected:
        float _intensity; /**< The intensity of the light. */
        bool _doesShadowcast; /**< Whether the light casts shadows or not. */
    };
}
