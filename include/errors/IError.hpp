/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IError
*/

#pragma once

#include <iostream>
#include <exception>

/**
 * @brief Interface for error handling.
 * Interface for error handling, it is used to handle errors in the program.
 */
class IError : public std::exception {
    public:
        /**
         * @brief Destroy the IError object
         * Destroy the IError object and free the memory allocated for the message.
         */
        ~IError() = default;

        /**
         * @brief Get the message
         * Get the message of the error.
         * @return The message of the error.
         */
        const char *what() const noexcept override = 0;
};
