/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** main
*/

#include "core/Core.hpp"
#include "core/Scene.hpp"
#include "core/Image.hpp"

int main(int ac, char **av)
{
    bool sfml = false;

    if (ac == 3 && std::string(av[2]) == "--SFML")
        sfml = true;
    if (ac != 2 && sfml == false) {
        std::cerr << "Usage: ./raytracer [scene.cfg]" << std::endl;
        return 84;
    }
    try {
        std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();
        RayTracer::Scene scene(av[1], core);
        RayTracer::Image image(*(scene._camera), scene.getPrimitives(), scene.getLights(), scene._camera->_width, scene._camera->_height, sfml);
        image.render();
        while(sfml)
            image.renderSFML();
    } catch (RayTracer::SFMLCLoseWindowException &e) {
        std::cerr << e.what() << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
