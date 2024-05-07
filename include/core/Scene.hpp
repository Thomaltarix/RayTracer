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

namespace RayTracer {
    class Scene {
    public:
        /**
         * @brief Construct a new Scene object
         * This class is responsible for creating the scene from the configuration file.
         * @param path path to the configuration file
         * @param core pointer to the core object
         */
        Scene(std::string path, Core *core);

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
        void createPrimitives(libconfig::Config &cfg, Core *core);

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
        void createLights(libconfig::Setting &lights, Core *core);

        /**
         * @brief Create the spheres
         * Create the spheres from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createSpheres(libconfig::Setting &primitives, Core *core);

        /**
         * @brief Create the planes
         * Create the planes from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createPlanes(libconfig::Setting &primitives, Core *core);

    private:
        /**
         * @brief Create a Sphere object
         * Create a Sphere object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createSphere(libconfig::Setting &primitive, Core *core);

        /**
         * @brief Create a Plane object
         * Create a Plane object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createPlane(libconfig::Setting &primitive, Core *core);

        /**
         * @brief Create a 3DAxis object
         * Create a 3DAxis object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        Math::Vector3D *getColor(libconfig::Setting &setting);

        /** Map of primitive creators */
        std::unordered_map<std::string, std::function<void(libconfig::Setting &, Core *)>> _primitiveCreators;

        /** Map of primitives */
        std::unordered_map<std::string, IPrimitive *> _primitives;

        /** Map of lights */
        std::unordered_map<std::string, ILight *> _lights;

        /** Camera object */
        // std::shared_ptr<Camera> _camera;
    };
}
