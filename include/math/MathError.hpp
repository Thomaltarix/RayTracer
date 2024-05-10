/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** MathError
*/

#pragma once

#include "../errors/IError.hpp"

namespace Math {
    /**
     * @brief Exception class for mathematical errors.
     */
    class MathError : public IError {
    public:
        /**
         * @brief Constructs a MathError object with the given error message.
         * @param message The error message.
         */
        MathError(std::string const &message);

        /**
         * @brief Default destructor for the MathError class.
         */
        ~MathError() override = default;

        /**
         * @brief Returns a C-style string describing the exception.
         * @return A C-style string describing the exception.
         */
        const char *what() const noexcept override;

    private:

        /**< The error message. */
        std::string _message;
    };

    class MathDivideByZeroError : public MathError {
    public:
        /**
         * @brief Constructs a MathDivideByZeroError object with the given error message.
         * @param message The error message.
         */
        MathDivideByZeroError(std::string const &message);

        /**
         * @brief Default destructor for the MathDivideByZeroError class.
         */
        ~MathDivideByZeroError() override = default;
    };

    class MathNoSolutionError : public MathError {
    public:
        /**
         * @brief Constructs a MathNoIntersectionError object with the given error message.
         * @param message The error message.
         */
        MathNoSolutionError(std::string const &message);

        /**
         * @brief Default destructor for the MathNoIntersectionError class.
         */
        ~MathNoSolutionError() override = default;
    };

    class MathIndexOutOfBoundsError : public MathError {
    public:
        /**
         * @brief Constructs a MathIndexOutOfBoundsError object with the given error message.
         * @param message The error message.
         */
        MathIndexOutOfBoundsError(std::string const &message);

        /**
         * @brief Default destructor for the MathIndexOutOfBoundsError class.
         */
        ~MathIndexOutOfBoundsError() override = default;
    };
}
