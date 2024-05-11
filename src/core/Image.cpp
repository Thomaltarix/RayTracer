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
#include <thread>
#include <sstream>

RayTracer::Image::Image()
{
    _camera = Camera();
    _height = 0;
    _width = 0;
}

RayTracer::Image::Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives, const std::vector<std::shared_ptr<ILight>> &lights, std::size_t width, std::size_t height)
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
}

void RayTracer::Image::renderThread(std::vector<std::vector<std::string>> &tab, size_t threadId, size_t start, size_t end)
{
    (void)threadId;

    for (size_t j = start; j < end; j++) {
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
                continue;
            }
            Math::Point3D hitPoint = std::any_cast<Math::Point3D>(closestHit);
            Math::Vector3D color(0, 0, 0);
            for (const auto& light : _lights) {
                color += light->Illuminate(hitPoint, closestHitPrimitive->getMaterial()); // color with light
            }
            tab[j][i] = std::to_string((int)round(color.x)) + " " + std::to_string((int)round(color.y)) + " " + std::to_string((int)round(color.z));
        }
    }
}

void RayTracer::Image::render(std::string filename)
{
    std::ofstream file;

    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file << "P3\n" << _width << " " << _height << "\n255\n";

    std::vector<std::thread> threads;
    size_t maxThreads = std::thread::hardware_concurrency();
    maxThreads = maxThreads == 0 ? 1 : maxThreads;
    maxThreads = maxThreads > _height? _height: maxThreads;

    std::vector<std::vector<std::string>> tab(_height, std::vector<std::string>(_width, "1 1 1"));
    for (size_t i = 0; i < maxThreads; i++) {
        threads.push_back(std::thread(&Image::renderThread, this, std::ref(tab), i, i * (_height / maxThreads), (i + 1) * (_height / maxThreads)));
    }
    for (auto &thread : threads) {
        thread.join();
    }

    for (size_t j = _height - 1; j > 0; j--) {
        for (size_t i = 0; i < _width; i++) {
            file << tab[j][i] << std::endl;
        }
    }
    for (size_t i = 0; i < _width; i++) {
        file << tab[0][i] << std::endl;
    }
    file.close();
}

