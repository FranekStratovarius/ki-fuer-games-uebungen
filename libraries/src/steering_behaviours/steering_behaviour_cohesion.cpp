#include <cmath>

#include "knowledge/buddy_knowledge.hpp"
#include "raymath.h"

#include "steering_behaviours/steering_behaviour_cohesion.hpp"
#include "steering_behaviours/steering_force.hpp"

void SteeringBehaviourCohesion::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	buddies = dynamic_cast<BuddyKnowledge*>(
		sharedBlackboard->getKnowledge("buddies")
	)->buddies;
}

SteeringForce SteeringBehaviourCohesion::getForce() {
	if (buddies.empty()) {
		return SteeringForce();
	}

	Vector2 centerOfMass = Vector2{0.0f, 0.0f};
	int numberOfRelevantBoids = 0;
	Kinematics *thisBoid = this->kinematics;

	for (Npc *buddy : this->buddies) {
		Kinematics *target = buddy->getKinematics();
		if (target == thisBoid) {
			continue;
		}
		
		Vector2 direction = Vector2Subtract(
			thisBoid->position,
			target->position
		);
		float distance = Vector2Length(direction);
		if (distance < activationDistance) {
			centerOfMass = Vector2Add(
				centerOfMass,
				target->position
			);
			numberOfRelevantBoids++;
		}
	}

	if (numberOfRelevantBoids > 0) {
		centerOfMass = Vector2Scale(
			centerOfMass,
			1.0f / numberOfRelevantBoids
		);
		Vector2 direction = Vector2Subtract(
			centerOfMass,
			thisBoid->position
		);
		float force = thisBoid->maxMovementForce
			* Vector2Length(direction)
			/ activationDistance;
		direction = Vector2Scale(
			Vector2Normalize(direction),
			force
		);

		Vector2 currentRotation = Vector2Rotate(
			Vector2{1, 0},
			kinematics->rotation
		);
		float desiredRotationDelta = atan2(
			direction.y * currentRotation.x - direction.x * currentRotation.y,
			direction.x * currentRotation.x + direction.y * currentRotation.y
		);

		float rotationForce = limit(
			desiredRotationDelta,
			this->kinematics->maxRotationForce
		);

		return SteeringForce(
			direction,
			rotationForce
		);
	}

	return SteeringForce();
}