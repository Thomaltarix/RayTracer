/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SafePluginsLister
*/

#include "core/SafePluginsLister.hpp"

Utils::SafePluginsLister::SafePluginsLister(std::string const &path)
{
    this->_path = path;
    this->_dir = opendir(this->_path.c_str());
    if (!this->_dir)
        throw OpenDirException("Error: could not open directory");
    this->_ent = nullptr;
}

Utils::SafePluginsLister::~SafePluginsLister()
{
    if (this->_dir)
        closedir(this->_dir);
}

std::string Utils::SafePluginsLister::getNextFile()
{
    std::string filename;

    if (!this->_dir)
        throw OpenDirException("Error: could not open directory");
    this->_ent = readdir(this->_dir);
    if (!this->_ent)
        throw NoMoreFilesException("Error: no more files in directory");
    if (this->_ent->d_name[0] == '.')
        return this->getNextFile();
    filename = this->_ent->d_name;
    if (filename.find(".so") == std::string::npos)
        return this->getNextFile();
    return filename;
}

Utils::SafePluginsListerException::SafePluginsListerException(std::string const &message)
{
    this->_message = message;
}

const char *Utils::SafePluginsListerException::what() const noexcept
{
    return this->_message.c_str();
}

Utils::NoMoreFilesException::NoMoreFilesException(std::string const &message) : SafePluginsListerException(message)
{
}

Utils::OpenDirException::OpenDirException(std::string const &message) : SafePluginsListerException(message)
{
}
