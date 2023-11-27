#include "steering_behaviour.hpp"
#include "math.hpp"
#include "raymath.h"
#include "steering_force.hpp"
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
		kinematics->maxMovementForce
	);
	steeringForce.rotationForce = limit(
		steeringForce.rotationForce,
		kinematics->maxRotationForce
	);
	// update kinematics
	kinematics->movementVelocity = limit(
		Vector2Add(
			kinematics->movementVelocity,
			steeringForce.movementForce
		),
		kinematics->maxMovementVelocity
	);
	kinematics->rotationVelocity = limit(
		steeringForce.rotationForce,
		kinematics->maxMovementVelocity
	);
}