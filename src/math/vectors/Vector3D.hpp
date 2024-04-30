/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Vector3D
*/

#pragma once

namespace Math {
    /**
     * @brief Represents a 3D vector.
     */
    class Vector3D {
    public:
        /**
         * @brief Default constructor.
         */
        Vector3D();

        /**
         * @brief Constructor that initializes the vector with the given coordinates.
         * @param x The x-coordinate of the vector.
         * @param y The y-coordinate of the vector.
         * @param z The z-coordinate of the vector.
         */
        Vector3D(double x, double y, double z);

        /**
         * @brief Copy constructor.
         * @param vector3D The vector to be copied.
         */
        Vector3D(const Vector3D &vector3D);

        /**
         * @brief Move constructor.
         * @param vector3D The vector to be moved.
         */
        Vector3D(const Vector3D &&vector3D);

        /**
         * @brief Default destructor.
         */
        ~Vector3D() = default;

        /**
         * @brief Assignment operator.
         * @param vector3D The vector to be assigned.
         * @return Reference to the assigned vector.
         */
        Vector3D &operator=(const Vector3D &vector3D);

        /**
         * @brief Move assignment operator.
         * @param vector3D The vector to be moved.
         * @return Reference to the moved vector.
         */
        Vector3D &operator=(const Vector3D &&vector3D);

        /**
         * @brief Addition operator.
         * @param vector3D The vector to be added.
         * @return The sum of the two vectors.
         */
        Vector3D operator+(const Vector3D &vector3D) const;

        /**
         * @brief Adds a Vector3D to the current vector.
         * @param vector3D The vector to be added.
         * @return Reference to the current vector.
         */
        Vector3D &operator+=(const Vector3D &vector3D);

        /**
         * @brief Subtraction operator.
         * @param vector3D The vector to be subtracted.
         * @return The difference of the two vectors.
         */
        Vector3D operator-(const Vector3D &vector3D) const;

        /**
         * @brief Subtracts a Vector3D from the current vector.
         * @param vector3D The vector to be subtracted.
         * @return Reference to the current vector.
         */
        Vector3D &operator-=(const Vector3D &vector3D);

        /**
         * @brief Multiplication operator.
         * @param vector3D The vector to be multiplied.
         * @return The product of the two vectors.
         */
        Vector3D operator*(const Vector3D &vector3D) const;

        /**
         * @brief Multiplies a Vector3D with the current vector.
         * @param vector3D The vector to be multiplied.
         * @return Reference to the current vector.
         */
        Vector3D &operator*=(const Vector3D &vector3D);

        /**
         * @brief Division operator.
         * @param vector3D The vector to be divided.
         * @return The quotient of the two vectors.
         */
        Vector3D operator/(const Vector3D &vector3D) const;

        /**
         * @brief Divides the current vector by another vector.
         * @param vector3D The vector to be divided.
         * @return Reference to the current vector.
         */
        Vector3D &operator/=(const Vector3D &vector3D);

        /**
         * @brief Calculates the dot product of two vectors.
         * @param vector3D The vector to be multiplied.
         * @return The dot product of the two vectors.
         */
        double DotProduct(const Vector3D &vector3D) const;

        /**
         * @brief Calculates the length of the vector.
         * @return The length of the vector.
         */
        double Length() const;

        double x; /**< The x-coordinate of the vector. */
        double y; /**< The y-coordinate of the vector. */
        double z; /**< The z-coordinate of the vector. */
    };
}
