/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Core
*/

#include "core/Core.hpp"
#include <memory>

RayTracer::Core::Core()
{
    this->loadPlugins();
}

RayTracer::Core::~Core()
{
    for (auto &it : this->_primitives) {
        delete it.second;
    }
    for (auto &it : this->_lights) {
        delete it.second;
    }
    for (auto &it : this->_materials) {
        delete it.second;
    }
}

void RayTracer::Core::scanPrimitives()
{
    Utils::SafePluginsLister lister("./plugins/primitives");

    try {
        while (1) {
            std::string path = "./plugins/primitives/" + lister.getNextFile();
            try {
                DLLoader<IPrimitive> *loader = new DLLoader<IPrimitive>(path, "loadPrimitiveInstance");
                this->_primitives[loader->getPluginName()] = loader;
            } catch (DLLoaderException &e) {
                std::cerr << path << ": " << e.what() << std::endl;
            }
        }
    } catch (Utils::NoMoreFilesException &e) {
        return;
    }
}

void RayTracer::Core::scanLights()
{
    Utils::SafePluginsLister lister("./plugins/lights");

    try {
        while (1) {
            std::string path = "./plugins/lights/" + lister.getNextFile();
            try {
                DLLoader<ILight> *loader = new DLLoader<ILight>(path, "loadLightInstance");
                this->_lights[loader->getPluginName()] = loader;
            } catch (DLLoaderException &e) {
                std::cerr << path << ": " << e.what() << std::endl;
            }
        }
    } catch (Utils::NoMoreFilesException &e) {
        return;
    }
}

void RayTracer::Core::scanMaterials()
{
    Utils::SafePluginsLister lister("./plugins/materials");

    try {
        while (1) {
            std::string path = "./plugins/materials/" + lister.getNextFile();
            try {
                DLLoader<IMaterial> *loader = new DLLoader<IMaterial>(path, "loadMaterialInstance");
                this->_materials[loader->getPluginName()] = loader;
            } catch (DLLoaderException &e) {
                std::cerr << path << ": " << e.what() << std::endl;
            }
        }
    } catch (Utils::NoMoreFilesException &e) {
        return;
    }
}

void RayTracer::Core::loadPlugins()
{
    this->scanPrimitives();
    this->scanLights();
    this->scanMaterials();
}

std::shared_ptr<RayTracer::IPrimitive> RayTracer::Core::factoryPrimitive(std::string const &name)
{
    if (this->_primitives.find(name) == this->_primitives.end()) {
        throw CoreUnknownPrimitiveException("Unknown primitive: " + name);
    }
    std::shared_ptr<IPrimitive> primitive(this->_primitives[name]->getInstance());
    return primitive;
}

std::shared_ptr<RayTracer::ILight> RayTracer::Core::factoryLight(std::string const &name)
{
    if (this->_lights.find(name) == this->_lights.end()) {
        throw CoreUnknownLightException("Unknown light: " + name);
    }
    std::shared_ptr<ILight> light(this->_lights[name]->getInstance());
    return light;
}

std::shared_ptr<RayTracer::IMaterial> RayTracer::Core::factoryMaterial(std::string const &name)
{
    if (this->_materials.find(name) == this->_materials.end()) {
        throw CoreUnknownMaterialException("Unknown material: " + name);
    }
    std::shared_ptr<IMaterial> material(this->_materials[name]->getInstance());
    return material;
}
