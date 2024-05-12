/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <iostream>
#include "Grid.hpp"

extern "C"
{
__attribute__((constructor))
static void initsharedlibrary()
{
    std::cout << "Loading Grid Material object ..." << std::endl;
}

Material::Grid *loadMaterialInstance()
{
    return new Material::Grid();
}

const std::string &getName(void)
{
    const static std::string name = "Grid";
    return name;
}

__attribute__((destructor))
static void destroysharedlibrary()
{
    std::cout << "Closing Grid Material object ..." << std::endl;
}
}
