#include <cstdio>
#include <valarray>
#include "math.hpp"

#include "steering_behaviour_seek.hpp"
#include "steering_behaviour.hpp"
#include "target_knowledge.hpp"

void SteeringBehaviourSeek::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
	sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		this->setTarget(targetPosition);
	}
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