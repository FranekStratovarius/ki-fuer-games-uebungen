#include "buddy_knowledge.hpp"

#include "steering_behaviours/steering_behaviour_flocking.hpp"

SteeringBehaviourFlocking::SteeringBehaviourFlocking() {
	steeringBehaviourCohesion = new SteeringBehaviourCohesion();
	steeringBehaviourSeperation = new SteeringBehaviourSeperation();
	steeringBehaviourVelocityMatching = new SteeringBehaviourVelocityMatching();
}

SteeringBehaviourFlocking::~SteeringBehaviourFlocking() {
		delete steeringBehaviourCohesion;
		delete steeringBehaviourSeperation;
		delete steeringBehaviourVelocityMatching;
}

void SteeringBehaviourFlocking::setKinematics(Kinematics *kinematics) {
	this->kinematics = kinematics;
	steeringBehaviourCohesion->setKinematics(this->kinematics);
	steeringBehaviourSeperation->setKinematics(this->kinematics);
	steeringBehaviourVelocityMatching->setKinematics(this->kinematics);
}

void SteeringBehaviourFlocking::getKnowledge(Blackboard *privateBlackboard, Blackboard *sharedBlackboard) {
	buddies = dynamic_cast<BuddyKnowledge*>(
		sharedBlackboard->getKnowledge("buddies")
	)->buddies;

	this->steeringBehaviourCohesion->getKnowledge(privateBlackboard, sharedBlackboard);
	this->steeringBehaviourSeperation->getKnowledge(privateBlackboard, sharedBlackboard);
	this->steeringBehaviourVelocityMatching->getKnowledge(privateBlackboard, sharedBlackboard);
}

SteeringForce SteeringBehaviourFlocking::getForce() {
	if (buddies.empty()) {
		return SteeringForce();
	}

	SteeringForce steeringForce = SteeringForce();

	steeringForce += this->steeringBehaviourCohesion->getForce();
	steeringForce += this->steeringBehaviourSeperation->getForce();
	steeringForce += this->steeringBehaviourVelocityMatching->getForce();

	return steeringForce;	
}