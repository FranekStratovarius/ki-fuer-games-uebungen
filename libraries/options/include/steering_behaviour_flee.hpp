#ifndef STEERING_BEHAVIOUR_FLEE_HPP
#define STEERING_BEHAVIOUR_FLEE_HPP

#include "kinematics.hpp"
#include "raymath.h"
#include "steering_behaviour.hpp"
#include "steering_force.hpp"

class SteeringBehaviourFlee : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		Vector2 target;
};

#endif // STEERING_BEHAVIOUR_FLEE_HPP