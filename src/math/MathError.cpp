/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** MathError
*/

#include "MathError.hpp"

Math::MathError::MathError(std::string const &message)
{
    this->_message = message;
}

const char *Math::MathError::what() const noexcept
{
    return this->_message.c_str();
}

Math::MathDivideByZeroError::MathDivideByZeroError(std::string const &message) : MathError(message)
{
}
