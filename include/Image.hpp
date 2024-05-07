/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "Camera.hpp"
#include "../src/plugins/primitives/APrimitive.hpp"
#include "../src/plugins/lights/ALight.hpp"
#include <vector>
#include <string>

namespace RayTracer {
    class Image {
    public:
        Camera _camera;
        std::vector<std::shared_ptr<IPrimitive>> _primitives;
        std::vector<std::shared_ptr<ILight>> _lights;
        std::size_t _width;
        std::size_t _height;

        Image();
        Image(const Camera &camera, const std::vector<std::shared_ptr<IPrimitive>> &primitives, const std::vector<std::shared_ptr<ILight>> &lights);
        ~Image() = default;

        void render(std::string filename);
    };
}
