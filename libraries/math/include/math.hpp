#ifndef MATH_HPP
#define MATH_HPP

# define M_PIl 3.141592653589793238462643383279502884L /* pi */

#include "raylib.h"
#include "raymath.h"

Vector2 limit(Vector2 force, float maxForce);
float limit(float force, float maxForce);
float Vector2Determinant(Vector2 x, Vector2 y);
float degreesToRadians(float degree);

#endif // MATH_HPP