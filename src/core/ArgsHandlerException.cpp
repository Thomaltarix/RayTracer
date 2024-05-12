/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ArgsHandlerException
*/

#include "core/ArgsHandlerException.hpp"

RayTracer::ArgsHandlerException::ArgsHandlerException(std::string const &message)
{
    this->_message = message;
}

const char *RayTracer::ArgsHandlerException::what() const noexcept
{
    return this->_message.c_str();
}

RayTracer::ArgsHandlerInvalidArgException::ArgsHandlerInvalidArgException(std::string const &message)
    : ArgsHandlerException(message)
{
}

RayTracer::ArgsHandlerMissingArgException::ArgsHandlerMissingArgException(std::string const &message)
    : ArgsHandlerException(message)
{
}

RayTracer::ArgsHandlerUnknownArgException::ArgsHandlerUnknownArgException(std::string const &message)
    : ArgsHandlerException(message)
{
}
