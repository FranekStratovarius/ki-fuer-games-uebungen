#ifndef STEERING_BEHAVIOUR_PATH_GRAPPLING_HOOKS_HPP
#define STEERING_BEHAVIOUR_PATH_GRAPPLING_HOOKS_HPP

#include "kinematics.hpp"
#include "raymath.h"
#include "steering_behaviour.hpp"
#include "steering_force.hpp"

class SteeringBehaviourPathGrapplingHooks : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		Vector2 *path = nullptr;
		int currentTarget = 0;
		int pathSize = 0;
		// settings
		float distanceReached = 1.0f;
};

#endif // STEERING_BEHAVIOUR_PATH_GRAPPLING_HOOKS_HPP