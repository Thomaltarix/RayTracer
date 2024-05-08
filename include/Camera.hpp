/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "Ray.hpp"
#include "Rectangle3D.hpp"

namespace RayTracer {
    /**
     * @class Camera
     * @brief This class represents a camera in the RayTracer project.
     *
     * A Camera object contains an origin point and a screen rectangle.
     * It provides methods to create a default camera, create a camera with specific parameters, and generate a ray.
     */
    class Camera {
    private:
        /**
         * @brief The origin point of the camera in 3D space.
         */
        Math::Point3D origin;

        /**
         * @brief The screen rectangle that the camera is capturing.
         */
        Math::Rectangle3D screen;
    public:
        /**
         * @brief Default constructor. Creates a default camera.
         */
        Camera();

        /**
         * @brief Constructor. Creates a camera with the specified origin and screen.
         *
         * @param origin The origin point of the camera in 3D space.
         * @param screen The screen rectangle that the camera is capturing.
         */
        Camera(const Math::Point3D &origin, const Math::Rectangle3D &screen);

        /**
         * @brief Default destructor.
         */
        ~Camera() = default;

        /**
         * @brief Generates a ray from the camera through a point on the screen.
         *
         * @param u The horizontal coordinate of the point on the screen.
         * @param v The vertical coordinate of the point on the screen.
         * @return The generated ray.
         */
        [[nodiscard]] Math::Ray ray(double u, double v) const;
    };
}