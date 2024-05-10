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
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer [scene.cfg]" << std::endl;
        return 84;
    }
    try {
        std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();
        RayTracer::Scene scene(av[1], core);
        RayTracer::Image image(*(scene._camera), scene.getPrimitives(), scene.getLights(), scene._camera->_width, scene._camera->_height);
        image.render();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
