/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ArgsHandler
*/

#include "core/ArgsHandler.hpp"


RayTracer::ArgsHandler::ArgsHandler(int ac, char **av)
{
    this->_scenePath = "";
    this->_sfml = false;
    this->_fastRender = 0;
    this->_canReload = false;
    this->_timeToReload = 1;
    this->_displayWhileRendering = false;
    this->_timeToDisplay = 1;
    this->parseArgs(ac, av);
}

void RayTracer::ArgsHandler::parseArgs(int ac, char **av)
{
    if (ac < 2) {
        this->displayHelp();
        throw RayTracer::ArgsHandlerMissingArgException("Not enough arguments");
    }
    this->_scenePath = av[1];
    for (int i = 2; i < ac; i++) {
        if (std::string(av[i]) == "--SFML")
            this->_sfml = true;
        else if (std::string(av[i]) == "--fast") {
            i++;
            if (i < ac) {
                try {
                    this->_fastRender = std::stoi(av[i]);
                } catch (std::exception &e) {
                    throw ArgsHandlerInvalidArgException("Invalid time specified for --reload");
                }
            } else
                throw ArgsHandlerInvalidArgException("No time specified for --reload");
        } else if (std::string(av[i]) == "--reload") {
            this->_canReload = true;
            i++;
            if (i < ac) {
                try {
                    this->_timeToReload = std::stoi(av[i]);
                } catch (std::exception &e) {
                    throw ArgsHandlerInvalidArgException("Invalid time specified for --reload");
                }
            } else
                throw ArgsHandlerInvalidArgException("No time specified for --reload");
        } else if (std::string(av[i]) == "--display") {
            this->_displayWhileRendering = true;
            i++;
            if (i < ac) {
                try {
                    this->_timeToDisplay = std::stoi(av[i]);
                } catch (std::exception &e) {
                    throw ArgsHandlerInvalidArgException("Invalid time specified for --display");
                }
            } else
                throw ArgsHandlerInvalidArgException("No time specified for --display");
        } else if (std::string(av[i]) == "--help") {
            this->displayHelp();
            exit(0);
        } else {
            throw ArgsHandlerUnknownArgException("Unknown argument");
        }
    }
    if (!this->_sfml && (this->_displayWhileRendering || this->_displayWhileRendering || this->_fastRender))
        throw ArgsHandlerInvalidArgException("Cannot use --display, --reload or --fast without --SFML");
}

void RayTracer::ArgsHandler::displayHelp()
{
    std::cout << "Usage: ./raytracer [scene.cfg] [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --SFML: Display the scene with SFML" << std::endl;
    std::cout << "  --fast: Render the scene faster" << std::endl;
    std::cout << "  --reload [time]: Reload the config file every [time] seconds" << std::endl;
    std::cout << "  --display [time]: Display the scene while rendering every [time] seconds" << std::endl;
    std::cout << "  --help: Display this help" << std::endl;
}

std::string RayTracer::ArgsHandler::getScenePath() const
{
    return this->_scenePath;
}

bool RayTracer::ArgsHandler::isSFML() const
{
    return this->_sfml;
}

size_t RayTracer::ArgsHandler::isFastRender() const
{
    return this->_fastRender;
}

bool RayTracer::ArgsHandler::isCanReload() const
{
    return this->_canReload;
}

int RayTracer::ArgsHandler::getTimeToReload() const
{
    return this->_timeToReload;
}

bool RayTracer::ArgsHandler::isDisplayWhileRendering() const
{
    return this->_displayWhileRendering;
}

int RayTracer::ArgsHandler::getTimeToDisplay() const
{
    return this->_timeToDisplay;
}

