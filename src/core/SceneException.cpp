/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneException
*/

#include "errors/SceneException.hpp"

RayTracer::SceneException::SceneException(std::string const &message)
{
    this->_message = message;
}

const char *RayTracer::SceneException::what() const noexcept
{
    return this->_message.c_str();
}

RayTracer::SceneMissingCameraException::SceneMissingCameraException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneMissingLightException::SceneMissingLightException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneParseError::SceneParseError(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneCameraException::SceneCameraException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneLightException::SceneLightException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneDuplicateNameException::SceneDuplicateNameException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneUnknownObjectException::SceneUnknownObjectException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneInvalidTransformationException::SceneInvalidTransformationException(std::string const &message) : SceneException(message)
{
}

RayTracer::SceneUnknownTransformationException::SceneUnknownTransformationException(std::string const &message) : SceneException(message)
{
}
