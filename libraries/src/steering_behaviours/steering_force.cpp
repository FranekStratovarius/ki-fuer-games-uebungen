#include "steering_behaviours/steering_force.hpp"
#include "raymath.h"

SteeringForce::SteeringForce(Vector2 movementForce, float rotationForce) {
	this->movementForce = movementForce;
	this->rotationForce = rotationForce;
}

SteeringForce::SteeringForce() {
	this->movementForce = Vector2{0.0, 0.0};
	this->rotationForce = 0.0f;
}

SteeringForce SteeringForce::operator+=(const SteeringForce& rhs) {
	this->movementForce = Vector2Add(this->movementForce, rhs.movementForce);
	this->rotationForce += rhs.rotationForce;

	return *this;
}

// SteeringForce SteeringForce::operator*(const SteeringForce& rhs) {
// 	return SteeringForce(
// 		Vector2Add(this->movementForce, rhs.movementForce),
// 		this->rotationForce + rhs.rotationForce
// 	);
// }

SteeringForce SteeringForce::operator+(const SteeringForce& rhs) {
	return SteeringForce(
		Vector2Add(this->movementForce, rhs.movementForce),
		this->rotationForce + rhs.rotationForce
	);
}