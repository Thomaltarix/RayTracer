/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLException
*/

#pragma once

#include "errors/IError.hpp"

namespace RayTracer {
    /**
     * @brief SFMLException class
     * This class is an exception class for the SFML
     */
    class SFMLException : public IError {
    public:
        /**
         * @brief Construct a new SFMLException object
         * Construct a new SFMLException object with a message.
         * @param message The message of the exception.
         */
        SFMLException(std::string const &message);

        /**
         * @brief Destroy the SFMLException object
         * Destroy the SFMLException object and free the memory allocated for the message.
         */
        ~SFMLException() override = default;

        /**
         * @brief Get the message
         * Get the message of the exception.
         * @return The message of the exception.
         */
        const char *what() const noexcept override;

    private:
        /** The message of the exception. */
        std::string _message;
    };

    class SFMLCLoseWindowException : public SFMLException {
    public:
        /**
         * @brief Construct a new SFMLCLoseWindowException object
         * Construct a new SFMLCLoseWindowException object with a message.
         * @param message The message of the exception.
         */
        SFMLCLoseWindowException(std::string const &message);

        /**
         * @brief Destroy the SFMLCLoseWindowException object
         * Destroy the SFMLCLoseWindowException object and free the memory allocated for the message.
         */
        ~SFMLCLoseWindowException() override = default;
    };
}
