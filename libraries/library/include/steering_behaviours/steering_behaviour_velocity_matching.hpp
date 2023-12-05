#ifndef STEERING_BEHAVIOUR_VELOCITY_MATCHING_HPP
#define STEERING_BEHAVIOUR_VELOCITY_MATCHING_HPP

#include <vector>

#include "npc.hpp"
#include "steering_behaviour.hpp"

class SteeringBehaviourVelocityMatching : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		std::vector<Npc*> buddies;
		// settings
		float activationDistance = 3.0f;
};

#endif // STEERING_BEHAVIOUR_VELOCITY_MATCHING_HPP