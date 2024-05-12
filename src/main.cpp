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

void testImageBuilder(RayTracer::ImageBuilder &builder, int ac, char **av)
{
    std::shared_ptr<RayTracer::ArgsHandler> args = std::make_shared<RayTracer::ArgsHandler>(ac, av);
    std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();
    RayTracer::Scene scene(args->getScenePath(), core);
    builder.withCamera(*(scene._camera));
    builder.withWidth(scene._camera->_width);
    builder.withHeight(scene._camera->_height);
    builder.withPrimitives(scene.getPrimitives());
}

int main(int ac, char **av)
{
    try {
        RayTracer::ImageBuilder builder;
        testImageBuilder(builder, ac, av);
        std::shared_ptr<RayTracer::Image> image2 = builder.buildImage();


        std::shared_ptr<RayTracer::ArgsHandler> args = std::make_shared<RayTracer::ArgsHandler>(ac, av);


        std::shared_ptr<RayTracer::Core> core = std::make_shared<RayTracer::Core>();

        RayTracer::Scene scene(args->getScenePath(), core);

        RayTracer::Image image(*(scene._camera), scene.getPrimitives(), scene.getLights(), scene._camera->_width, scene._camera->_height, args);

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
