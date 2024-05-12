/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#include "core/Scene.hpp"
#include "core/Camera.hpp"

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

RayTracer::Scene::Scene(std::string path, std::shared_ptr<Core> core)
{
    this->_primitiveCreators = {
        {"spheres", [this](libconfig::Setting &primitive, std::shared_ptr<Core> core) {createSpheres(primitive, core);} },
        {"planes", [this](libconfig::Setting &primitive, std::shared_ptr<Core> core) {createPlanes(primitive, core);} },
        {"cylinders", [this](libconfig::Setting &primitive, std::shared_ptr<Core> core) {createCylinders(primitive, core);} },
        {"cones", [this](libconfig::Setting &primitive, std::shared_ptr<Core> core) {createCones(primitive, core);} }
    };
    this->_primitiveTransformations = {
        {"rotation", [this](libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive) {applyRotation(transformation, primitive);} },
        {"translation", [this](libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive) {applyTranslation(transformation, primitive);} },
        {"scale", [this](libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive) {applyScale(transformation, primitive);} }
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
        if (libconfig.exists("transformations"))
            applyTransformations(libconfig.lookup("transformations"));
        if (libconfig.exists("scenes"))
            importScenes(libconfig.lookup("scenes"), core);
    } catch (libconfig::ParseException &e) {
        throw SceneParseError("The configuration file is invalid");
    } catch (libconfig::FileIOException &e) {
        throw SceneParseError("File not found");
    } catch (libconfig::SettingNotFoundException &e) {
        throw SceneParseError("A setting is missing in the configuration file");
    } catch (libconfig::SettingTypeException &e) {
        throw SceneParseError("Invalid setting type in the configuration file");
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
    Math::Point3D position(posX, posY, posZ);
    Math::Vector3D rotation(rotX, rotY, rotZ);
    _camera = std::make_shared<RayTracer::Camera>(position, rotation, width, height, fov);
    std::cout << "Position: " << posX << ", " << posY << ", " << posZ << std::endl;
    std::cout << "Rotation: " << rotX << ", " << rotY << ", " << rotZ << std::endl;
    std::cout << "Resolution: " << width << ", " << height << std::endl;
    std::cout << "Field of view: " << fov << std::endl;
    std::cout << "Camera created" << std::endl << std::endl;
}

void RayTracer::Scene::createLights(libconfig::Setting &lights, std::shared_ptr<Core> core)
{
    double ambiantIntensity, diffuseIntensity;
    std::unordered_map<std::string, Math::Point3D> positions;
    std::unordered_map<std::string, Math::Vector3D> vectors;

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
    if (lights.exists("directional")) {
        libconfig::Setting &lightVectors = lights.lookup("directional");
        for (int i = 0; i < lightVectors.getLength(); i++) {
            libconfig::Setting &light = lightVectors[i];
            double x, y, z;
            std::string name;

            light.lookupValue("name", name);
            x = transformValue(light.lookup("x"));
            y = transformValue(light.lookup("y"));
            z = transformValue(light.lookup("z"));

            if (vectors.find(name) != vectors.end())
                throw SceneDuplicateNameException("Duplicate light name");
            vectors[name] = Math::Vector3D(x, y, z);
            std::cout << name << " --> {x: " << x << "; y: " << y << "; z: " << z << "};" << std::endl;
        }
    }
    std::shared_ptr<Light::Ambiant> ambiant = std::make_shared<Light::Ambiant>(ambiantIntensity);
    this->_lights["ambiant"] = ambiant;
    for (auto &vector : vectors) {
        std::shared_ptr<Light::Directional> directional = std::make_shared<Light::Directional>(diffuseIntensity, vector.second);
        this->_lights[vector.first] = directional;
    }
    std::cout << "Lights created" << std::endl << std::endl;
}

void RayTracer::Scene::importScenes(libconfig::Setting &scenes, std::shared_ptr<Core> core)
{
    std::cout << "Importing scenes" << std::endl;
    for (int i = 0; i < scenes.getLength(); i++) {
        libconfig::Setting &scene = scenes[i];
        std::string path;

        scene.lookupValue("path", path);
        std::cout << "Importing scene: " << path << std::endl;
        Scene newScene(path, core);
        std::unordered_map<std::string, std::shared_ptr<IPrimitive>> primitives = newScene.getPrimitivesMap();
        std::unordered_map<std::string, std::shared_ptr<ILight>> lights = newScene.getLightsMap();
        for (auto &primitive : primitives) {
            if (this->_primitives.find(primitive.first) != this->_primitives.end())
                throw SceneDuplicateNameException("Duplicate primitive name");
            this->_primitives[primitive.first] = primitive.second;
        }
        for (auto &light : lights) {
            if (light.first == "ambiant")
                continue;
            if (this->_lights.find(light.first) != this->_lights.end())
                throw SceneDuplicateNameException("Duplicate light name");
            this->_lights[light.first] = light.second;
        }
    }
    std::cout << "Scenes imported" << std::endl << std::endl;
}

void RayTracer::Scene::createPrimitives(libconfig::Config &libconfig, std::shared_ptr<Core> core)
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

void RayTracer::Scene::createSpheres(libconfig::Setting &spheres, std::shared_ptr<Core> core)
{
    std::cout << "Creating spheres" << std::endl;
    for (int i = 0; i < spheres.getLength(); i++) {
        libconfig::Setting &sphere = spheres[i];
        createSphere(sphere, core);
    }
    std::cout << "Spheres created" << std::endl << std::endl;
}

void RayTracer::Scene::createSphere(libconfig::Setting &primitive, std::shared_ptr<Core> core)
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
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::shared_ptr<Primitive::Sphere> sphere = std::make_shared<Primitive::Sphere>(x, y, z, radius, materialPtr);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; radius: " << radius;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = sphere;
}

