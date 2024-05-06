/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** FlatColor.hpp
*/

#pragma once

#include "AMaterial.hpp"

namespace Material {
    class FlatColor : public RayTracer::AMaterial {
        public:
        FlatColor();
        FlatColor(Math::Vector3D color);
        ~FlatColor();
    };
}
