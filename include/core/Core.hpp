/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Core
*/

#pragma once

#include <iostream>
#include "primitives/IPrimitive.hpp"
#include "lights/ILight.hpp"
#include "materials/IMaterial.hpp"
#include "core/DLLoader.hpp"
#include "core/SafePluginsLister.hpp"
#include "errors/CoreException.hpp"
#include <unordered_map>
#include <memory>

namespace RayTracer {

    /**
     * @brief The Core class
     * This class is the core of the RayTracer.
     * It is responsible for loading plugins and
     * creating instances of primitives, lights and materials.
     */
    class Core {
    public:
        /**
         * @brief Construct a new Core object
         * This class is the core of the RayTracer.
         * It is responsible for loading plugins and
         * creating instances of primitives, lights and materials.
         *
         */
        Core();

        /**
         * @brief Destroy the Core object
         * Destroy the Core object and free the memory allocated for the plugins.
         */
        ~Core();

        /**
         * @brief Load the plugins
         * Load the plugins from the plugins directory.
         */
        void loadPlugins();

        /**
         * @brief Scan the primitives plugins
         * Scan the primitives from the plugins directory.
         */
        void scanPrimitives();

        /**
         * @brief Scan the lights plugins
         * Scan the lights from the plugins directory.
         */
        void scanLights();

        /**
         * @brief Scan the materials plugins
         * Scan the materials from the plugins directory.
         */
        void scanMaterials();

        /**
         * @brief Factory method for materials
         * Create an instance of a material from the given name.
         *
         * @param name Name of the material to create
         * @return std::shared_ptr<IMaterial> Instance of the material
         */
        std::shared_ptr<IMaterial> factoryMaterial(std::string const &name);

    private:
        /** Map of primitives */
        std::unordered_map<std::string, DLLoader<IPrimitive> *> _primitives;
        /** Map of lights */
        std::unordered_map<std::string, DLLoader<ILight> *> _lights;
        /** Map of materials */
        std::unordered_map<std::string, DLLoader<IMaterial> *> _materials;
    };
}
