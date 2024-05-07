/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** getInstance
*/

#include <iostream>
#include "FlatColor.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading FlatColor object ..." << std::endl;
    }

    Material::FlatColor *loadMaterialInstance()
    {
        return new Material::FlatColor();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Closing FlatColor object ..." << std::endl;
    }
}