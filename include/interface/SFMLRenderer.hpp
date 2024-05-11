/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.hpp
*/

#pragma once

#include "math/Point3D.hpp"
#include "math/Vector3D.hpp"
#include "interface/SFMLException.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

namespace RayTracer {
    /**
     * @class SFMLRenderer
     * @brief The SFMLRenderer class is responsible for rendering images using SFML library.
     */
    class SFMLRenderer {
        public:
            /**
             * @brief Default constructor for SFMLRenderer.
             */
            SFMLRenderer();

            /**
             * @brief Constructor for SFMLRenderer with specified width and height.
             * @param width The width of the renderer.
             * @param height The height of the renderer.
             */
            SFMLRenderer(int width, int height);

            /**
             * @brief Destructor for SFMLRenderer.
             */
            ~SFMLRenderer();

            /**
             * @brief Displays the rendered image on the SFML window and waits for the specified time.
             * @param timeBeforeUpdating The time to wait before updating the window.
             */
            void display(double timeBeforeUpdating);

            /**
             * @brief Clears the rendered image on the SFML window.
             */
            void clear();

            /**
             * @brief Updates the texture used for rendering.
             */
            void updateTexture();

            /**
             * @brief Handles events for the SFML window.
             */
            void handleEvents();

            /**
             * @brief Sets the pixel at the specified coordinates to the specified color.
             * @param x The x coordinate of the pixel.
             * @param y The y coordinate of the pixel.
             * @param color The color of the pixel.
             */
            void setPixel(unsigned int x, unsigned int y, Math::Point3D color);

            /**
             * @brief Sets the pixel at the specified coordinates to the specified color.
             * @param x The x coordinate of the pixel.
             * @param y The y coordinate of the pixel.
             * @param color The color of the pixel.
             */
            void setPixel(unsigned int x, unsigned int y, Math::Vector3D color);

            /**
             * @brief Gets the pixel at the specified coordinates.
             * @param x The x coordinate of the pixel.
             * @param y The y coordinate of the pixel.
             * @return The color of the pixel.
             */
            Math::Point3D getPixel(unsigned int x, unsigned int y);

            /**
             * @brief Gets the image used for rendering.
             * @return The SFML image object.
             */
            sf::Image getImage() const;

            /**
             * @brief Sets the image used for rendering.
             * @param image The SFML image object.
             */
            void setImage(const sf::Image &image);

            /**
             * @brief Gets the texture used for rendering.
             * @return The SFML texture object.
             */
            sf::Texture getTexture() const;

            /**
             * @brief Sets the texture used for rendering.
             * @param texture The SFML texture object.
             */
            void setTexture(const sf::Texture &texture);

            /**
             * @brief Gets the sprite used for rendering.
             * @return The SFML sprite object.
             */
            sf::Sprite getSprite() const;

            /**
             * @brief Sets the sprite used for rendering.
             * @param sprite The SFML sprite object.
             */
            void setSprite(const sf::Sprite &sprite);

            /**
             * @brief Gets the width of the renderer.
             * @return The width of the renderer.
             */
            int getWidth() const;

            /**
             * @brief Sets the width of the renderer.
             * @param width The width of the renderer.
             */
            void setWidth(int width);

            /**
             * @brief Gets the height of the renderer.
             * @return The height of the renderer.
             */
            int getHeight() const;

            /**
             * @brief Sets the height of the renderer.
             * @param height The height of the renderer.
             */
            void setHeight(int height);

            /**< The SFML window object used for rendering. */
            sf::RenderWindow window;

        private:
            /**
             * @brief Converts a Point3D object to an SFML color object.
             * @param color The Point3D object to convert.
             * @return The SFML color object.
             */
            sf::Color point3DToColor(Math::Point3D color);

            /**
             * @brief Converts a Vector3D object to an SFML color object.
             * @param color The Vector3D object to convert.
             * @return The SFML color object.
             */
            sf::Color vector3DToColor(Math::Vector3D color);

            /**
             * @brief Converts an SFML color object to a Point3D object.
             * @param color The SFML color object to convert.
             * @return The Point3D object.
             */
            Math::Point3D colorToPoint3D(sf::Color color);

            /**
             * @brief Converts an SFML color object to a Vector3D object.
             * @param color The SFML color object to convert.
             * @return The Vector3D object.
             */
            Math::Vector3D colorToVector3D(sf::Color color);

            /**< The SFML image object used for rendering. */
            sf::Image _image;

            /**< The SFML texture object used for rendering. */
            sf::Texture _texture;

            /**< The SFML sprite object used for rendering. */
            sf::Sprite _sprite;

            /**< The width of the renderer. */
            int _width;

            /**< The height of the renderer. */
            int _height;

            /**< The clock used for rendering. */
            std::unique_ptr<sf::Clock> _clock;
    };
}