void RayTracer::Scene::createPlanes(libconfig::Setting &planes, std::shared_ptr<Core> core)
{
    std::cout << "Creating planes" << std::endl;
    for (int i = 0; i < planes.getLength(); i++) {
        libconfig::Setting &plane = planes[i];
        if (plane.exists("axis"))
            createPlaneFromAxis(plane, core);
        else
            createPlaneFromVector(plane, core);
    }
    std::cout << "Planes created" << std::endl << std::endl;
}

void RayTracer::Scene::createPlaneFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core)
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
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << " ; axis: " << axis;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    std::shared_ptr<Primitive::Plane> plane = std::make_shared<Primitive::Plane>(x, y, z, materialPtr, axis);
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = plane;
}

void RayTracer::Scene::createPlaneFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core)
{
    double x, y, z;
    Math::Vector3D vector;
    std::string name;
    std::string material;

    primitive.lookupValue("name", name);
    vector = getVector3D(primitive);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    primitive.lookupValue("material", material);
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << " ; vector: " << vector.x << ", " << vector.y << ", " << vector.z;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    std::shared_ptr<Primitive::Plane> plane = std::make_shared<Primitive::Plane>(x, y, z, materialPtr, vector);
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = plane;
}

void RayTracer::Scene::createCylinders(libconfig::Setting &cylinders, std::shared_ptr<Core> core)
{
    std::cout << "Creating cylinders" << std::endl;
    for (int i = 0; i < cylinders.getLength(); i++) {
        libconfig::Setting &cylinder = cylinders[i];
        if (cylinder.exists("axis"))
            createCylinderFromAxis(cylinder, core);
        else
            createCylinderFromVector(cylinder, core);
    }
    std::cout << "Cylinders created" << std::endl << std::endl;
}

void RayTracer::Scene::createCylinderFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core)
{
    double x, y, z, radius;
    std::string name;
    std::string material;
    Axis3D axis;

    primitive.lookupValue("name", name);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    radius = transformValue(primitive.lookup("r"));
    axis = transformAxis(primitive.lookup("axis"));
    primitive.lookupValue("material", material);
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::shared_ptr<Primitive::Cylinder> cylinder = std::make_shared<Primitive::Cylinder>(x, y, z, materialPtr, axis, radius);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; radius: " << radius << "; axis: " << axis;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = cylinder;
}

