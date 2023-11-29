#include <cstdio>
#include <valarray>

#include "steering_behaviours/steering_behaviour_wander.hpp"

void SteeringBehaviourWander::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {}

SteeringForce SteeringBehaviourWander::getForce() {
	// Mittelpunkt des Kreises
	Vector2 positionCenterPoint = Vector2Scale(
		Vector2Rotate(
			Vector2{1.0f, 0.0f},
			this->currentAngle
		),
		this->offset
	);

	float percent = random.random_normal_distribution_float(-this->maxAngleChange, this->maxAngleChange);
	this->currentAngle += percent;
	Vector2 direction = Vector2Add(
		positionCenterPoint,
		Vector2Scale(
			Vector2Rotate(
				Vector2{1.0, 0.0},
				this->currentAngle
			),
			this->radius
		)
	);

	return buildSteeringForce(direction);
}