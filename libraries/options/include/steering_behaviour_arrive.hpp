#ifndef STEERING_BEHAVIOUR_ARRIVE_HPP
#define STEERING_BEHAVIOUR_ARRIVE_HPP

#include "kinematics.hpp"
#include "raymath.h"
#include "steering_behaviour.hpp"
#include "steering_force.hpp"

class SteeringBehaviourArrive : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
		void setTarget(Vector2 target);
	private:
		Vector2 target;
		float stopRadius = 3.0f;
		float breakRadius = 8.0f;
		float breakFaktor = 0.25f;
};

#endif // STEERING_BEHAVIOUR_ARRIVE_HPP