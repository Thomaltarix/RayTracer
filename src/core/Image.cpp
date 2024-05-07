/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include "Image.hpp"
#include <any>
#include <fstream>
#include <iostream>

#include "../plugins/materials/flatColor/FlatColor.hpp"

RayTracer::Image::Image()
{
    _camera = Camera();
    _height = 1000;
    _width = 1000;
}

RayTracer::Image::Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives, const std::vector<std::shared_ptr<ILight>> &lights)
{
    _camera = camera;
    for (auto &primitive : primitives) {
        _primitives.push_back(primitive);
    }
    for (auto &light : lights) {
        _lights.push_back(light);
    }
    _lights = lights;
    _height = 1000;
    _width = 1000;
}


void RayTracer::Image::render(std::string filename)
{
    std::ofstream file;

    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file << "P3\n" << _width << " " << _height << "\n255\n";

    for (std::size_t i = 0; i < _width; i++) {
        for (std::size_t j = 0; j < _height; j++) {
            double u = double(i) / (double)_width;
            double v = double(j) / (double)_height;
            Math::Ray ray = _camera.ray(u, v);
            std::any closestHit = 0;
            std::shared_ptr<IPrimitive> closestHitPrimitive = nullptr;
            for (const auto& primitive : _primitives) {
                if (primitive->hits(ray)) {
                    Math::Point3D hitPoint = primitive->hitPoint(ray);
                    try {
                        std::any_cast<Math::Point3D>(closestHit);
                    }
                    catch (const std::bad_any_cast &e) {
                        closestHit = hitPoint;
                        closestHitPrimitive = primitive;
                        continue;
                    }
                    if (hitPoint.distance(_camera.origin) < std::any_cast<Math::Point3D>(closestHit).distance(_camera.origin)) {
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
            Math::Vector3D color;
            for (const auto& light : _lights) {
                color += light->Illuminate(hitPoint, closestHitPrimitive->getMaterial());
            }
            file << color.x << " " << color.y << " " << color.z << std::endl;
        }
    }
}

