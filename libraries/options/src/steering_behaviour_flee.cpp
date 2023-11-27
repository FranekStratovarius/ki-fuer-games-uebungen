#include <cstdio>
#include "math.hpp"

#include "steering_behaviour_flee.hpp"
#include "raymath.h"
#include "steering_behaviour.hpp"
#include "target_knowledge.hpp"

void SteeringBehaviourFlee::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
	sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		this->setTarget(targetPosition);
	}
}

SteeringForce SteeringBehaviourFlee::getForce() {
	Vector2 direction = Vector2Subtract(
		kinematics->position,
		target
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

void SteeringBehaviourFlee::setTarget(Vector2 target) {
	this->target = target;
}