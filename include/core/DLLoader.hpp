/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DLLoader
*/

#pragma once

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <string>
#include "errors/DLLoaderException.hpp"

/**
 * @brief Class representing a dynamic library loader.
 * This class is used to load a dynamic library and get an instance of a class from it.
 * It encapsulates the dlopen and dlsym functions.
 *
 * @tparam T Type of the class to get from the dynamic library
 */
template <typename T>
class DLLoader {
public:

    /**
     * @brief Construct a new DLLoader object
     * This class is used to load a dynamic library and get an instance of a class from it.
     * It encapsulates the dlopen and dlsym functions.
     *
     * @param libPath path to the dynamic library
     * @param entryPointName name of the function to call to get an instance of the class
     */
    DLLoader(std::string const &libPath, std::string const &entryPointName): getPluginName(nullptr), _handle(nullptr), _entryPoint(nullptr)
    {
        this->_handle = dlopen(libPath.c_str(), RTLD_LAZY);
        if (!this->_handle) {
            throw DLLoaderException(dlerror());
        }
        this->_entryPoint = reinterpret_cast<T *(*)()>(dlsym(this->_handle, entryPointName.c_str()));
        if (!this->_entryPoint) {
            throw DLLoaderException(dlerror());
        }
        this->getPluginName = reinterpret_cast<const std::string &(*)()>(dlsym(this->_handle, "getName"));
        if (!this->getPluginName) {
            throw DLLoaderException(dlerror());
        }
    }

    /**
     * @brief Destroy the DLLoader object
     * Close the dynamic library
     */
    ~DLLoader() {
        dlclose(this->_handle);
    }

    /**
     * @brief Get the Instance object
     * Get an instance of the class from the dynamic library
     * @return T* instance of the class
     */
    T *getInstance() {
        return this->_entryPoint();
    }

    /**
     * @brief Get the Plugin Name object
     * Get the name of the plugin
     * @return const std::string& name of the plugin
     */
    const std::string &(*getPluginName)();

private:
    /** Handle to the dynamic library */
    void *_handle;
    /** Entry point to get an instance of the class */
    T *(*_entryPoint)();
};
