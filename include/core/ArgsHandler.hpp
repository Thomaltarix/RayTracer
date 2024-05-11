/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ArgsHandler
*/

#pragma once

#include <iostream>
#include "core/ArgsHandlerException.hpp"

namespace RayTracer {
    /**
     * @brief ArgsHandler class
     * This class is used to handle the arguments of the program
     */
    class ArgsHandler {
    public:
        /**
         * @brief Construct a new ArgsHandler object
         * Construct a new ArgsHandler object with the arguments of the program.
         * @param ac The number of arguments.
         * @param av The arguments.
         */
        ArgsHandler(int ac, char **av);

        /**
         * @brief Destroy the ArgsHandler object
         * Destroy the ArgsHandler object and free the memory allocated for the arguments.
         */
        ~ArgsHandler() = default;

        /**
         * @brief Get the scene path
         * Get the path of the scene file.
         * @return The path of the scene file.
         */
        std::string getScenePath() const;

        /**
         * @brief Check if the program is using SFML
         * Check if the program is using SFML.
         * @return True if the program is using SFML, false otherwise.
         */
        bool isSFML() const;

        /**
         * @brief Check if the program is using fast render
         * Check if the program is using fast render.
         * @return True if the program is using fast render, false otherwise.
         */
        std::size_t isFastRender() const;

        /**
         * @brief Check if the program can reload the scene
         * Check if the program can reload the scene.
         * @return True if the program can reload the scene, false otherwise.
         */
        bool isCanReload() const;

        /**
         * @brief Get the time to reload
         * Get the time to reload the scene.
         * @return The time to reload the scene.
         */
        int getTimeToReload() const;

        /**
         * @brief Check if the program is displaying while rendering
         * Check if the program is displaying while rendering.
         * @return True if the program is displaying while rendering, false otherwise.
         */
        bool isDisplayWhileRendering() const;

        /**
         * @brief Get the time to display
         * Get the time to display the scene.
         * @return The time to display the scene.
         */
        int getTimeToDisplay() const;

    private:
        /**
         * @brief Display the help
         * Display the help of the program.
         */
        void displayHelp();

        /**
         * @brief Parse the arguments
         * Parse the arguments of the program.
         * @param ac The number of arguments.
         * @param av The arguments.
         */
        void parseArgs(int ac, char **av);

        /** The path of the scene file. */
        std::string _scenePath;

        /** True if the program is using SFML, false otherwise. */
        bool _sfml;

        /** True if the program is using fast render, false otherwise. */
        std::size_t _fastRender;

        /** True if the program can reload the scene, false otherwise. */
        bool _canReload;

        /** The time to reload the scene. */
        int _timeToReload;

        /** True if the program is displaying while rendering, false otherwise. */
        bool _displayWhileRendering;

        /** The time to display the scene. */
        int _timeToDisplay;
    };
}
