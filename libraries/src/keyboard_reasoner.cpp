#include "keyboard_reasoner.hpp"
#include "raylib.h"
#include "steering_behaviours/steering_behaviour_seek.hpp"
#include "steering_behaviours/steering_behaviour_flee.hpp"
#include "steering_behaviours/steering_behaviour_arrive.hpp"
#include "steering_behaviours/steering_behaviour_wander.hpp"
#include "steering_behaviours/steering_behaviour_flocking.hpp"

KeyboardReasoner::KeyboardReasoner(OptionManager *optionManager) : Reasoner(optionManager) {

}

void KeyboardReasoner::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	if (IsKeyPressed(KEY_ONE)) {	// seek
		optionManager->setOption(new SteeringBehaviourSeek());
	} else if (IsKeyPressed(KEY_TWO)) {	// flee
		optionManager->setOption(new SteeringBehaviourFlee());
	} else if (IsKeyPressed(KEY_THREE)) { // arrive
		optionManager->setOption(new SteeringBehaviourArrive());
	} else if (IsKeyPressed(KEY_FOUR)) { // wander
		optionManager->setOption(new SteeringBehaviourWander());
	} else if (IsKeyPressed(KEY_FIVE)) { // flocking
		optionManager->setOption(new SteeringBehaviourFlocking());
	}
}