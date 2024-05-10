/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SFMLRenderer.hpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

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
             * @brief Constructor for SFMLRenderer with specified image file.
             * @param filename The path to the image file.
             */
            SFMLRenderer(const std::string &filename);

            /**
             * @brief Destructor for SFMLRenderer.
             */
            ~SFMLRenderer();

            /**
             * @brief Displays the rendered image on the SFML window.
             */
            void display();

            /**
             * @brief Loads a PPM image file.
             * @param filename The path to the PPM image file.
             */
            void loadPPM(const std::string &filename);

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

            sf::RenderWindow window; /**< The SFML window object used for rendering. */

        private:
            sf::Image _image; /**< The SFML image object used for rendering. */
            sf::Texture _texture; /**< The SFML texture object used for rendering. */
            sf::Sprite _sprite; /**< The SFML sprite object used for rendering. */
            int _width; /**< The width of the renderer. */
            int _height; /**< The height of the renderer. */
    };
}
