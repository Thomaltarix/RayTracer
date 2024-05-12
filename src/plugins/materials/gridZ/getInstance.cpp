/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <iostream>
#include "GridZ.hpp"

extern "C"
{
__attribute__((constructor))
static void initsharedlibrary()
{
    std::cout << "Loading GridZ Material object ..." << std::endl;
}

Material::GridZ *loadMaterialInstance()
{
    return new Material::GridZ();
}

const std::string &getName(void)
{
    const static std::string name = "GridZ";
    return name;
}

__attribute__((destructor))
static void destroysharedlibrary()
{
    std::cout << "Closing GridZ Material object ..." << std::endl;
}
}
