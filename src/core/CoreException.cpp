/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** CoreException
*/

#include "errors/CoreException.hpp"

RayTracer::CoreException::CoreException(std::string const &message)
{
    this->_message = message;
}

const char *RayTracer::CoreException::what() const noexcept
{
    return this->_message.c_str();
}

RayTracer::CoreLoadPluginException::CoreLoadPluginException(std::string const &message) : CoreException(message)
{
}

RayTracer::CoreUnknownPrimitiveException::CoreUnknownPrimitiveException(std::string const &message) : CoreException(message)
{
}

RayTracer::CoreUnknownLightException::CoreUnknownLightException(std::string const &message) : CoreException(message)
{
}

RayTracer::CoreUnknownMaterialException::CoreUnknownMaterialException(std::string const &message) : CoreException(message)
{
}
