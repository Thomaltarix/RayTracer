/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ITransformation
*/

#pragma once

namespace RayTracer {
    /**
     * @class ITransformation
     * @brief Interface for all the classes that can transform objects.
     *
     * This class is an interface for all the classes that can transform objects.
     * It provides a common interface for applying transformations to objects.
     */
    class ITransformation {
    public:
        /**
         * @brief Default destructor.
         */
        virtual ~ITransformation() = default;

        /**
         * @brief Applies a transformation to an object.
         *
         * This function is responsible for applying a transformation to an object.
         * The specific transformation logic should be implemented in the derived classes.
         */
        virtual void transform() = 0;
    };
}
