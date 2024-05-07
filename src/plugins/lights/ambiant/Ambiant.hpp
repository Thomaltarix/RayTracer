/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ambiant.hpp
*/

#pragma once

#include "ALight.hpp"

namespace Light {
    /**
     * @brief The Ambiant class represents an ambient light source in a ray tracer.
     *
     * This class inherits from the ALight class and provides functionality for creating
     * ambient light sources with different intensities.
     */
    class Ambiant : public RayTracer::ALight {
    public:
        /**
         * @brief Default constructor for the Ambiant class.
         */
        Ambiant();

        /**
         * @brief Constructor for the Ambiant class with a specified intensity.
         *
         * @param intensity The intensity of the ambient light source.
         */
        Ambiant(float intensity);

        /**
         * @brief Destructor for the Ambiant class.
         */
        ~Ambiant() = default;
    };
}
