/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "Sphere.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading Sphere object ..." << std::endl;
    }

    Primitive::Sphere *loadPrimitiveInstance()
    {
        return new Primitive::Sphere();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing Sphere object ..." << std::endl;
    }
}
