/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "../AMaterial.hpp"

namespace Material {

    /**
     * @brief The Grid class represents a material with a grid pattern.
     *
     * This class inherits from the AMaterial class and provides a material
     * implementation with a grid pattern.
     */
    class GridX : public RayTracer::AMaterial {
        public:
        /**
         * @brief Default constructor for the Grid class.
         */
        GridX();

        /**
         * @brief Constructor for the Grid class with a specified color.
         *
         * @param color1 The first color of the grid.
         * @param color2 The second color of the grid.
         */
        GridX(Math::Vector3D color1, Math::Vector3D color2);

        /**
         * @brief Destructor for the Grid class.
         */
        ~GridX() = default;

        /**
         * @brief Compute the color of the material at a given point.
         *
         * @return The color of the material at the given point.
         */
        Math::Vector3D compute(Math::Point3D point) override;

        /**
         * @brief Sets the color of the material.
         *
         * @param color The color of the material.
         */
        void setColor(Math::Vector3D color) override;

    private:
        Math::Vector3D _color2;
    };
}