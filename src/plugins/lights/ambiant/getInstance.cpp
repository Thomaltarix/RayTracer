/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "Ambiant.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading AmbiantLight object ..." << std::endl;
    }

    Light::Ambiant *loadLightInstance()
    {
        return new Light::Ambiant();
    }

    const std::string &getName(void) {
        const static std::string name = "AmbiantLight";
        return name;
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing AmbiantLight object ..." << std::endl;
    }
}
