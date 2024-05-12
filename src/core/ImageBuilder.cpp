/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ImageBuilder
*/

#include "core/ImageBuilder.hpp"

RayTracer::ImageBuilder::ImageBuilder()
{
    _image = std::make_shared<Image>();
}

RayTracer::ImageBuilder::~ImageBuilder()
{
}

std::shared_ptr<RayTracer::Image> RayTracer::ImageBuilder::buildImage()
{
    return _image;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::withCamera(const Camera &camera)
{
    _image->_camera = camera;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::withWidth(const int &width)
{
    _image->_width = width;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::withHeight(const int &height)
{
    _image->_height = height;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::withPrimitives(const std::vector<std::shared_ptr<IPrimitive>> &primitives)
{
    for (auto &primitive : primitives) {
        std::shared_ptr<IPrimitive> new_primitive = primitive->clone();
        _image->_primitives.push_back(new_primitive);
    }
    return *this;
}