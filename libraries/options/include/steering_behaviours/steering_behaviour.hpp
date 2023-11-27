#ifndef STEERING_BEHAVIOUR_HPP
#define STEERING_BEHAVIOUR_HPP

#include "blackboard.hpp"
#include "kinematics.hpp"
#include "option.hpp"
#include "raymath.h"
#include "steering_force.hpp"

class SteeringBehaviour : public Option {
	public:
		void setKinematics(Kinematics *kinematic);
		void update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		virtual void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) = 0;
		virtual SteeringForce getForce() = 0;
	protected:
		Kinematics *kinematics;
};

#endif // STEERING_BEHAVIOUR_HPP