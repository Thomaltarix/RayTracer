/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DLLoaderException
*/

#include "errors/DLLoaderException.hpp"

DLLoaderException::DLLoaderException(std::string const &message)
{
    this->_message = message;
}

const char *DLLoaderException::what() const noexcept
{
    return this->_message.c_str();
}
