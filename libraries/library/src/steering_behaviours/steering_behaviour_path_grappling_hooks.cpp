#include <cstdio>
#include <valarray>
#include "math.hpp"

#include "raymath.h"
#include "steering_behaviours/steering_behaviour_path_grappling_hooks.hpp"
#include "knowledge/path_knowledge.hpp"
#include "steering_behaviours/steering_force.hpp"

void SteeringBehaviourPathGrapplingHooks::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	PathKnowledge *pathKnowledge = dynamic_cast<PathKnowledge*>(
	sharedBlackboard->getKnowledge("grappling_path")
	);
	if(pathKnowledge != nullptr) {
		this->path = pathKnowledge->path;
		this->pathSize = pathKnowledge->pathSize;
	}
}

SteeringForce SteeringBehaviourPathGrapplingHooks::getForce() {
	if (path == nullptr) {
		return SteeringForce();
	}
	Vector2 direction = Vector2Subtract(
		this->path[currentTarget],
		kinematics->position
	);

	if (Vector2Length(direction) < this->distanceReached) {
		currentTarget = (currentTarget + 1) % this->pathSize;
	}
	
	return buildSteeringForce(direction);
}