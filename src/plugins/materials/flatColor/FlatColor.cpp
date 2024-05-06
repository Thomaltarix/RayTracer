/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** FlatColor.cpp
*/

#include "FlatColor.hpp"

Material::FlatColor::FlatColor() : AMaterial() {}

Material::FlatColor::FlatColor(Math::Vector3D color) : AMaterial(color) {}
