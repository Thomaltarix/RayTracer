/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "Plane.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading Plane object ..." << std::endl;
    }

    Primitive::Plane *loadPrimitiveInstance()
    {
        return new Primitive::Plane();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing Plane object ..." << std::endl;
    }
}
