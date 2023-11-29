#include <cstdio>
#include <valarray>
#include "math.hpp"

#include "steering_behaviours/steering_behaviour_seek.hpp"
#include "knowledge/target_knowledge.hpp"

void SteeringBehaviourSeek::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
	sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		this->target = targetPosition;
	}
}

SteeringForce SteeringBehaviourSeek::getForce() {
	Vector2 direction = Vector2Subtract(
		this->target,
		kinematics->position
	);
	
	return buildSteeringForce(direction);
}