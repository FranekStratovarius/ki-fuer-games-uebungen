#ifndef FISH_REASONER_HPP
#define FISH_REASONER_HPP

#include "kinematics.hpp"
#include "option_manager.hpp"
#include "reasoner.hpp"

enum FishMode {
	hungry,
	wandering,
	swarming
};

class FishReasoner : public Reasoner {
	public:
		FishReasoner(Kinematics *kinematics);
		void update(
			float delta_time,
			Blackboard *privateBlackboard,
			Blackboard *sharedBlackboard
		) override;
	private:
		Kinematics *kinematics;
		float maxMovementForce;
		FishMode fishMode = swarming;
		float remainingWanderingTime = 0.0f;
		float energy = 0.0f;
		// settings
		float foodDistance = 4.0f;
		float foodEnergy = 10.0f;
		float moveEnergyDrain = 1.0f;
		float wanderingTime = 3.0f;

};

#endif // FISH_REASONER_HPP