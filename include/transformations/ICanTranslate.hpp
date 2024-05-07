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
    };
}
