#include "option_manager.hpp"
#include "kinematics.hpp"
#include "raymath.h"
#include "steering_behaviours/steering_behaviour.hpp"
#include "steering_behaviours/steering_behaviour_flee.hpp"
#include "steering_behaviours/steering_force.hpp"
#include "knowledge/target_knowledge.hpp"
#include "math.hpp"

OptionManager::OptionManager(Kinematics *kinematics) {
	this->option = new SteeringBehaviourFlee();
	dynamic_cast<SteeringBehaviour*>(this->option)->setKinematics(kinematics);
	this->kinematics = kinematics;
}

void OptionManager::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	this->option->update(delta_time, privateBlackboard, sharedBlackboard);
}

void OptionManager::clearOption() {
	delete this->option;
}

void OptionManager::setOption(Option* option) {
	this->clearOption();
	SteeringBehaviour* steeringBehaviourOption = dynamic_cast<SteeringBehaviour*>(option);
	if (steeringBehaviourOption != nullptr) {
		steeringBehaviourOption->setKinematics(this->kinematics);
	}
	this->option = option;
}