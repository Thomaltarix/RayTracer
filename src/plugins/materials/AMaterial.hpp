/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** AMaterial.hpp
*/

#pragma once

#include "materials/IMaterial.hpp"

namespace RayTracer {

    /**
     * @brief Abstract base class for materials used in the RayTracer.
     *
     * This class provides a common interface and basic functionality for materials
     * used in the RayTracer. It defines a color property and a compute() method.
     */
    class AMaterial : public IMaterial {
    public:
        /**
         * @brief Default constructor.
         */
        AMaterial();

        /**
         * @brief Constructor that sets the color of the material.
         *
         * @param color The color of the material.
         */
        AMaterial(Math::Vector3D color);

        /**
         * @brief Destructor.
         */
        ~AMaterial() = default;

        /**
         * @brief Computes the material properties.
         *
         * This method computes the material properties and returns the result as a
         * Math::Vector3D object.
         *
         * @return The computed material properties.
         */
        Math::Vector3D compute() override;

        /**
         * @brief Gets the color of the material.
         *
         * @return The color of the material.
         */
        Math::Vector3D getColor() const;

        /**
         * @brief Sets the color of the material.
         *
         * @param color The color of the material.
         */
        void setColor(Math::Vector3D color) override;

    protected:
        Math::Vector3D _color; /**< The color of the material. */
    };
}
