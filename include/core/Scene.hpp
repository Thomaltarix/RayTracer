/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#pragma once

#include "math/Vector3D.hpp"
#include "primitives/IPrimitive.hpp"
#include "core/Core.hpp"
#include "core/Camera.hpp"
#include "plugins/AMaterial.hpp"
#include "plugins/Sphere.hpp"
#include "plugins/Plane.hpp"
#include "plugins/Cylinder.hpp"
#include "plugins/Cone.hpp"
#include "plugins/3DAxis.hpp"
#include "plugins/Ambiant.hpp"
#include "errors/SceneException.hpp"
#include "transformations/ICanRotate.hpp"
#include "transformations/ICanTranslate.hpp"
#include "transformations/ICanScale.hpp"
#include <iostream>
#include <memory>
#include <libconfig.h++>
#include <unordered_map>
#include <functional>
#include <vector>

namespace RayTracer {
    class Scene {
    public:
        /**
         * @brief Construct a new Scene object
         * This class is responsible for creating the scene from the configuration file.
         * @param path path to the configuration file
         * @param core pointer to the core object
         */
        Scene(std::string path, std::shared_ptr<Core> core);

        /**
         * @brief Destroy the Scene object
         * Destroy the Scene object and free the memory allocated for the primitives and lights.
         */
        ~Scene() = default;

        /**
         * @brief Get the Primitives object
         * Get the primitives from the configuration file.
         * @return std::vector<std::shared_ptr<IPrimitive>> primitives
         */
        std::vector<std::shared_ptr<RayTracer::IPrimitive>> getPrimitives() const;

        /**
         * @brief Get the Primitives Map object
         * Get the primitives map from the configuration file.
         * @return std::unordered_map<std::string, std::shared_ptr<IPrimitive>> primitives
         */
        std::unordered_map<std::string, std::shared_ptr<IPrimitive>> getPrimitivesMap() const;

        /**
         * @brief Get the Lights object
         * Get the lights from the configuration file.
         * @return std::vector<std::shared_ptr<ILight>> lights
         */
        std::vector<std::shared_ptr<RayTracer::ILight>> getLights() const;

        /**
         * @brief Get the Lights Map object
         * Get the lights map from the configuration file.
         * @return std::unordered_map<std::string, std::shared_ptr<ILight>> lights
         */
        std::unordered_map<std::string, std::shared_ptr<ILight>> getLightsMap() const;

    private:
        /**
         * @brief Create the primitives
         * Create the primitives from the configuration file.
         * @param cfg configuration file
         * @param core pointer to the core object
         */
        void createPrimitives(libconfig::Config &cfg, std::shared_ptr<Core> core);

        /**
         * @brief Create the camera
         * Create the camera from the configuration file.
         * @param camera configuration file
         */
        void createCamera(libconfig::Setting &camera);

        /**
         * @brief Create the lights
         * Create the lights from the configuration file.
         * @param lights configuration file
         * @param core pointer to the core object
         */
        void createLights(libconfig::Setting &lights, std::shared_ptr<Core> core);

        /**
         * @brief Import the scenes
         * Import the scenes from other configuration files.
         * @param scenes configuration file
         * @param core pointer to the core object
         */
        void importScenes(libconfig::Setting &scenes, std::shared_ptr<Core> core);

        /**
         * @brief Apply the transformations
         * Apply the transformations to the primitives.
         * @param transformations configuration file
         */
        void applyTransformations(libconfig::Setting &transformation);

        /**
         * @brief Apply the transformation
         * Apply the transformation to the primitive.
         * @param transformation configuration file
         */
        void applyTransformation(libconfig::Setting &transformation);

        /**
         * @brief Apply the translation
         * Apply the translation to the primitive.
         * @param transformation configuration file
         * @param primitive pointer to the primitive object
         */
        void applyTranslation(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive);

        /**
         * @brief Apply the rotation
         * Apply the rotation to the primitive.
         * @param transformation configuration file
         * @param primitive pointer to the primitive object
         */
        void applyRotation(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive);

        /**
         * @brief Apply the scale
         * Apply the scale to the primitive.
         * @param transformation configuration file
         * @param primitive pointer to the primitive object
         */
        void applyScale(libconfig::Setting &transformation, std::shared_ptr<IPrimitive> primitive);

        /**
         * @brief Create the spheres
         * Create the spheres from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createSpheres(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Create a Sphere object
         * Create a Sphere object from the configuration file.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createSphere(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create the planes
         * Create the planes from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createPlanes(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Create a Plane object
         * Create a Plane object from the configuration file.
         * It creates a plane from an axis.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createPlaneFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create a Plane object
         * Create a Plane object from the configuration file.
         * It creates a plane from a vector.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createPlaneFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create the cylinders
         * Create the cylinders from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createCylinders(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Create a Cylinder object
         * Create a Cylinder object from the configuration file.
         * It creates a cylinder from an axis.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createCylinderFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create a Cylinder object
         * Create a Cylinder object from the configuration file.
         * It creates a cylinder from a vector.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createCylinderFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create the cones
         * Create the cones from the configuration file.
         * @param primitives configuration file
         * @param core pointer to the core object
         */
        void createCones(libconfig::Setting &primitives, std::shared_ptr<Core> core);

        /**
         * @brief Create a Cone object
         * Create a Cone object from the configuration file.
         * It creates a cone from an axis.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createConeFromAxis(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Create a Cone object
         * Create a Cone object from the configuration file.
         * It creates a cone from a vector.
         * @param primitive configuration file
         * @param core pointer to the core object
         */
        void createConeFromVector(libconfig::Setting &primitive, std::shared_ptr<Core> core);

        /**
         * @brief Get the Color object
         * Get the color from the configuration file.
         * @param setting configuration file
         * @return std::shared_ptr<Math::Vector3D> color
         */
        std::shared_ptr<Math::Vector3D> getColor(libconfig::Setting &setting);

        /**
         * @brief Get the Vector3D object
         * Get the vector3D from the configuration file.
         * @param setting configuration file
         * @return Math::Vector3D vector3D
         */
        Math::Vector3D getVector3D(libconfig::Setting &setting);

        /** Map of primitive creators */
        std::unordered_map<std::string, std::function<void(libconfig::Setting &, std::shared_ptr<Core>)>> _primitiveCreators;

        /** Map of transformation we can apply to primitives */
        std::unordered_map<std::string, std::function<void(libconfig::Setting &, std::shared_ptr<IPrimitive>)>> _primitiveTransformations;

    public:
        /** Map of primitives */
        std::unordered_map<std::string, std::shared_ptr<IPrimitive>> _primitives;

        /** Map of lights */
        std::unordered_map<std::string, std::shared_ptr<ILight>> _lights;

        /** Camera object */
        std::shared_ptr<Camera> _camera;
    };
}
