/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#include "core/Scene.hpp"

static double transformValue(libconfig::Setting &setting)
{
    double value = 0.f;
    int temp = 0;

    if (setting.getType() == libconfig::Setting::TypeInt) {
        temp = setting;
        value = static_cast<double>(temp);
    } else if (setting.getType() == libconfig::Setting::TypeFloat)
        value = setting;
    else
        throw RayTracer::SceneParseError("Invalid value type");
    return value;
}

static RayTracer::Axis transformAxis(std::string axis)
{
    if (axis == "x" || axis == "X")
        return RayTracer::Axis::X;
    if (axis == "y" || axis == "Y")
        return RayTracer::Axis::Y;
    if (axis == "z" || axis == "Z")
        return RayTracer::Axis::Z;
    throw RayTracer::SceneParseError("Invalid axis for plane");
}

RayTracer::Scene::Scene(std::string path, Core *core)
{
    this->_primitiveCreators = {
        {"spheres", [this](libconfig::Setting &primitive, Core *core) {createSpheres(primitive, core);} },
        {"planes", [this](libconfig::Setting &primitive, Core *core) {createPlanes(primitive, core);} }
    };
    try {
        libconfig::Config libconfig;
        libconfig.readFile(path.c_str());
        if (!libconfig.exists("camera"))
            throw SceneMissingCameraException("You must provide a camera in your scene");
        createCamera(libconfig.lookup("camera"));
        if (libconfig.exists("primitives"))
            createPrimitives(libconfig, core);
        if (!libconfig.exists("lights"))
            throw SceneMissingLightException("You must provide lights in your scene");
        createLights(libconfig.lookup("lights"), core);
    } catch (libconfig::ParseException &e) {
        throw SceneParseError(e.what());
    } catch (libconfig::FileIOException &e) {
        throw SceneParseError(e.what());
    } catch (libconfig::SettingNotFoundException &e) {
        throw SceneParseError(e.what());
    } catch (libconfig::SettingTypeException &e) {
        throw SceneParseError(e.what());
    }
}

void RayTracer::Scene::createCamera(libconfig::Setting &camera)
{
    double posX, posY, posZ;
    double rotX, rotY, rotZ;
    double width, height;
    double fov;
    std::string name;

    std::cout << std::endl << "Creating camera" << std::endl;
    if (camera.exists("resolution")) {
        libconfig::Setting &resolution = camera.lookup("resolution");
        width = transformValue(resolution.lookup("width"));
        height = transformValue(resolution.lookup("height"));
    } else {
        throw SceneCameraException("You must provide a resolution for your camera");
    }
    if (camera.exists("position")) {
        libconfig::Setting &position = camera.lookup("position");
        posX = transformValue(position.lookup("x"));
        posY = transformValue(position.lookup("y"));
        posZ = transformValue(position.lookup("z"));
    } else {
        throw SceneCameraException("You must provide a position for your camera");
    }
    if (camera.exists("rotation")) {
        libconfig::Setting &rotation = camera.lookup("rotation");
        rotX = transformValue(rotation.lookup("x"));
        rotY = transformValue(rotation.lookup("y"));
        rotZ = transformValue(rotation.lookup("z"));
    } else {
        throw SceneCameraException("You must provide a rotation for your camera");
    }
    if (camera.exists("fieldOfView")) {
        fov = transformValue(camera.lookup("fieldOfView"));
    } else {
        throw SceneCameraException("You must provide a field of view for your camera");
    }
    Math::Vector3D position(posX, posY, posZ);
    Math::Vector3D rotation(rotX, rotY, rotZ);
    // _camera = std::make_shared<Camera>(position, rotation, width, height, fov); // Add the camera class here
    std::cout << "Position: " << posX << ", " << posY << ", " << posZ << std::endl;
    std::cout << "Rotation: " << rotX << ", " << rotY << ", " << rotZ << std::endl;
    std::cout << "Resolution: " << width << ", " << height << std::endl;
    std::cout << "Field of view: " << fov << std::endl;
    std::cout << "Camera created" << std::endl << std::endl;
}

