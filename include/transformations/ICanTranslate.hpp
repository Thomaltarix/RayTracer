/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ICanTranslate
*/

#pragma once

#include "Vector3D.hpp"

namespace RayTracer {
    /**
     * @class ICanTranslate
     * @brief This class is an interface for all the classes that can translate.
     * This method will be used to translate the object and will have all the variables needed to do so.
     */
    class ICanTranslate{
    public:
        /**
         * @brief Destructor for ICanTranslate class.
         */
        virtual ~ICanTranslate() = default;

        /**
         * @brief Translates the object by the given x, y, and z values.
         * @param x The x value to translate by.
         * @param y The y value to translate by.
         * @param z The z value to translate by.
         */
        virtual void translate(double x, double y, double z) = 0;

        /**
         * @brief Translates the object by the given vector.
         * @param vector The vector to translate by.
         */
        virtual void translate(const Math::Vector3D &vector) = 0;
    };
}
