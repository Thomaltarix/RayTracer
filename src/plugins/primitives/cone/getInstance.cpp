/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <iostream>
#include "Cone.hpp"

extern "C"
{
__attribute__((constructor))
static void initsharedlibrary()
{
    std::cout << "Loading Cone object ..." << std::endl;
}

Primitive::Cone *loadPrimitiveInstance()
{
    return new Primitive::Cone();
}

const std::string &getName(void)
{
    const static std::string name = "Cone";
    return name;
}

__attribute__((destructor))
static void destroysharedlibrary()
{
    std::cout << "Closing Cone object ..." << std::endl;
}
}
