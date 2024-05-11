/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** main
*/

#include "core/Core.hpp"
#include "core/Scene.hpp"
#include "core/Image.hpp"
#include "core/ArgsHandler.hpp"

int main(int ac, char **av)
{
    try {
        std::shared_ptr<RayTracer::ArgsHandler> args = std::make_shared<RayTracer::ArgsHandler>(ac, av);
        std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();
        RayTracer::Scene scene(args->getScenePath(), core);
        RayTracer::Image image(*(scene._camera), scene.getPrimitives(), scene.getLights(), scene._camera->_width, scene._camera->_height, args);
        // if (args.isFastRender())
        //     image.fastRender();
        image.render();
    } catch (RayTracer::SFMLCLoseWindowException &e) {
        std::cerr << e.what() << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
