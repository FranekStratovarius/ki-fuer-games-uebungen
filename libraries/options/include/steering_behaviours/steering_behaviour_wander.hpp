#ifndef STEERING_BEHAVIOUR_WANDER_HPP
#define STEERING_BEHAVIOUR_WANDER_HPP

#include "math.hpp"
#include "kinematics.hpp"
#include "steering_behaviour.hpp"
#include "steering_force.hpp"
#include "random.hpp"

class SteeringBehaviourWander : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		Random random = Random();
		float currentAngle = 0.0f;
		float offset = 2.0f;
		float radius = 2.0f;
		float maxAngleChange = degreesToRadians(15);
};

#endif // STEERING_BEHAVIOUR_WANDER_HPP