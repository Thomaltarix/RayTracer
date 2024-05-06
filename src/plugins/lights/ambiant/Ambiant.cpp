/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ambiant.cpp
*/

#include "Ambiant.hpp"

Light::Ambiant::Ambiant() : ALight()
{
    _intensity = 1.0f;
}

Light::Ambiant::Ambiant(float intensity) : ALight(intensity) {}

Light::Ambiant::~Ambiant() {}
