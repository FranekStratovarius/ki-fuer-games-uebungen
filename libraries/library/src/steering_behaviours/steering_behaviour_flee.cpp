#include <cstdio>
#include "math.hpp"

#include "steering_behaviours/steering_behaviour_flee.hpp"
#include "raymath.h"
#include "knowledge/target_knowledge.hpp"

void SteeringBehaviourFlee::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
	sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		this->target = targetPosition;
	}
}

SteeringForce SteeringBehaviourFlee::getForce() {
	Vector2 direction = Vector2Subtract(
		kinematics->position,
		target
	);

	return buildSteeringForce(direction);
}