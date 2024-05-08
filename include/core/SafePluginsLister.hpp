/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SafePluginsLister
*/

#pragma once

#include <iostream>
#include <dirent.h>
#include <cstring>
#include "../errors/IError.hpp"

namespace Utils {
    /**
     * @brief Safe Plugins Lister class
     * This class is responsible for listing the files in a directory.
     * It is used to safely list the files in a directory.
     * @see SafePluginsListerException
     */
    class SafePluginsLister {
    public:
        /**
         * @brief Construct a new Safe Plugins Lister object
         * This class is responsible for listing the files in a directory.
         * It is used to safely list the files in a directory.
         * @param path path to the directory
         */
        SafePluginsLister(std::string const &path);

        /**
         * @brief Destroy the Safe Plugins Lister object
         * Destroy the Safe Plugins Lister object.
         */
        ~SafePluginsLister();

        /**
         * @brief Get the next file
         * Get the next file in the directory.
         * @return std::string next file
         */
        std::string getNextFile();

    private:
        /** Path to the directory */
        std::string _path;

        /** Directory pointer */
        DIR *_dir;

        /** Directory entry */
        struct dirent *_ent;
    };

    /**
     * @brief Safe Plugins Lister Exception class
     * This class is responsible for handling exceptions thrown by
     * the SafePluginsLister class.
     * @see SafePluginsLister
     */
    class SafePluginsListerException : public IError {
    public:
        /**
         * @brief Construct a new Safe Plugins Lister Exception object
         * This class is responsible for handling exceptions thrown by
         * the SafePluginsLister class.
         * @param message error message
         */
        SafePluginsListerException(std::string const &message);

        /**
         * @brief Destroy the Safe Plugins Lister Exception object
         * Destroy the Safe Plugins Lister Exception object.
         */
        ~SafePluginsListerException() override = default;

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

    /**
     * @brief No More Files Exception class
     * This class is responsible for handling exceptions thrown by the
     * SafePluginsLister class when there are no more files to read.
     * @see SafePluginsLister
     */
    class NoMoreFilesException : public SafePluginsListerException {
    public:
        /**
         * @brief Construct a new No More Files Exception object
         * This class is responsible for handling exceptions thrown by the
         * SafePluginsLister class when there are no more files to read.
         * @param message error message
         */
        NoMoreFilesException(std::string const &message);

        /**
         * @brief Destroy the No More Files Exception object
         * Destroy the No More Files Exception object.
         */
        ~NoMoreFilesException() override = default;
    };

    /**
     * @brief Open Dir Exception class
     * This class is responsible for handling exceptions thrown by the
     * SafePluginsLister class when the directory could not be opened.
     * @see SafePluginsLister
     */
    class OpenDirException : public SafePluginsListerException {
    public:
        /**
         * @brief Construct a new Open Dir Exception object
         * This class is responsible for handling exceptions thrown by
         * the SafePluginsLister class when the directory could not be opened.
         * @param message error message
         */
        OpenDirException(std::string const &message);

        /**
         * @brief Destroy the Open Dir Exception object
         * Destroy the Open Dir Exception object.
         */
        ~OpenDirException() override = default;
    };
}
