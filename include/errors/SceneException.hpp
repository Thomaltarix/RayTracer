/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneException
*/

#pragma once

#include "IError.hpp"

namespace RayTracer {
    /**
     * @brief SceneException class
     * This class is an exception class for the Scene
     */
    class SceneException : public IError {
    public:
        /**
         * @brief Construct a new SceneException object
         * Construct a new SceneException object with a message.
         * @param message The message of the exception.
         */
        SceneException(std::string const &message);

        /**
         * @brief Destroy the SceneException object
         * Destroy the SceneException object and free the memory allocated for the message.
         */
        ~SceneException() override = default;

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
     * @brief SceneMissingCameraException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneMissingCameraException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneMissingCameraException object
         * Construct a new SceneMissingCameraException object with a message.
         * @param message The message of the exception.
         */
        SceneMissingCameraException(std::string const &message);

        /**
         * @brief Destroy the SceneMissingCameraException object
         * Destroy the SceneMissingCameraException object and free the memory allocated for the message.
         */
        ~SceneMissingCameraException() override = default;
    };

    /**
     * @brief SceneMissingLightException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneMissingLightException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneMissingLightException object
         * Construct a new SceneMissingLightException object with a message.
         * @param message The message of the exception.
         */
        SceneMissingLightException(std::string const &message);

        /**
         * @brief Destroy the SceneMissingLightException object
         * Destroy the SceneMissingLightException object and free the memory allocated for the message.
         */
        ~SceneMissingLightException() override = default;
    };

    /**
     * @brief SceneParseError class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneParseError : public SceneException {
    public:
        /**
         * @brief Construct a new SceneParseError object
         * Construct a new SceneParseError object with a message.
         * @param message The message of the exception.
         */
        SceneParseError(std::string const &message);

        /**
         * @brief Destroy the SceneParseError object
         * Destroy the SceneParseError object and free the memory allocated for the message.
         */
        ~SceneParseError() override = default;
    };

    /**
     * @brief SceneCameraException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneCameraException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneCameraException object
         * Construct a new SceneCameraException object with a message.
         * @param message The message of the exception.
         */
        SceneCameraException(std::string const &message);

        /**
         * @brief Destroy the SceneCameraException object
         * Destroy the SceneCameraException object and free the memory allocated for the message.
         */
        ~SceneCameraException() override = default;
    };

    /**
     * @brief SceneLightException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneLightException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneLightException object
         * Construct a new SceneLightException object with a message.
         * @param message The message of the exception.
         */
        SceneLightException(std::string const &message);

        /**
         * @brief Destroy the SceneLightException object
         * Destroy the SceneLightException object and free the memory allocated for the message.
         */
        ~SceneLightException() override = default;
    };

    /**
     * @brief SceneDuplicateNameException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneDuplicateNameException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneDuplicateNameException object
         * Construct a new SceneDuplicateNameException object with a message.
         * @param message The message of the exception.
         */
        SceneDuplicateNameException(std::string const &message);

        /**
         * @brief Destroy the SceneDuplicateNameException object
         * Destroy the SceneDuplicateNameException object and free the memory allocated for the message.
         */
        ~SceneDuplicateNameException() override = default;
    };

    /**
     * @brief SceneUnknownObjectException class
     * This class is an exception class for the Scene
     * It inherits from SceneException
     */
    class SceneUnknownObjectException : public SceneException {
    public:
        /**
         * @brief Construct a new SceneUnknownObjectException object
         * Construct a new SceneUnknownObjectException object with a message.
         * @param message The message of the exception.
         */
        SceneUnknownObjectException(std::string const &message);

        /**
         * @brief Destroy the SceneUnknownObjectException object
         * Destroy the SceneUnknownObjectException object and free the memory allocated for the message.
         */
        ~SceneUnknownObjectException() override = default;
    };
}