void RayTracer::Scene::createLights(libconfig::Setting &lights, Core *core)
{
    double ambiantIntensity, diffuseIntensity;
    std::unordered_map<std::string, Math::Point3D> positions;
    // std::unordered_map<std::string, RayTracer::DirectionalLight *> directionalLights;

    (void)core;
    std::cout << "Creating lights" << std::endl;
    ambiantIntensity = transformValue(lights.lookup("ambiant"));
    diffuseIntensity = transformValue(lights.lookup("diffuse"));
    if (lights.exists("points")) {
        libconfig::Setting &lightPositions = lights.lookup("points");
        for (int i = 0; i < lightPositions.getLength(); i++) {
            libconfig::Setting &light = lightPositions[i];
            double x, y, z;
            std::string name;

            light.lookupValue("name", name);
            x = transformValue(light.lookup("x"));
            y = transformValue(light.lookup("y"));
            z = transformValue(light.lookup("z"));
            if (positions.find(name) != positions.end())
                throw SceneDuplicateNameException("Duplicate light name");
            positions[name] = Math::Point3D(x, y, z);
            std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << std::endl;
        }
    }
    // if (lights.exists("directional")) {
    //     libconfig::Setting &directionalLights = lights.lookup("directional");
    //     for (int i = 0; i < directionalLights.getLength(); i++) {
    //         libconfig::Setting &light = directionalLights[i];
    //         CREATE DIRECTIONAL LIGHT
    // }
    Light::Ambiant *ambiant = new Light::Ambiant(ambiantIntensity);
    this->_lights["ambiant"] = ambiant;
    (void)diffuseIntensity;
    std::cout << "Lights created" << std::endl << std::endl;
}

void RayTracer::Scene::createPrimitives(libconfig::Config &libconfig, Core *core)
{
    libconfig::Setting &primitives = libconfig.lookup("primitives");
    for (int i = 0; i < primitives.getLength(); i++) {
        libconfig::Setting &primitive = primitives[i];
        if (this->_primitiveCreators.find(primitive.getName()) == this->_primitiveCreators.end()) {
            std::string error = primitive.getName();
            throw SceneUnknownObjectException("Unknown object: " + error);
        }
        this->_primitiveCreators[primitive.getName()](primitive, core);
    }
}

void RayTracer::Scene::createSpheres(libconfig::Setting &spheres, Core *core)
{
    std::cout << "Creating spheres" << std::endl;
    for (int i = 0; i < spheres.getLength(); i++) {
        libconfig::Setting &sphere = spheres[i];
        createSphere(sphere, core);
    }
    std::cout << "Spheres created" << std::endl << std::endl;
}

void RayTracer::Scene::createSphere(libconfig::Setting &primitive, Core *core)
{
    double x, y, z, radius;
    std::string name;
    std::string material;

    primitive.lookupValue("name", name);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    radius = transformValue(primitive.lookup("r"));
    primitive.lookupValue("material", material);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; radius: " << radius << "; material: " << material << std::endl;
    Math::Vector3D *color = getColor(primitive);
    IMaterial *mat = core->factoryMaterial(material);
    std::shared_ptr<IMaterial> materialPtr(mat);
    materialPtr->setColor(*color);
    Primitive::Sphere *sphere = new Primitive::Sphere(x, y, z, radius, materialPtr);
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = sphere;
}

void RayTracer::Scene::createPlanes(libconfig::Setting &planes, Core *core)
{
    std::cout << "Creating planes" << std::endl;
    for (int i = 0; i < planes.getLength(); i++) {
        libconfig::Setting &plane = planes[i];
        createPlane(plane, core);
    }
    std::cout << "Planes created" << std::endl << std::endl;
}

void RayTracer::Scene::createPlane(libconfig::Setting &primitive, Core *core)
{
    double x, y, z;
    Axis axis;
    std::string name;
    std::string material;

    primitive.lookupValue("name", name);
    axis = transformAxis(primitive.lookup("axis"));
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    primitive.lookupValue("material", material);
    Math::Vector3D *color = getColor(primitive);
    IMaterial *mat = core->factoryMaterial(material);
    std::shared_ptr<IMaterial> materialPtr(mat);
    materialPtr->setColor(*color);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << " ;axis: " << axis << "; material: " << material << std::endl;
    Primitive::Plane *plane = new Primitive::Plane(x, y, z, materialPtr, axis);
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = plane;
}

Math::Vector3D *RayTracer::Scene::getColor(libconfig::Setting &setting)
{
    double r, g, b;

    if (!setting.exists("color"))
        Math::Vector3D(255, 255, 255);
    libconfig::Setting &color = setting.lookup("color");
    color.lookupValue("r", r);
    color.lookupValue("g", g);
    color.lookupValue("b", b);
    return new Math::Vector3D(r, g, b);
}