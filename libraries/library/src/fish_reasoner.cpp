#include "fish_reasoner.hpp"
#include "knowledge/target_knowledge.hpp"
#include "raymath.h"
#include "steering_behaviours/steering_behaviour_arrive.hpp"
#include "steering_behaviours/steering_behaviour_flocking.hpp"
#include "steering_behaviours/steering_behaviour_wander.hpp"

FishReasoner::FishReasoner(Kinematics *kinematics) {
	this->kinematics = kinematics;
	this->maxMovementForce = this->kinematics->maxMovementForce;
}

void FishReasoner::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	Vector2 foodPlace = dynamic_cast<TargetKnowledge*>(
		sharedBlackboard->getKnowledge("food_place")
	)->targetPosition;
	
	switch (fishMode) {
		case hungry:
			if (Vector2Length(
				Vector2Subtract(
					this->kinematics->position,
					foodPlace
				)) < foodDistance
			) {
				this->kinematics->maxMovementForce = this->maxMovementForce;
				this->fishMode = wandering;
				this->remainingWanderingTime = this->wanderingTime;
				this->energy = this->foodEnergy;
				this->optionManager->setOption(new SteeringBehaviourWander());
			}
			break;
		case wandering:
			this->energy -= this->moveEnergyDrain * delta_time;
			this->kinematics->maxMovementForce = this->maxMovementForce
				* (0.3 + 0.7 * (this->energy / this->foodEnergy));
			this->remainingWanderingTime -= delta_time;
			if (remainingWanderingTime <= 0.0f) {
				this->fishMode = swarming;
				this->optionManager->setOption(new SteeringBehaviourFlocking());
			}
			break;
		case swarming:
			this->energy -= this->moveEnergyDrain * delta_time;
			this->kinematics->maxMovementForce = this->maxMovementForce
				* (0.3 + 0.7 * (this->energy / this->foodEnergy));
			if (this->energy <= 0.0f) {
				this->fishMode = hungry;
				this->optionManager->setOption(new SteeringBehaviourArrive());
			}
			break;
		}
}