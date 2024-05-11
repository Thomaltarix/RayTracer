/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ICanRotate
*/

#pragma once

#include "../plugins/3DAxis.hpp"

namespace RayTracer {
    /**
     * @class ICanRotate
     * @brief This class is an interface for all the classes that can rotate.
     * It inherits the ITransformation class and the transform method.
     * This method will be used to rotate the object and will have all the variables needed to do so.
     */
    class ICanRotate {
    public:
        /**
         * @brief Destructor for ICanRotate class.
         */
        virtual ~ICanRotate() = default;

        /**
         * @brief Rotates the object by the given x, y, and z values.
         * @param axis The axis to rotate around.
         * @param angle The angle to rotate by.
         */
        virtual void rotate(const RayTracer::Axis3D &axis, double angle) = 0;
    };
}
