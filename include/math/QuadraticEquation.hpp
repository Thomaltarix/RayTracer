/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#pragma once

namespace Math {
    /**
     * @brief Solves a quadratic equation of the form ax^2 + bx + c = 0.
     *
     * @param a The coefficient of the quadratic term.
     * @param b The coefficient of the linear term.
     * @param c The constant term.
     * @param x1 The first solution of the equation (output parameter).
     * @param x2 The second solution of the equation (output parameter).
     * @return true if the equation has real solutions, false otherwise.
     */
    bool solveQuadraticEquation(double a, double b, double c, double &x1, double &x2);
}
