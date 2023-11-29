#include "steering_behaviours/steering_behaviour_arrive.hpp"
#include "raylib.h"
#include "raymath.h"
#include "math.hpp"
#include "knowledge/target_knowledge.hpp"
#include <cmath>
#include <cstdio>
#include <math.h>

void SteeringBehaviourArrive::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
		sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		this->target = targetPosition;
	}
}

SteeringForce SteeringBehaviourArrive::getForce() {
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

	float forceFaktor = 0.0f;
	float distance = Vector2Length(direction);
	if (distance > breakRadius) {
		forceFaktor = kinematics->maxMovementForce;
	} else {
		forceFaktor = kinematics->maxMovementForce * (distance - stopRadius) / breakRadius;
	}
	direction = Vector2Scale(
		Vector2Normalize(direction),
		forceFaktor
	);
	Vector2 movementForce = Vector2Subtract(
		direction,
		kinematics->movementVelocity
	);
	movementForce = Vector2Scale(movementForce, 1.0f / breakFaktor);

	float rotationForce = desiredRotationDelta;

	if (distance < stopRadius) {
		// this->stop();
		kinematics->movementVelocity = Vector2{0.0f, 0.0f};
		kinematics->rotationVelocity = 0.0f;
		return SteeringForce();
	}

	return SteeringForce(
		movementForce,
		rotationForce
	);
}