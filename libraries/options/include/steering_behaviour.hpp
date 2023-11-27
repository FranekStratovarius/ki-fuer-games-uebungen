#ifndef STEERING_BEHAVIOUR_HPP
#define STEERING_BEHAVIOUR_HPP

#include "kinematics.hpp"
#include "raymath.h"
#include "steering_force.hpp"

class SteeringBehaviour {
	public:
		SteeringBehaviour();
		void update(double time_delta);
		virtual SteeringForce getForce();
	private:
		Kinematics kinematics;
};

#endif // STEERING_BEHAVIOUR_HPP