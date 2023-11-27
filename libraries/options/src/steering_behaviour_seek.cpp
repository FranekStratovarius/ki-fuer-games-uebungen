#include <cstdio>
#include <valarray>
#include "math.hpp"

#include "steering_behaviour_seek.hpp"
#include "steering_behaviour.hpp"

SteeringBehaviourSeek::SteeringBehaviourSeek() :SteeringBehaviour() {
}

SteeringBehaviourSeek::SteeringBehaviourSeek(Kinematics *kinematic) :SteeringBehaviour() {
	this->kinematics = kinematic;
}

SteeringForce SteeringBehaviourSeek::getForce() {
	Vector2 direction = Vector2Subtract(
		target,
		kinematics->position
	);

	Vector2 currentRotation = Vector2Rotate(
		Vector2{1, 0},
		kinematics->rotation
	);
	float desiredRotationDelta = atan2(
		direction.y * currentRotation.x - direction.x * currentRotation.y,
		direction.x * currentRotation.x + direction.y * currentRotation.y
	);

	Vector2 movementForce = Vector2Scale(
		Vector2Normalize(
			direction
		),
		kinematics->maxMovementForce
	);

	float rotationForce = limit(
		desiredRotationDelta,
		kinematics->maxRotationForce
	);

	return SteeringForce(
		movementForce,
		rotationForce
	);
}

void SteeringBehaviourSeek::setTarget(Vector2 target) {
	this->target = target;
}