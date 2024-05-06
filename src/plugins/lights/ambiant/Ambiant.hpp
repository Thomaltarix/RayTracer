/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ambiant.hpp
*/

#pragma once

#include "ALight.hpp"

namespace Light {
    class Ambiant : public RayTracer::ALight {
        public:
        Ambiant();
        Ambiant(float intensity);
        ~Ambiant();
    };
}