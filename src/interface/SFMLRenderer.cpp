/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.cpp
*/

#include "interface/SFMLRenderer.hpp"

RayTracer::SFMLRenderer::SFMLRenderer()
{
    this->window.create(sf::VideoMode(800, 600), "RayTracer");
    this->_image.create(800, 600, sf::Color::Black);
}

RayTracer::SFMLRenderer::SFMLRenderer(int width, int height)
{
    this->window.create(sf::VideoMode(width, height), "RayTracer");
    this->_image.create(width, height, sf::Color::Black);
    this->_clock = std::make_unique<sf::Clock>();
}

RayTracer::SFMLRenderer::~SFMLRenderer()
{
    this->window.close();
}

void RayTracer::SFMLRenderer::display(double timeBeforeUpdating)
{
    window.clear();
    if (this->_clock->getElapsedTime().asSeconds() > timeBeforeUpdating) {
        this->updateTexture();
        this->_clock->restart();
    }
    window.draw(this->_sprite);
    window.display();
}

void RayTracer::SFMLRenderer::clear()
{
    this->_image.create(this->_width, this->_height, sf::Color::Black);
    this->_texture.loadFromImage(this->_image);
    this->_sprite.setTexture(this->_texture);
}

void RayTracer::SFMLRenderer::updateTexture()
{
    this->_texture.loadFromImage(this->_image);
    this->_sprite.setTexture(this->_texture);
}

void RayTracer::SFMLRenderer::handleEvents()
{
    sf::Event event;
    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->window.close();
            throw SFMLCLoseWindowException("Window closed");
        }
    }
}

void RayTracer::SFMLRenderer::setPixel(unsigned int x, unsigned int y, Math::Point3D color)
{
    this->_image.setPixel(x, y, this->point3DToColor(color));
}

void RayTracer::SFMLRenderer::setPixel(unsigned int x, unsigned int y, Math::Vector3D color)
{
    this->_image.setPixel(x, y, this->vector3DToColor(color));
}

Math::Point3D RayTracer::SFMLRenderer::getPixel(unsigned int x, unsigned int y)
{
    sf::Color color = this->_image.getPixel(x, y);

    return Math::Point3D(color.r, color.g, color.b);
}

sf::Color RayTracer::SFMLRenderer::point3DToColor(Math::Point3D color)
{
    return sf::Color(color.x, color.y, color.z);
}

sf::Color RayTracer::SFMLRenderer::vector3DToColor(Math::Vector3D color)
{
    return sf::Color(color.x, color.y, color.z);
}

Math::Point3D RayTracer::SFMLRenderer::colorToPoint3D(sf::Color color)
{
    return Math::Point3D(color.r, color.g, color.b);
}

Math::Vector3D RayTracer::SFMLRenderer::colorToVector3D(sf::Color color)
{
    return Math::Vector3D(color.r, color.g, color.b);
}

/**  GETTER AND SETTER  **/

sf::Image RayTracer::SFMLRenderer::getImage() const
{
    return this->_image;
}

void RayTracer::SFMLRenderer::setImage(const sf::Image &image)
{
    this->_image = image;
}

sf::Texture RayTracer::SFMLRenderer::getTexture() const
{
    return this->_texture;
}

void RayTracer::SFMLRenderer::setTexture(const sf::Texture &texture)
{
    this->_texture = texture;
}

sf::Sprite RayTracer::SFMLRenderer::getSprite() const
{
    return this->_sprite;
}

void RayTracer::SFMLRenderer::setSprite(const sf::Sprite &sprite)
{
    this->_sprite = sprite;
}

int RayTracer::SFMLRenderer::getWidth() const
{
    return this->_width;
}

void RayTracer::SFMLRenderer::setWidth(int width)
{
    this->_width = width;
}

int RayTracer::SFMLRenderer::getHeight() const
{
    return this->_height;
}

void RayTracer::SFMLRenderer::setHeight(int height)
{
    this->_height = height;
}
