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
         * @brief Constructor that initializes the axis.
         * @param axis The axis to set.
         * @param coordinate The coordinate of the axis.
         * @note The default coordinate is 0.
         */
        Axis3D(Axis axis = Axis::X);

        /**
         * @brief Destructor.
         */
        ~Axis3D() = default;

        /**
         * @brief Get the current axis.
         * @return The current axis.
         */
        Axis getAxis() const;

        /**
         * @brief Set the axis.
         * @param axis The axis to set.
         */
        void setAxis(Axis axis);

    private:

        /**< The current axis. */
        Axis _axis;
    };
}
