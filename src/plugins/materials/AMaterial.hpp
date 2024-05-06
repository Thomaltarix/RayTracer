/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** AMaterial.hpp
*/

#pragma once

#include "materials/IMaterial.hpp"

namespace RayTracer {
    class AMaterial : public IMaterial {
        public:
        AMaterial();
        AMaterial(Math::Vector3D color);
        ~AMaterial();
        Math::Vector3D compute();

        Math::Vector3D getColor() const;
        void setColor(Math::Vector3D color);

        private:
        Math::Vector3D _color;
    };
}