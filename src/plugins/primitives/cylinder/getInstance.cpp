/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "Cylinder.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading Cylinder object ..." << std::endl;
    }

    Primitive::Cylinder *loadPrimitiveInstance()
    {
        return new Primitive::Cylinder();
    }

    const std::string &getName(void)
    {
        const static std::string name = "Cylinder";
        return name;
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing Cylinder object ..." << std::endl;
    }
}
