#include "option_manager.hpp"
#include "kinematics.hpp"
#include "raymath.h"
#include "steering_force.hpp"
#include "target_knowledge.hpp"
#include "math.hpp"

OptionManager::OptionManager(Kinematics *kinematics) {
	steeringBehaviour = SteeringBehaviourFlee(kinematics);
	this->kinematics = kinematics;
}

void OptionManager::update(float delta_time, Blackboard *privateVlackboard, Blackboard *sharedBlackboard) {
	TargetKnowledge *targetKnowledge = dynamic_cast<TargetKnowledge*>(
		sharedBlackboard->getKnowledge("target_position")
	);
	if(targetKnowledge != nullptr) {
		Vector2 targetPosition = targetKnowledge->targetPosition;
		steeringBehaviour.setTarget(targetPosition);
		SteeringForce steeringForce = steeringBehaviour.getForce();

		// limit forces
		steeringForce.movementForce = limit(
			Vector2Scale(steeringForce.movementForce, delta_time),
			kinematics->maxMovementForce
		);
		steeringForce.rotationForce = limit(
			steeringForce.rotationForce,
			kinematics->maxRotationForce
		);
		// update kinematics
		kinematics->movementVelocity = limit(
			Vector2Add(
				kinematics->movementVelocity,
				steeringForce.movementForce
			),
			kinematics->maxMovementVelocity
		);
		kinematics->rotationVelocity = limit(
			steeringForce.rotationForce,
			kinematics->maxMovementVelocity
		);
		// update position and rotation
		moveAndRotate();
	}
}

void OptionManager::clearOption() {

}

void OptionManager::setOption(Option* option) {
	
}

void OptionManager::moveAndRotate() {
	Vector2 newPosition = Vector2Add(kinematics->position, kinematics->movementVelocity);
	kinematics->position = Vector2{
		Clamp(newPosition.x, -10, 10),
		Clamp(newPosition.y, -10, 10)
	};
	kinematics->rotation = kinematics->rotation + kinematics->rotationVelocity;
}