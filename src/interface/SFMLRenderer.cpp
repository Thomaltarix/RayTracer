/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.cpp
*/

#include "SFMLRenderer.hpp"

RayTracer::SFMLRenderer::SFMLRenderer()
{
    window.create(sf::VideoMode(800, 600), "RayTracer");
}

RayTracer::SFMLRenderer::SFMLRenderer(int width, int height)
{
    window.create(sf::VideoMode(width, height), "RayTracer");
}

RayTracer::SFMLRenderer::SFMLRenderer(const std::string &filename)
{
    this->loadPPM(filename);
}

void RayTracer::SFMLRenderer::display()
{
    window.clear();
    window.draw(this->getSprite());
    window.display();
}

void RayTracer::SFMLRenderer::loadPPM(const std::string &filename)
{
    _image.loadFromFile(filename);
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    window.create(sf::VideoMode(_image.getSize().x, _image.getSize().y), "RayTracer");
}

sf::Image RayTracer::SFMLRenderer::getImage() const
{
    return _image;
}

void RayTracer::SFMLRenderer::setImage(const sf::Image &image)
{
    _image = image;
}

sf::Texture RayTracer::SFMLRenderer::getTexture() const
{
    return _texture;
}

void RayTracer::SFMLRenderer::setTexture(const sf::Texture &texture)
{
    _texture = texture;
}

sf::Sprite RayTracer::SFMLRenderer::getSprite() const
{
    return _sprite;
}

void RayTracer::SFMLRenderer::setSprite(const sf::Sprite &sprite)
{
    _sprite = sprite;
}

int RayTracer::SFMLRenderer::getWidth() const
{
    return _width;
}

void RayTracer::SFMLRenderer::setWidth(int width)
{
    _width = width;
}

int RayTracer::SFMLRenderer::getHeight() const
{
    return _height;
}

void RayTracer::SFMLRenderer::setHeight(int height)
{
    _height = height;
}

RayTracer::SFMLRenderer::~SFMLRenderer()
{
    window.close();
}
