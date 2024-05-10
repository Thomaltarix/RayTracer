/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ICanScale
*/

#pragma once

#include "Vector3D.hpp"

namespace RayTracer {
    /**
     * @class ICanScale
     * @brief This class is an interface for all the classes that can scale.
     * This method will be used to scale the object and will have all the variables needed to do so.
     */
    class ICanScale {
    public:
        /**
         * @brief Destructor for ICanScale class.
         */
        virtual ~ICanScale() = default;

        /**
         * @brief Scales the object by the given multiplier.
         * @param multiplier The multiplier to scale by.
         */
        virtual void scale(double multiplier) = 0;
    };
}
