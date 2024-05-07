/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DLLoaderException
*/

#pragma once

#include "IError.hpp"

class DLLoaderException : public IError {
    public:
        DLLoaderException(std::string const &message);
        const char *what() const noexcept;

    private:
        std::string _message;
};