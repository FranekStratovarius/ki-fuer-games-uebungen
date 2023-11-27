#ifndef STEERING_BEHAVIOUR_SEEK_HPP
#define STEERING_BEHAVIOUR_SEEK_HPP

#include "kinematics.hpp"
#include "raymath.h"
#include "steering_behaviour.hpp"
#include "steering_force.hpp"

class SteeringBehaviourSeek : public SteeringBehaviour {
	public:
		SteeringBehaviourSeek();
		SteeringBehaviourSeek(Kinematics *kinematic);
		SteeringForce getForce() override;
		void setTarget(Vector2 target);
	private:
		Vector2 target;
		Kinematics *kinematics;
};

#endif // STEERING_BEHAVIOUR_SEEK_HPP