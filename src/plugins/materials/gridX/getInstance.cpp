/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <iostream>
#include "GridX.hpp"

extern "C"
{
__attribute__((constructor))
static void initsharedlibrary()
{
    std::cout << "Loading GridX Material object ..." << std::endl;
}

Material::GridX *loadMaterialInstance()
{
    return new Material::GridX();
}

const std::string &getName(void)
{
    const static std::string name = "GridX";
    return name;
}

__attribute__((destructor))
static void destroysharedlibrary()
{
    std::cout << "Closing GridX Material object ..." << std::endl;
}
}
