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
    class ImageBuilder {
    public:
        ImageBuilder() = default;
        ~ImageBuilder() = default;

        Image buildImage();

        ImageBuilder &buildCamera(const Camera &camera);
        ImageBuilder &buildWidth(const int &width);
        ImageBuilder &buildHeight(const int &height);
        ImageBuilder &buildPrimitives(const std::vector<std::shared_ptr<IPrimitive>> &primitives);
        ImageBuilder &buildLights(const std::vector<std::shared_ptr<ILight>> &lights);
        ImageBuilder &buildArgs(std::shared_ptr<ArgsHandler> args);
        ImageBuilder &buildRenderer(std::shared_ptr<ArgsHandler> args);

    private:
        Image _image;
    };
}
