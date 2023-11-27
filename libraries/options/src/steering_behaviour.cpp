#include "steering_behaviour.hpp"
#include "raymath.h"
#include "steering_force.hpp"

SteeringBehaviour::SteeringBehaviour() {
	kinematics.movementVelocity = Vector2{0.01, 0.0};
	kinematics.rotationVelocity = 0.1;
}

void SteeringBehaviour::update(double time_delta) {
	// update kinematics
	// make abstract for child classes
}

SteeringForce SteeringBehaviour::getForce() {
	return SteeringForce(kinematics.movementVelocity, kinematics.rotationVelocity);
}