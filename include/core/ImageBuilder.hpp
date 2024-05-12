/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ImageBuilder
*/

#pragma once

#include "Image.hpp"
#include "Core.hpp"

namespace RayTracer {
    /**
     * @class ImageBuilder
     * @brief The ImageBuilder class is responsible for building an Image object.
     *
     * The ImageBuilder class provides a fluent interface for constructing an Image object
     * with various properties such as camera, width, height, primitives, lights, and arguments.
     */
    class ImageBuilder {
    public:
        /**
         * @brief Default constructor.
         */
        ImageBuilder() = default;

        /**
         * @brief Default destructor.
         */
        ~ImageBuilder() = default;

        /**
         * @brief Builds and returns the Image object.
         * @return The built Image object.
         */
        Image buildImage();

        /**
         * @brief Sets the camera for the ImageBuilder.
         * @param camera The camera to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildCamera(const Camera &camera);

        /**
         * @brief Sets the width for the ImageBuilder.
         * @param width The width to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildWidth(const int &width);

        /**
         * @brief Sets the height for the ImageBuilder.
         * @param height The height to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildHeight(const int &height);

        /**
         * @brief Sets the primitives for the ImageBuilder.
         * @param primitives The primitives to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildPrimitives(const std::vector<std::shared_ptr<IPrimitive>> &primitives);

        /**
         * @brief Sets the lights for the ImageBuilder.
         * @param lights The lights to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildLights(const std::vector<std::shared_ptr<ILight>> &lights);

        /**
         * @brief Sets the arguments handler for the ImageBuilder.
         * @param args The arguments handler to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildArgs(std::shared_ptr<ArgsHandler> args);

        /**
         * @brief Sets the renderer for the ImageBuilder.
         * @param args The renderer to set.
         * @return Reference to the ImageBuilder.
         */
        ImageBuilder &buildRenderer(std::shared_ptr<ArgsHandler> args);

    private:
        /**< The Image object being built. */
        Image _image;
    };
}
