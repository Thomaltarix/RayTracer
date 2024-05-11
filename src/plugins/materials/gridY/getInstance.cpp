/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <iostream>
#include "GridY.hpp"

extern "C"
{
__attribute__((constructor))
static void initsharedlibrary()
{
    std::cout << "Loading GridY Material object ..." << std::endl;
}

Material::GridY *loadMaterialInstance()
{
    return new Material::GridY();
}

const std::string &getName(void)
{
    const static std::string name = "GridY";
    return name;
}

__attribute__((destructor))
static void destroysharedlibrary()
{
    std::cout << "Closing GridY Material object ..." << std::endl;
}
}
