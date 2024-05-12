/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ArgsHandlerException
*/

#pragma once
#include "errors/IError.hpp"

namespace RayTracer {
    /**
     * @brief ArgsHandlerException class
     * This class is an exception class for the ArgsHandler
     */
    class ArgsHandlerException : public IError {
    public:
        /**
         * @brief Construct a new ArgsHandlerException object
         * Construct a new ArgsHandlerException object with a message.
         * @param message The message of the exception.
         */
        ArgsHandlerException(std::string const &message);

        /**
         * @brief Destroy the ArgsHandlerException object
         * Destroy the ArgsHandlerException object and free the memory allocated for the message.
         */
        ~ArgsHandlerException() override = default;

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

    /**
     * @brief ArgsHandlerInvalidArgException class
     * This class is an exception class for the ArgsHandler
     */
    class ArgsHandlerInvalidArgException : public ArgsHandlerException {
    public:
        /**
         * @brief Construct a new ArgsHandlerInvalidArgException object
         * Construct a new ArgsHandlerInvalidArgException object with a message.
         * @param message The message of the exception.
         */
        ArgsHandlerInvalidArgException(std::string const &message);

        /**
         * @brief Destroy the ArgsHandlerInvalidArgException object
         * Destroy the ArgsHandlerInvalidArgException object and free the memory allocated for the message.
         */
        ~ArgsHandlerInvalidArgException() override = default;
    };

    /**
     * @brief ArgsHandlerUnknownArgException class
     * This class is an exception class for the ArgsHandler
     */
    class ArgsHandlerUnknownArgException : public ArgsHandlerException {
    public:
        /**
         * @brief Construct a new ArgsHandlerUnknownArgException object
         * Construct a new ArgsHandlerUnknownArgException object with a message.
         * @param message The message of the exception.
         */
        ArgsHandlerUnknownArgException(std::string const &message);

        /**
         * @brief Destroy the ArgsHandlerUnknownArgException object
         * Destroy the ArgsHandlerUnknownArgException object and free the memory allocated for the message.
         */
        ~ArgsHandlerUnknownArgException() override = default;
    };

    /**
     * @brief ArgsHandlerMissingArgException class
     * This class is an exception class for the ArgsHandler
     */
    class ArgsHandlerMissingArgException : public ArgsHandlerException {
    public:
        /**
         * @brief Construct a new ArgsHandlerMissingArgException object
         * Construct a new ArgsHandlerMissingArgException object with a message.
         * @param message The message of the exception.
         */
        ArgsHandlerMissingArgException(std::string const &message);

        /**
         * @brief Destroy the ArgsHandlerMissingArgException object
         * Destroy the ArgsHandlerMissingArgException object and free the memory allocated for the message.
         */
        ~ArgsHandlerMissingArgException() override = default;
    };
}
