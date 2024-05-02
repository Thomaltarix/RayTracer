/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** MathError
*/

#pragma once

#include <exception>
#include <string>

namespace Math {
    class MathError : public std::exception {
    public:
        MathError(std::string const &message);
        const char *what() const noexcept override;
    private:
        std::string _message;
    };
}
