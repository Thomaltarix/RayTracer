/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ALight.hpp
*/

#pragma once

#include "lights/ILight.hpp"

namespace RayTracer {

    class ALight : public ILight {
        public:
        ALight();
        ALight(float intensity);
        ALight(float intensity, bool doesShadowcast);
        ~ALight();

        float getIntensity() const;
        void setIntensity(float intensity);

        bool doesShadowcast() const;
        void setShadowcast(bool doesShadowcast);

        Math::Vector3D Illuminate(Math::Point3D point, IMaterial material);
        bool InShadow(Math::Point3D point);

        protected:
        float _intensity;
        bool _doesShadowcast;
    };
}