/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "Directional.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading DirectionalLight object ..." << std::endl;
    }

    Light::Directional *loadLightInstance()
    {
        return new Light::Directional();
    }

    const std::string &getName(void) {
        const static std::string name = "DirectionalLight";
        return name;
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing DirectionalLight object ..." << std::endl;
    }
}
