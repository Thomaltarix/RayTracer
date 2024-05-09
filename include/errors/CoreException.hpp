/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** CoreException
*/

#pragma once

#include "IError.hpp"

namespace RayTracer {
    /**
     * @brief CoreException class
     * This class is an exception class for the core
     * It inherits from IError
     */
    class CoreException : public IError {
    public:
        /**
         * @brief Construct a new CoreException object
         * Construct a new CoreException object with a message.
         * @param message The message of the exception.
         */
        CoreException(std::string const &message);

        /**
         * @brief Destroy the CoreException object
         * Destroy the CoreException object and free the memory allocated for the message.
         */
        ~CoreException() override = default;

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
     * @brief CoreLoadPluginException class
     * This class is an exception class for the core
     * It inherits from IError
     */
    class CoreLoadPluginException : public CoreException {
    public:
        /**
         * @brief Construct a new CoreLoadPluginException object
         * Construct a new CoreLoadPluginException object with a message.
         * @param message The message of the exception.
         */
        CoreLoadPluginException(std::string const &message);

        /**
         * @brief Destroy the CoreLoadPluginException object
         * Destroy the CoreLoadPluginException object and free the memory allocated for the message.
         */
        ~CoreLoadPluginException() override = default;
    };

    /**
     * @brief CoreUnknownPrimitiveException class
     * This class is an exception class for the core
     * It inherits from IError
     */
    class CoreUnknownPrimitiveException : public CoreException {
    public:
        /**
         * @brief Construct a new CoreUnknownPrimitiveException object
         * Construct a new CoreUnknownPrimitiveException object with a message.
         * @param message The message of the exception.
         */
        CoreUnknownPrimitiveException(std::string const &message);

        /**
         * @brief Destroy the CoreUnknownPrimitiveException object
         * Destroy the CoreUnknownPrimitiveException object and free the memory allocated for the message.
         */
        ~CoreUnknownPrimitiveException() override = default;
    };

    /**
     * @brief CoreUnknownLightException class
     * This class is an exception class for the core
     * It inherits from IError
     */
    class CoreUnknownLightException : public CoreException {
    public:
        /**
         * @brief Construct a new CoreUnknownLightException object
         * Construct a new CoreUnknownLightException object with a message.
         * @param message The message of the exception.
         */
        CoreUnknownLightException(std::string const &message);

        /**
         * @brief Destroy the CoreUnknownLightException object
         * Destroy the CoreUnknownLightException object and free the memory allocated for the message.
         */
        ~CoreUnknownLightException() override = default;
    };

    /**
     * @brief CoreUnknownMaterialException class
     * This class is an exception class for the core
     * It inherits from IError
     */
    class CoreUnknownMaterialException : public CoreException {
    public:
        /**
         * @brief Construct a new CoreUnknownMaterialException object
         * Construct a new CoreUnknownMaterialException object with a message.
         * @param message The message of the exception.
         */
        CoreUnknownMaterialException(std::string const &message);

        /**
         * @brief Destroy the CoreUnknownMaterialException object
         * Destroy the CoreUnknownMaterialException object and free the memory allocated for the message.
         */
        ~CoreUnknownMaterialException() override = default;
    };
}
