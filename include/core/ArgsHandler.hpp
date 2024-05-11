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
    class ArgsHandler {
    public:
        ArgsHandler(int ac, char **av);
        ~ArgsHandler() = default;

        std::string getScenePath() const;
        bool isSFML() const;
        std::size_t isFastRender() const;
        bool isCanReload() const;
        int getTimeToReload() const;
        bool isDisplayWhileRendering() const;
        int getTimeToDisplay() const;

    private:
        void displayHelp();

        void parseArgs(int ac, char **av);

        std::string _scenePath;
        bool _sfml;
        std::size_t _fastRender;
        bool _canReload;
        int _timeToReload;
        bool _displayWhileRendering;
        int _timeToDisplay;
    };
}
