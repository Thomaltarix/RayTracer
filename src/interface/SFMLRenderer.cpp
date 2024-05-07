/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.cpp
*/

#include "SFMLRenderer.hpp"

SFMLRenderer::SFMLRenderer()
{
    _window.create(sf::VideoMode(800, 600), "RayTracer");
}

SFMLRenderer::SFMLRenderer(int width, int height)
{
    _window.create(sf::VideoMode(width, height), "RayTracer");
}

SFMLRenderer::SFMLRenderer(const std::string &filename)
{
    this->loadPPM(filename);
}

void SFMLRenderer::display()
{
    _window.clear();
    sf::Sprite sprite(_texture);

    this->setSprite(sprite);
    _window.draw(this->getSprite());
    _window.display();
}

void SFMLRenderer::loadPPM(const std::string &filename)
{
    sf::Image image;
    image.loadFromFile(filename);
    this->setImage(image);

    sf::Texture texture;
    texture.loadFromImage(image);
    this->setTexture(texture);
    this->setWidth(image.getSize().x);
    this->setHeight(image.getSize().y);
    _window.create(sf::VideoMode(this->getWidth(), this->getHeight()), "RayTracer");
}

sf::Image SFMLRenderer::getImage() const
{
    return _image;
}

void SFMLRenderer::setImage(const sf::Image &image)
{
    _image = image;
}

sf::Texture SFMLRenderer::getTexture() const
{
    return _texture;
}

void SFMLRenderer::setTexture(const sf::Texture &texture)
{
    _texture = texture;
}

sf::Sprite SFMLRenderer::getSprite() const
{
    return _sprite;
}

void SFMLRenderer::setSprite(const sf::Sprite &sprite)
{
    _sprite = sprite;
}

int SFMLRenderer::getWidth() const
{
    return _width;
}

void SFMLRenderer::setWidth(int width)
{
    _width = width;
}

int SFMLRenderer::getHeight() const
{
    return _height;
}

void SFMLRenderer::setHeight(int height)
{
    _height = height;
}
