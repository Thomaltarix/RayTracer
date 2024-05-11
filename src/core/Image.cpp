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

RayTracer::Image::Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives,
    const std::vector<std::shared_ptr<ILight>> &lights, std::size_t width, std::size_t height, std::shared_ptr<ArgsHandler> args)
{
    _camera = camera;
    for (auto &primitive : primitives) {
        _primitives.push_back(primitive);
    }
    for (auto &light : lights) {
        _lights.push_back(light);
    }
    this->_width = width;
    this->_height = height;
    this->_args = args.get();
    if (args->isSFML()) {
        this->_renderer = new SFMLRenderer(width, height);
    }
    else {
        this->_renderer = nullptr;
    }
}

void RayTracer::Image::renderThread(std::vector<std::vector<Math::Vector3D>> &tab, size_t threadId, size_t start, size_t end, size_t fast)
{
    (void)threadId;

    for (size_t j = start; j < end; j++) {
        if (fast && j % fast != 0) continue;
        for (size_t i = 0; i < _width; i++) {
            if (fast && i % fast != 0) continue;
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
                tab[j][i] = Math::Vector3D(1 ,1, 1);
                continue;
            }
            Math::Point3D hitPoint = std::any_cast<Math::Point3D>(closestHit);
            Math::Vector3D color(0, 0, 0);
            for (const auto& light : _lights) {
                color += light->Illuminate(hitPoint, closestHitPrimitive->getMaterial()); // color with light
            }
            tab[j][i] = color;
            if (fast) {
                for (size_t dj = 0; dj < fast && j + dj < _height; dj++) {
                    for (size_t di = 0; di < fast && i + di < _width; di++) {
                        tab[j + dj][i + di] = color;
                    }
                }
            }
        }
    }
    if (fast) {
        renderThread(tab, threadId, start, end, fast / 2);
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

    std::vector<std::vector<Math::Vector3D>> tab(_height, std::vector<Math::Vector3D>(_width, Math::Vector3D(1, 1, 1)));
    if (maxThreads > 1 && this->_args->isSFML()) {
        maxThreads--;
        threads.push_back(std::thread(&Image::threadHandlingSFML, this, std::ref(tab)));
    }
    for (size_t i = 0; i < maxThreads; i++) {
        threads.push_back(std::thread(&Image::renderThread, this, std::ref(tab), i, i * (_height / maxThreads), (i + 1) * (_height / maxThreads), this->_args->isFastRender()));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    std::string content = "";
    for (size_t j = _height - 1; j > 0; j--) {
        for (size_t i = 0; i < _width; i++) {
            content += std::to_string((int)(tab[j][i].x)) + " " + std::to_string((int)(tab[j][i].y)) + " " + std::to_string((int)(tab[j][i].z)) + "\n";
        }
    }
    for (size_t i = 0; i < _width; i++) {
        content += std::to_string((int)(tab[0][i].x)) + " " + std::to_string((int)(tab[0][i].y)) + " " + std::to_string((int)(tab[0][i].z)) + "\n";
    }
    file << content;
    file.close();
}

void RayTracer::Image::threadHandlingSFML(std::vector<std::vector<Math::Vector3D>> &tab)
{
    if (this->_renderer == nullptr) {
        throw std::runtime_error("No renderer set"); //TODO: Create a custom exception
    }
    try {
        while (1) {
            this->setSFMLPixels(tab);
            this->renderSFML();
        }
    } catch (const SFMLCLoseWindowException &e) {
        std::cerr << e.what() << std::endl;
    }
}

void RayTracer::Image::setSFMLPixels(std::vector<std::vector<Math::Vector3D>> &tab)
{
    if (this->_renderer == nullptr) {
        throw std::runtime_error("No renderer set"); // TODO: Create a custom exception
    }
    for (size_t j = 0; j < _height; j++) {
        for (size_t i = 0; i < _width; i++) {
            this->_renderer->setPixel(i, j, tab[j][i]);
        }
    }
}

void RayTracer::Image::renderSFML()
{
    if (this->_renderer == nullptr) {
        throw std::runtime_error("No renderer set"); // TODO: Create a custom exception
    }
    this->_renderer->display(this->_args->getTimeToDisplay());
    this->_renderer->handleEvents();
}
