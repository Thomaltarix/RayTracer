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
#include "core/ImageBuilder.hpp"

void setupBuilder(int ac, char **av)
{
    std::shared_ptr<RayTracer::ArgsHandler> args = std::make_shared<RayTracer::ArgsHandler>(ac, av);
    std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();
    RayTracer::Scene scene(args->getScenePath(), core);
    RayTracer::ImageBuilder builder;
    builder.buildCamera((*scene._camera));
    builder.buildPrimitives(scene.getPrimitives());
    builder.buildLights(scene.getLights());
    builder.buildWidth(scene._camera->_width);
    builder.buildHeight(scene._camera->_height);
    builder.buildArgs(args);
    builder.buildRenderer(args);
    RayTracer::Image newImage = builder.buildImage();
    newImage.render();
}

int main(int ac, char **av)
{
    try {
        setupBuilder(ac, av);
    } catch (RayTracer::SFMLCLoseWindowException &e) {
        std::cerr << e.what() << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
