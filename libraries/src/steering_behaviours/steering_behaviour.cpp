#include "steering_behaviours/steering_behaviour.hpp"
#include "math.hpp"
#include "raymath.h"
#include "target_knowledge.hpp"

void SteeringBehaviour::setKinematics(Kinematics *kinematics) {
	this->kinematics = kinematics;
}

void SteeringBehaviour::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {

	this->getKnowledge(privateBlackboard, sharedBlackboard);

	SteeringForce steeringForce = this->getForce();

	// limit forces
	steeringForce.movementForce = limit(
		Vector2Scale(steeringForce.movementForce, delta_time),
		this->kinematics->maxMovementForce
	);
	steeringForce.rotationForce = limit(
		steeringForce.rotationForce,
		this->kinematics->maxRotationForce
	);
	// update kinematics
	this->kinematics->movementVelocity = limit(
		Vector2Add(
			this->kinematics->movementVelocity,
			steeringForce.movementForce
		),
		this->kinematics->maxMovementVelocity
	);
	this->kinematics->rotationVelocity = limit(
		steeringForce.rotationForce,
		this->kinematics->maxMovementVelocity
	);
}

SteeringForce SteeringBehaviour::buildSteeringForce(Vector2 direction) {
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
		this->kinematics->maxMovementForce
	);

	float rotationForce = limit(
		desiredRotationDelta,
		this->kinematics->maxRotationForce
	);

	return SteeringForce(
		movementForce,
		rotationForce
	);
}