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
         * @param point3D The point to be assigned.
         * @return Reference to the assigned point.
         */
        Point3D &operator=(const Point3D &point3D);
        Point3D &operator=(const Vector3D &vector3D);

        /**
         * @brief Move assignment operator.
         * @param point3D The point to be moved.
         * @return Reference to the moved point.
         */
        Point3D &operator=(const Point3D &&point3D);

        /**
         * @brief Adds two points together.
         */
        Point3D operator+(const Point3D &point3D) const;
        Point3D operator+(const double &value) const;
        Point3D operator+(const Vector3D &vector3D) const;

        /**
         * @brief Adds a point to the current point.
         */
        Point3D &operator+=(const Point3D &point3D);
        Point3D &operator+=(const double &value);
        Point3D &operator+=(const Vector3D &vector3D);

        /**
         * @brief Subtracts two points.
         */
        Point3D operator-(const Point3D &point3D) const;
        Point3D operator-(const double &value) const;
        Point3D operator-(const Vector3D &vector3D) const;

        /**
         * @brief Subtracts a point from the current point.
         */
        Point3D &operator-=(const Point3D &point3D);
        Point3D &operator-=(const double &value);
        Point3D &operator-=(const Vector3D &vector3D);

        /**
         * @brief Multiplies two points.
         */
        Point3D operator*(const Point3D &point3D) const;
        Point3D operator*(const double &value) const;

        /**
         * @brief Multiplies the current point by another point.
         */
        Point3D &operator*=(const Point3D &point3D);
        Point3D &operator*=(const double &value);

        /**
         * @brief Divides two points.
         */
        Point3D operator/(const Point3D &point3D) const;
        Point3D operator/(const double &value) const;

        /**
         * @brief Divides the current point by another point.
         */
        Point3D &operator/=(const Point3D &point3D);
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

        double x; /**< The x-coordinate of the point. */
        double y; /**< The y-coordinate of the point. */
        double z; /**< The z-coordinate of the point. */
    };
}
