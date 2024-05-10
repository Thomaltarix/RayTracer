/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "core/Image.hpp"
#include "../plugins/ALight.hpp"
#include "../plugins/APrimitive.hpp"
#include "math/MathError.hpp"
#include <any>
#include <fstream>
#include <iostream>
#include <cmath>

RayTracer::Image::Image()
{
    _camera = Camera();
    _height = 0;
    _width = 0;
}

RayTracer::Image::Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives,
    const std::vector<std::shared_ptr<ILight>> &lights, std::size_t width, std::size_t height, bool sfml)
{
    _camera = camera;
    for (auto &primitive : primitives) {
        _primitives.push_back(primitive);
    }
    for (auto &light : lights) {
        _lights.push_back(light);
    }
    _width = width;
    _height = height;
    this->_sfmlDisplay = sfml;
    this->_renderer = nullptr;
}

void RayTracer::Image::render(std::string filename)
{
    std::ofstream file;

    if (_sfmlDisplay) {
        this->_renderer = std::make_shared<SFMLRenderer>(_width, _height);
    }
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file << "P3\n" << _width << " " << _height << "\n255\n";

    for (size_t j = _height; j > 0; j--) {
        for (size_t i = 0; i < _width; i++) {
            double u = double(i) / (double)_width;
            double v = double(j) / (double)_height;
            Math::Ray ray = _camera.ray(u, v);
            std::any closestHit = 0;
            std::shared_ptr<IPrimitive> closestHitPrimitive = nullptr;
            for (const auto& primitive : _primitives) {
                if (primitive->hits(ray)) {
                    Math::Point3D hitPoint;
                    try {
                        hitPoint = primitive->hitPoint(ray);
                    }
                    catch (const Math::MathNoSolutionError &e) {
                        continue;
                    }
                    try {
                        if (hitPoint.distance(_camera._origin) < std::any_cast<Math::Point3D>(closestHit).distance(_camera._origin)) {
                            closestHit = hitPoint;
                            closestHitPrimitive = primitive;
                        }
                    }
                    catch (const std::bad_any_cast &e) {
                        closestHit = hitPoint;
                        closestHitPrimitive = primitive;
                    }
                }
            }
            try {
                std::any_cast<Math::Point3D>(closestHit);
            }
            catch (const std::bad_any_cast &e) {
                file << "0 0 0" << std::endl;
                continue;
            }
            Math::Point3D hitPoint = std::any_cast<Math::Point3D>(closestHit);
            Math::Vector3D color(0, 0, 0);
            for (const auto& light : _lights) {
                color += light->Illuminate(hitPoint, closestHitPrimitive->getMaterial()); // color with light
            }
            file << round(color.x) << " " << round(color.y) << " " << round(color.z) << std::endl;
            if (_sfmlDisplay) {
                this->setSFMLPixel(i, j, color);
                this->renderSFML();
            }
        }
    }
}

void RayTracer::Image::setSFMLPixel(unsigned int x, unsigned int y, Math::Vector3D color)
{
    this->_renderer->setPixel(x, y, color);
}

void RayTracer::Image::renderSFML()
{
    this->_renderer->display();
    this->_renderer->handleEvents();
}
