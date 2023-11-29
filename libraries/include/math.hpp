#ifndef MATH_HPP
#define MATH_HPP

# define M_PIl 3.141592653589793238462643383279502884L /* pi */

#include "raylib.h"
#include "raymath.h"

Vector2 limit(Vector2 value, float maxValue);
Vector2 limit(Vector2 value, float minValue, float maxValue);
float limit(float value, float maxValue);
float limit(float value, float minValue, float maxValue);
float degreesToRadians(float degree);

#endif // MATH_HPP