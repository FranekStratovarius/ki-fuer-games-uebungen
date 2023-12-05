#include "keyboard_reasoner.hpp"
#include "raylib.h"
#include "steering_behaviours/steering_behaviour_seek.hpp"
#include "steering_behaviours/steering_behaviour_flee.hpp"
#include "steering_behaviours/steering_behaviour_arrive.hpp"
#include "steering_behaviours/steering_behaviour_wander.hpp"
#include "steering_behaviours/steering_behaviour_flocking.hpp"
#include "steering_behaviours/steering_behaviour_path_grappling_hooks.hpp"

void KeyboardReasoner::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	if (IsKeyPressed(KEY_ONE)) {	// seek
		this->optionManager->setOption(new SteeringBehaviourSeek());
	} else if (IsKeyPressed(KEY_TWO)) {	// flee
		this->optionManager->setOption(new SteeringBehaviourFlee());
	} else if (IsKeyPressed(KEY_THREE)) { // arrive
		this->optionManager->setOption(new SteeringBehaviourArrive());
	} else if (IsKeyPressed(KEY_FOUR)) { // wander
		this->optionManager->setOption(new SteeringBehaviourWander());
	} else if (IsKeyPressed(KEY_FIVE)) { // flocking
		this->optionManager->setOption(new SteeringBehaviourFlocking());
	} else if (IsKeyPressed(KEY_SIX)) { // grappling hooks
		this->optionManager->setOption(new SteeringBehaviourPathGrapplingHooks());
	}
}