#ifndef STEERING_BEHAVIOUR_FLOCKING_HPP
#define STEERING_BEHAVIOUR_FLOCKING_HPP

#include <vector>

#include "npc.hpp"
#include "steering_behaviour.hpp"
#include "steering_behaviour_cohesion.hpp"
#include "steering_behaviour_seperation.hpp"
#include "steering_behaviour_velocity_matching.hpp"

class SteeringBehaviourFlocking : public SteeringBehaviour {
	public:
		SteeringBehaviourFlocking();
		~SteeringBehaviourFlocking();
		void setKinematics(Kinematics *kinematic) override;
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		std::vector<Npc*> buddies;
		SteeringBehaviourCohesion *steeringBehaviourCohesion;
		SteeringBehaviourSeperation *steeringBehaviourSeperation;
		SteeringBehaviourVelocityMatching *steeringBehaviourVelocityMatching;

		// settings
		float weightCohesion = 1.0f;
		float weightSeperation = 1.0f;
		float weightVelocityMatching = 1.0f;
};

#endif // STEERING_BEHAVIOUR_FLOCKING_HPP