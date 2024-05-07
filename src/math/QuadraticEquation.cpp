/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** No file there , just an epitech header example .
*/

#include <cmath>

bool solveQuadraticEquation(double a, double b, double c, double &x1, double &x2)
{
    double delta = b * b - 4 * a * c;

    if (delta < 0)
        return false;
    if (delta == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return true;
    }
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);

    if (x1 > x2) {
        double tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    return true;
}
