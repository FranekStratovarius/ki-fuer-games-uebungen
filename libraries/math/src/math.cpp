#include "math.hpp"

Vector2 limit(Vector2 force, float maxForce) {
	float forceLength = Vector2Length(force);
	if (forceLength > maxForce) {
		return Vector2Scale(force, maxForce / forceLength);
	}
	return force;
}

float limit(float force, float maxForce) {
	if (force > maxForce) {
		return maxForce;
	} else if (force < -maxForce) {
		return -maxForce;
	}
	return force;
}

float Vector2Determinant(Vector2 x, Vector2 y){
	return x.x * y.y - y.x * x.y;
}