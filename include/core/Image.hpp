/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "Scene.hpp"
#include <vector>
#include <string>

namespace RayTracer {
    /**
     * @class Image
     * @brief This class represents an image in the RayTracer project.
     *
     * An Image object contains a camera, a list of primitives, a list of lights, and dimensions (width and height).
     * It provides methods to create an empty image, create an image with specific parameters, and render the image to a file.
     */
    class Image {
    public:
        /**
         * @brief The camera used to capture the image.
         */
        Camera _camera;

        /**
         * @brief A list of primitives (shapes) in the image.
         */
        std::vector<std::shared_ptr<IPrimitive>> _primitives;

        /**
         * @brief A list of lights in the image.
         */
        std::vector<std::shared_ptr<ILight>> _lights;

        /**
         * @brief The width of the image in pixels.
         */
        std::size_t _width;

        /**
         * @brief The height of the image in pixels.
         */
        std::size_t _height;

        /**
         * @brief Default constructor. Creates an empty image.
         */
        Image();

        /**
         * @brief Constructor. Creates an image with the specified camera, primitives, and lights.
         *
         * @param camera The camera used to capture the image.
         * @param primitives A list of primitives (shapes) in the image.
         * @param lights A list of lights in the image.
         * @param width The width of the image in pixels.
         * @param height The height of the image in pixels.
         */
        Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives, const std::vector<std::shared_ptr<ILight>> &lights, std::size_t width, std::size_t height);

        /**
         * @brief Default destructor.
         */
        ~Image() = default;

        /**
         * @brief Renders the image to a file.
         *
         * @param filename The name of the file to which the image is rendered.
         */
        void render(std::string filename="output.ppm");
    };
}

