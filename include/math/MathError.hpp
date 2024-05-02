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
    /**
     * @brief Exception class for mathematical errors.
     */
    class MathError : public std::exception {
    public:
        /**
         * @brief Constructs a MathError object with the given error message.
         * @param message The error message.
         */
        MathError(std::string const &message);

        /**
         * @brief Returns a C-style string describing the exception.
         * @return A C-style string describing the exception.
         */
        const char *what() const noexcept override;

    private:

        /**< The error message. */
        std::string _message;
    };
}
