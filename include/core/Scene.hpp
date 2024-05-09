/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#pragma once

#include "math/Vector3D.hpp"
#include "primitives/IPrimitive.hpp"
#include "core/Core.hpp"
#include "plugins/AMaterial.hpp"
#include "plugins/Sphere.hpp"
#include "plugins/Plane.hpp"
#include "plugins/3DAxis.hpp"
#include "plugins/Ambiant.hpp"
#include "errors/SceneException.hpp"
#include <iostream>
#include <memory>
#include <libconfig.h++>
#include <unordered_map>
#include <functional>
#include <vector>

namespace RayTracer {
    class Scene {
    public:
        /**
         * @brief Construct a new Scene object
         * This class is responsible for creating the scene from the configuration file.
         * @param path path to the configuration file
         * @param core pointer to the core object
         */
        Scene(std::string path, std::shared_ptr<Core> core);

        /**
         * @brief Destroy the Scene object
         * Destroy the Scene object and free the memory allocated for the primitives and lights.
         */
        ~Scene() = default;

        /**
         * @brief Create the primitives
         * Create the primitives from the configuration file.
         * @param cfg configuration file
         * @param core pointer to the core object
         */
        void createPrimitives(libconfig::Config &cfg, std::shared_ptr<Core> core);

        /**
         * @brief Create the camera
         * Create the camera from the configuration file.
         * @param camera configuration file
         */
        void createCamera(libconfig::Setting &camera);

        /**
         * @brief Create the lights
         * Create the lights from the configuration file.
         * @param lights configuration file
         * @param core pointer to the core object
         */
        void createLights(libconfig::Setting &lights, std::shared_ptr<Core> core);

        /**
         * @brief Create the spheres
         * Create the spheres from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createSpheres(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Create the planes
         * Create the planes from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createPlanes(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Get the Primitives object
         * Get the primitives from the configuration file.
         * @return std::vector<std::shared_ptr<IPrimitive>> primitives
         */
        std::vector<std::shared_ptr<RayTracer::IPrimitive>> getPrimitives() const;

        /**
         * @brief Get the Lights object
         * Get the lights from the configuration file.
         * @return std::vector<std::shared_ptr<ILight>> lights
         */
        std::vector<std::shared_ptr<RayTracer::ILight>> getLights() const;

    private:
        /**
         * @brief Create a Sphere object
         * Create a Sphere object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createSphere(libconfig::Setting &primitive, std::shared_ptr<Core> core);
        /**
         * @brief Create a Plane object
         * Create a Plane object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createPlane(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Get the Color object
         * Get the color from the configuration file.
         * @param setting configuration file
         * @return std::shared_ptr<Math::Vector3D> color
         */
        std::shared_ptr<Math::Vector3D> getColor(libconfig::Setting &setting);

        /** Map of primitive creators */
        std::unordered_map<std::string, std::function<void(libconfig::Setting &, std::shared_ptr<Core>)>> _primitiveCreators;

        /** Map of primitives */
        std::unordered_map<std::string, std::shared_ptr<IPrimitive>> _primitives;

        /** Map of lights */
        std::unordered_map<std::string, std::shared_ptr<ILight>> _lights;

        /** Camera object */
        // std::shared_ptr<Camera> _camera;
    };
}