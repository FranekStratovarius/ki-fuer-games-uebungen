#ifndef STEERING_BEHAVIOUR_SEPERATION_HPP
#define STEERING_BEHAVIOUR_SEPERATION_HPP

#include <vector>

#include "math.hpp"
#include "npc.hpp"
#include "steering_behaviours/steering_behaviour.hpp"

class SteeringBehaviourSeperation : public SteeringBehaviour {
	public:
		void getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) override;
		SteeringForce getForce() override;
	private:
		bool inFov(Vector2 viewDirection, Vector2 TargetDirection, float fov);
		std::vector<Npc*> buddies;
		// settings
		float fov = degreesToRadians(360.0f);
		float activationDistance = 3.0f;
};

#endif // STEERING_BEHAVIOUR_SEPERATION_HPP