/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ImageBuilder
*/

#include "core/ImageBuilder.hpp"

RayTracer::Image RayTracer::ImageBuilder::buildImage()
{
    return _image;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildCamera(const Camera &camera)
{
    _image._camera = camera;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildWidth(const int &width)
{
    _image._width = width;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildHeight(const int &height)
{
    _image._height = height;
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildPrimitives(const std::vector<std::shared_ptr<IPrimitive>> &primitives)
{
    for (auto &primitive : primitives) {
        _image._primitives.push_back(primitive);
    }
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildLights(const std::vector<std::shared_ptr<ILight>> &lights)
{
    for (auto &light : lights) {
        _image._lights.push_back(light);
    }
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildArgs(std::shared_ptr<ArgsHandler> args)
{
    _image.setArgs(args);
    return *this;
}

RayTracer::ImageBuilder &RayTracer::ImageBuilder::buildRenderer(std::shared_ptr<ArgsHandler> args)
{
    _image.setRenderer(args);
    return *this;
}
