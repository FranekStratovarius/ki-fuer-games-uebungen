#ifndef STEERING_BEHAVIOUR_COHESION_HPP
#define STEERING_BEHAVIOUR_COHESION_HPP

#include <vector>

#include "math.hpp"
#include "npc.hpp"
#include "steering_behaviours/steering_behaviour.hpp"

class SteeringBehaviourCohesion : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		std::vector<Npc*> buddies;
		// settings
		float activationDistance = 3.0f;
};

#endif // STEERING_BEHAVIOUR_COHESION_HPP