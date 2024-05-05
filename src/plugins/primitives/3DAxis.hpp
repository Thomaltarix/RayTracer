/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** 3DAxis
*/

#pragma once

namespace RayTracer {

    /**
     * @brief Enum class representing the axis in 3D space.
     */
    enum class Axis {

        /**< X-axis */
        X,

        /**< Y-axis */
        Y,

        /**< Z-axis */
        Z
    };

    /**
     * @brief Class representing a 3D axis.
     */
    class Axis3D {
    public:
        /**
         * @brief Default constructor.
         * @note The default axis is X.
         */
        Axis3D();

        /**
         * @brief Constructor that initializes the axis.
         * @param axis The axis to set.
         */
        Axis3D(Axis axis);

        /**
         * @brief Destructor.
         */
        ~Axis3D() = default;

        /**
         * @brief Get the current axis.
         * @return The current axis.
         */
        Axis GetAxis() const;

        /**
         * @brief Set the axis.
         * @param axis The axis to set.
         */
        void SetAxis(Axis axis);

    private:

        /**< The current axis. */
        Axis _axis;
    };
}
