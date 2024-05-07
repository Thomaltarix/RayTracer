/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.cpp
*/

#include "SFMLRenderer.hpp"

SFMLRenderer::SFMLRenderer()
{
    window.create(sf::VideoMode(800, 600), "RayTracer");
}

SFMLRenderer::SFMLRenderer(int width, int height)
{
    window.create(sf::VideoMode(width, height), "RayTracer");
}

SFMLRenderer::SFMLRenderer(const std::string &filename)
{
    this->loadPPM(filename);
}

void SFMLRenderer::display()
{
    window.clear();
    window.draw(this->getSprite());
    window.display();
}

void SFMLRenderer::loadPPM(const std::string &filename)
{
    _image.loadFromFile(filename);
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    window.create(sf::VideoMode(_image.getSize().x, _image.getSize().y), "RayTracer");
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

SFMLRenderer::~SFMLRenderer()
{
    window.close();
}
