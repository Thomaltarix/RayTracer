/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Point3D
*/

#pragma once

namespace Math {

    class Vector3D;

    /**
     * @class Point3D
     * @brief Represents a point in 3D space.
     */
    class Point3D {
    public:
        /**
         * @brief Default constructor.
         */
        Point3D();

        /**
         * @brief Constructor that initializes the point with the given coordinates.
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         * @param z The z-coordinate of the point.
         */
        Point3D(double x, double y, double z);

        /**
         * @brief Copy constructor.
         * @param point3D The point to be copied.
         */
        Point3D(const Point3D &point3D);

        /**
         * @brief Move constructor.
         * @param point3D The point to be moved.
         */
        Point3D(const Point3D &&point3D);

        /**
         * @brief Destructor.
         */
        ~Point3D() = default;

        /**
         * @brief Copy assignment operator.
         * @param point3D The point to be copied.
         * @return Reference to the assigned point.
         */
        Point3D &operator=(const Point3D &point3D);

        /**
         * @brief Copy assignment operator.
         * @param vector3D The vector to be copied.
         * @return Reference to the assigned point.
         */
        Point3D &operator=(const Vector3D &vector3D);

        /**
         * @brief Move assignment operator.
         * @param point3D The point to be moved.
         * @return Reference to the moved point.
         */
        Point3D &operator=(const Point3D &&point3D);

        /**
         * @brief Adds two points together.
         * @param point3D The point to be added.
         * @return The resulting point.
         */
        Point3D operator+(const Point3D &point3D) const;

        /**
         * @brief Adds a value to the current point.
         * @param value The value to be added.
         * @return The resulting point.
         */
        Point3D operator+(const double &value) const;

        /**
         * @brief Adds a vector to the current point.
         * @param vector3D The vector to be added.
         * @return The resulting point.
         */
        Point3D operator+(const Vector3D &vector3D) const;

        /**
         * @brief Adds a point to the current point.
         * @param point3D The point to be added.
         * @return Reference to the current point after addition.
         */
        Point3D &operator+=(const Point3D &point3D);

        /**
         * @brief Adds a value to the current point.
         * @param value The value to be added.
         * @return Reference to the current point after addition.
         */
        Point3D &operator+=(const double &value);

        /**
         * @brief Adds a vector to the current point.
         * @param vector3D The vector to be added.
         * @return Reference to the current point after addition.
         */
        Point3D &operator+=(const Vector3D &vector3D);

        /**
         * @brief Subtracts two points.
         * @param point3D The point to be subtracted.
         * @return The resulting point.
         */
        Point3D operator-(const Point3D &point3D) const;

        /**
         * @brief Subtracts a value from the current point.
         * @param value The value to be subtracted.
         * @return The resulting point.
         */
        Point3D operator-(const double &value) const;

        /**
         * @brief Subtracts a vector from the current point.
         * @param vector3D The vector to be subtracted.
         * @return The resulting point.
         */
        Point3D operator-(const Vector3D &vector3D) const;

        /**
         * @brief Subtracts a point from the current point.
         * @param point3D The point to be subtracted.
         * @return Reference to the current point after subtraction.
         */
        Point3D &operator-=(const Point3D &point3D);

        /**
         * @brief Subtracts a value from the current point.
         * @param value The value to be subtracted.
         * @return Reference to the current point after subtraction.
         */
        Point3D &operator-=(const double &value);

        /**
         * @brief Subtracts a vector from the current point.
         * @param vector3D The vector to be subtracted.
         * @return Reference to the current point after subtraction.
         */
        Point3D &operator-=(const Vector3D &vector3D);

        /**
         * @brief Multiplies two points.
         * @param point3D The point to be multiplied.
         * @return The resulting point.
         */
        Point3D operator*(const Point3D &point3D) const;

        /**
         * @brief Multiplies a point by a value.
         * @param value The value to multiply the point by.
         * @return The resulting point.
         */
        Point3D operator*(const double &value) const;

        /**
         * @brief Multiplies the current point by another point.
         * @param point3D The point to be multiplied.
         * @return Reference to the current point after multiplication.
         */
        Point3D &operator*=(const Point3D &point3D);

        /**
         * @brief Multiplies the current point by a value.
         * @param value The value to multiply the point by.
         * @return Reference to the current point after multiplication.
         */
        Point3D &operator*=(const double &value);

        /**
         * @brief Divides two points.
         * @param point3D The point to be divided.
         * @return The resulting point.
         */
        Point3D operator/(const Point3D &point3D) const;

        /**
         * @brief Divides the current point by a value.
         * @param value The value to divide the point by.
         * @return The resulting point.
         */
        Point3D operator/(const double &value) const;

        /**
         * @brief Divides the current point by another point.
         * @param point3D The point to be divided.
         * @return Reference to the current point after division.
         */
        Point3D &operator/=(const Point3D &point3D);

        /**
         * @brief Divides the current point by a value.
         * @param value The value to divide the point by.
         * @return Reference to the current point after division.
         */
        Point3D &operator/=(const double &value);

        /**
         * @brief Calculates the distance between two points.
         * @param point3D The point to calculate the distance to.
         * @return The distance between the two points.
         */
        double distance(const Point3D &point3D) const;

        /**
         * @brief Rotates the point around the origin.
         * @param rotation The rotation to apply.
         */
        void rotate(const Vector3D &rotation);

        /**
         * Calculates the dot product between this Point3D and the given Vector3D.
         *
         * @param vector3D The Vector3D to calculate the dot product with.
         * @return The dot product between this Point3D and the given Vector3D.
         */
        double dot(const Vector3D &vector3D) const;

        /**
         * @brief Checks if two points are equal.
         * @param point3D The point to compare with.
         * @return True if the points are equal, false otherwise.
         */
        bool operator==(const Point3D &point3D) const;

        /**
         * @brief Checks if two points are not equal.
         * @param point3D The point to compare with.
         * @return True if the points are not equal, false otherwise.
         */
        bool operator!=(const Point3D &point3D) const;

        double x; /**< The x-coordinate of the point. */
        double y; /**< The y-coordinate of the point. */
        double z; /**< The z-coordinate of the point. */
    };
}
