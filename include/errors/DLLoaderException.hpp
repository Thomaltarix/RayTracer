/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DLLoaderException
*/

#pragma once

#include "IError.hpp"

/**
 * @brief DLLoader Exception class
 * This class is responsible for handling exceptions thrown by
 * the DLLoader class.
 */
class DLLoaderException : public IError {
    public:
        /**
         * @brief Construct a new DLLoader Exception object
         * This class is responsible for handling exceptions thrown by
         * the DLLoader class.
         * @param message error message
         */
        DLLoaderException(std::string const &message);

        /**
         * @brief Destroy the DLLoader Exception object
         * Destroy the DLLoader Exception object.
         */
        ~DLLoaderException() override = default;

        /**
         * @brief Get the error message
         * Get the error message.
         * @return const char* error message
         */
        const char *what() const noexcept;

    private:
        /** Error message */
        std::string _message;
};
