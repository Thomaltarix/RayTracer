/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** FlatColor.hpp
*/

#pragma once

#include "AMaterial.hpp"

namespace Material {

    /**
     * @brief The FlatColor class represents a material with a flat color.
     *
     * This class inherits from the AMaterial class and provides a simple material
     * implementation with a single flat color.
     */
    class FlatColor : public RayTracer::AMaterial {
        public:
        /**
         * @brief Default constructor for the FlatColor class.
         */
        FlatColor();

        /**
         * @brief Constructor for the FlatColor class with a specified color.
         *
         * @param color The color of the material.
         */
        FlatColor(Math::Vector3D color);

        /**
         * @brief Destructor for the FlatColor class.
         */
        ~FlatColor();
    };
}
