#include "buddy_knowledge.hpp"
#include "math.hpp"

#include "raymath.h"
#include "steering_behaviours/steering_behaviour_velocity_matching.hpp"

void SteeringBehaviourVelocityMatching::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	buddies = dynamic_cast<BuddyKnowledge*>(
		sharedBlackboard->getKnowledge("buddies")
	)->buddies;
}

SteeringForce SteeringBehaviourVelocityMatching::getForce() {
	if (buddies.empty()) {
		return SteeringForce();
	}

	Vector2 averageVelocity = Vector2{0.0f, 0.0f};

	Kinematics *thisBoid = this->kinematics;

	for (Npc *buddy : this->buddies) {
		Kinematics *target = buddy->getKinematics();
		if (target == thisBoid) {
			continue;
		}

		if (target != nullptr) {
			Vector2 direction = Vector2Subtract(
				target->position,
				thisBoid->position
			);
			float distance = Vector2Length(direction);
			if (distance < activationDistance) {
				averageVelocity = Vector2Add(
					averageVelocity,
					target->movementVelocity
				);
			}
		}
	}

	return buildSteeringForce(averageVelocity);
}