void RayTracer::Scene::createCylinderFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core)
{
    double x, y, z, radius;
    std::string name;
    std::string material;
    Math::Vector3D vector;

    primitive.lookupValue("name", name);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    radius = transformValue(primitive.lookup("r"));
    vector = getVector3D(primitive);
    primitive.lookupValue("material", material);
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::shared_ptr<Primitive::Cylinder> cylinder = std::make_shared<Primitive::Cylinder>(x, y, z, materialPtr, vector, radius);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; radius: " << radius << "; vector: " << vector.x << ", " << vector.y << ", " << vector.z;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = cylinder;
}

void RayTracer::Scene::createCones(libconfig::Setting &cones, std::shared_ptr<Core> core)
{
    std::cout << "Creating cones" << std::endl;
    for (int i = 0; i < cones.getLength(); i++) {
        libconfig::Setting &cone = cones[i];
        if (cone.exists("axis")) {
            createConeFromAxis(cone, core);
        } else {
            createConeFromVector(cone, core);
        }
    }
    std::cout << "Cones created" << std::endl << std::endl;
}

void RayTracer::Scene::createConeFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core)
{
    double x, y, z, angle;
    std::string name;
    std::string material;
    Axis3D axis;

    primitive.lookupValue("name", name);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    angle = transformValue(primitive.lookup("angle"));
    axis = transformAxis(primitive.lookup("axis"));
    primitive.lookupValue("material", material);
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::shared_ptr<Primitive::Cone> cone = std::make_shared<Primitive::Cone>(x, y, z, materialPtr, axis, angle);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; angle: " << angle << "; axis: " << axis;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = cone;
}

void RayTracer::Scene::createConeFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core)
{
    double x, y, z, angle;
    std::string name;
    std::string material;
    Math::Vector3D vector;

    primitive.lookupValue("name", name);
    x = transformValue(primitive.lookup("x"));
    y = transformValue(primitive.lookup("y"));
    z = transformValue(primitive.lookup("z"));
    angle = transformValue(primitive.lookup("angle"));
    vector = getVector3D(primitive);
    primitive.lookupValue("material", material);
    std::shared_ptr<Math::Vector3D> color = getColor(primitive);
    std::shared_ptr<IMaterial> materialPtr = core->factoryMaterial(material);
    materialPtr->setColor(*color);
    std::shared_ptr<Primitive::Cone> cone = std::make_shared<Primitive::Cone>(x, y, z, materialPtr, vector, angle);
    std::cout << name << " --> x: " << x << "; y: " << y << "; z: " << z << "; angle: " << angle << "; vector: " << vector.x << ", " << vector.y << ", " << vector.z;
    std::cout << "; material: " << material << " ; color: " << color->x << ", " << color->y << ", " << color->z << std::endl;
    if (this->_primitives.find(name) != this->_primitives.end())
        throw SceneDuplicateNameException("Duplicate primitive name");
    this->_primitives[name] = cone;
}

std::shared_ptr<Math::Vector3D> RayTracer::Scene::getColor(libconfig::Setting &setting)
{
    double r, g, b;

    if (!setting.exists("color"))
        Math::Vector3D(255, 255, 255);
    libconfig::Setting &color = setting.lookup("color");
    r = transformValue(color.lookup("r"));
    g = transformValue(color.lookup("g"));
    b = transformValue(color.lookup("b"));
    return std::make_shared<Math::Vector3D>(r, g, b);
}

Math::Vector3D RayTracer::Scene::getVector3D(libconfig::Setting &setting)
{
    double x, y, z;

    if (!setting.exists("vector"))
        throw RayTracer::SceneParseError("Vector not found");
    libconfig::Setting &vector = setting.lookup("vector");
    x = transformValue(vector.lookup("x"));
    y = transformValue(vector.lookup("y"));
    z = transformValue(vector.lookup("z"));
    return Math::Vector3D(x, y, z);
}

