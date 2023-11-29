#include <cmath>

#include "buddy_knowledge.hpp"
#include "raymath.h"

#include "steering_behaviours/steering_behaviour_seperation.hpp"

void SteeringBehaviourSeperation::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	buddies = dynamic_cast<BuddyKnowledge*>(
		sharedBlackboard->getKnowledge("buddies")
	)->buddies;
}

SteeringForce SteeringBehaviourSeperation::getForce() {
	if (buddies.empty()) {
		return SteeringForce();
	}

	Vector2 movementForce = Vector2{0.0f, 0.0f};

	Kinematics *thisBoid = this->kinematics;

	for (Npc *buddy : this->buddies) {
		Kinematics *target = buddy->getKinematics();
		if (target == thisBoid) {
			continue;
		}
		
		Vector2 npcToTarget = Vector2Subtract(
			target->position,
			thisBoid->position
		);
		Vector2 targetToNpc = Vector2Subtract(
			thisBoid->position,
			target->position
		);
		float distance = Vector2Length(npcToTarget);
		if (distance < activationDistance
			&& inFov(
				thisBoid->movementVelocity,
				npcToTarget,
				fov
			)
		) {
			float force = thisBoid->maxMovementForce
				* (activationDistance - distance)
				/ activationDistance;
			movementForce = Vector2Add(
				movementForce,
				Vector2Scale(
					Vector2Normalize(targetToNpc),
					force
				)
			);
		}
	}

	Vector2 currentRotation = Vector2Rotate(
		Vector2{1, 0},
		kinematics->rotation
	);
	float desiredRotationDelta = atan2(
		movementForce.y * currentRotation.x - movementForce.x * currentRotation.y,
		movementForce.x * currentRotation.x + movementForce.y * currentRotation.y
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

bool SteeringBehaviourSeperation::inFov(Vector2 viewDirection, Vector2 targetDirection, float fov) {
	float relativeAngle = acos(
		Vector2DotProduct(viewDirection, targetDirection)
		/ (Vector2Length(viewDirection) * Vector2Length(targetDirection))
	);

	return relativeAngle < 0.5 * fov;
}