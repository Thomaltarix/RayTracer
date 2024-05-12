/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLException
*/

#include "interface/SFMLException.hpp"

RayTracer::SFMLException::SFMLException(std::string const &message)
{
    this->_message = message;
}

const char *RayTracer::SFMLException::what() const noexcept
{
    return this->_message.c_str();
}

RayTracer::SFMLCLoseWindowException::SFMLCLoseWindowException(std::string const &message) : SFMLException(message)
{
}
