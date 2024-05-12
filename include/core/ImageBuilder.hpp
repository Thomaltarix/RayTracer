/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ImageBuilder
*/

#pragma once

#include "Image.hpp"

namespace RayTracer {
    class ImageBuilder {
    public:
        ImageBuilder();
        ~ImageBuilder();

        std::shared_ptr<Image> buildImage();

        ImageBuilder &withCamera(const Camera &camera);
        ImageBuilder &withWidth(const int &width);
        ImageBuilder &withHeight(const int &height);
        ImageBuilder &withPrimitives(const std::vector<std::shared_ptr<IPrimitive>> &primitives);

    private:
        std::shared_ptr<Image> _image;
    };
}