void RayTracer::Scene::applyTransformations(libconfig::Setting &transformations)
{
    std::cout << "Applying transformations" << std::endl;
    for (int i = 0; i < transformations.getLength(); i++) {
        libconfig::Setting &transformation = transformations[i];
        applyTransformation(transformation);
    }
    std::cout << "Transformations applied" << std::endl << std::endl;
}

void RayTracer::Scene::applyTransformation(libconfig::Setting &transformation)
{
    std::string target;
    std::string type;

    transformation.lookupValue("target", target);
    transformation.lookupValue("type", type);
    if (this->_primitives.find(target) == this->_primitives.end())
        throw SceneUnknownObjectException("Transformation target not found: " + target);
    if (this->_primitiveTransformations.find(type) == this->_primitiveTransformations.end())
        throw SceneUnknownTransformationException("Unknown transformation: " + type);
    std::cout << target << " : ";
    this->_primitiveTransformations[type](transformation, this->_primitives[target]);
}

void RayTracer::Scene::applyTranslation(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive)
{
    double x, y, z;

    x = transformValue(transformation.lookup("x"));
    y = transformValue(transformation.lookup("y"));
    z = transformValue(transformation.lookup("z"));
    std::cout << "Translation: x: " << x << "; y: " << y << "; z: " << z << std::endl;
    if (dynamic_cast<ICanTranslate *>(primitive.get()) == nullptr)
        throw SceneInvalidTransformationException("Invalid transformation for object");
    dynamic_cast<ICanTranslate *>(primitive.get())->translate(x, y, z);
}

void RayTracer::Scene::applyRotation(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive)
{
    double angle;
    Axis axis;
    Math::Vector3D vector;

    if (dynamic_cast<ICanRotate *>(primitive.get()) == nullptr)
        throw SceneInvalidTransformationException("Invalid transformation for object");
    angle = transformValue(transformation.lookup("angle"));
    if (transformation.exists("axis")) {
        axis = transformAxis(transformation.lookup("axis"));
        std::cout << "Rotation: angle: " << angle << "; axis: " << axis << std::endl;
        dynamic_cast<ICanRotate *>(primitive.get())->rotate(axis, angle);
    } else {
        vector = getVector3D(transformation);
        std::cout << "Rotation: angle: " << angle << "; vector: " << vector.x << ", " << vector.y << ", " << vector.z << std::endl;
        dynamic_cast<ICanRotate *>(primitive.get())->rotate(vector, angle);
    }
}

void RayTracer::Scene::applyScale(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive)
{
    double multiplier;

    multiplier = transformValue(transformation.lookup("multiplier"));
    std::cout << "Scale: multiplier: " << multiplier << std::endl;
    if (dynamic_cast<ICanScale *>(primitive.get()) == nullptr)
        throw SceneInvalidTransformationException("Invalid transformation for object");
    dynamic_cast<ICanScale *>(primitive.get())->scale(multiplier);
}

std::vector<std::shared_ptr<RayTracer::IPrimitive>> RayTracer::Scene::getPrimitives() const
{
    std::vector<std::shared_ptr<RayTracer::IPrimitive>> primitives;

    for (auto &primitive : this->_primitives) {
        primitives.push_back(primitive.second);
    }
    return primitives;
}

std::unordered_map<std::string, std::shared_ptr<RayTracer::IPrimitive>> RayTracer::Scene::getPrimitivesMap() const
{
    return this->_primitives;
}

std::vector<std::shared_ptr<RayTracer::ILight>> RayTracer::Scene::getLights() const
{
    std::vector<std::shared_ptr<RayTracer::ILight>> lights;

    for (auto &light : this->_lights) {
        lights.push_back(light.second);
    }
    return lights;
}

std::unordered_map<std::string, std::shared_ptr<RayTracer::ILight>> RayTracer::Scene::getLightsMap() const
{
    return this->_lights;
}
