/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DegToRad
*/

#include "DegToRad.hpp"
#include <math.h>

double Math::degToRad(double degrees) {
    return degrees * M_PI / 180.0;
}
