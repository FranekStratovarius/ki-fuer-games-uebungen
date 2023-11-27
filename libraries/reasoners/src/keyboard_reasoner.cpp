#include "keyboard_reasoner.hpp"
#include "raylib.h"
#include "steering_behaviour_arrive.hpp"
#include "steering_behaviour_flee.hpp"
#include "steering_behaviour_seek.hpp"

KeyboardReasoner::KeyboardReasoner(OptionManager *optionManager) : Reasoner(optionManager) {

}

void KeyboardReasoner::update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	if (IsKeyPressed(KEY_ONE)) {	// seek
		optionManager->setOption(new SteeringBehaviourSeek());
	} else if (IsKeyPressed(KEY_TWO)) {	// flee
		optionManager->setOption(new SteeringBehaviourFlee());
	} else if (IsKeyPressed(KEY_THREE)) { // arrive
		optionManager->setOption(new SteeringBehaviourArrive());
	}
}