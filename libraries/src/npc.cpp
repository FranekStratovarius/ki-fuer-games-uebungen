#include <cstdio>

#include "blackboard.hpp"
#include "keyboard_reasoner.hpp"
#include "raylib.h"
#include "raymath.h"

#include "npc.hpp"
#include "target_knowledge.hpp"

Npc::Npc() {
	Vector2 position = {
		(float)(rand() % 200) / 10 - 10,
		(float)(rand() % 200) / 10 - 10
	};

	Color colors[] = {
		LIGHTGRAY,
		GRAY,
		DARKGRAY,
		YELLOW,
		GOLD,
		ORANGE,
		PINK,
		RED,
		MAROON,
		GREEN,
		LIME,
		DARKGREEN,
		BLUE,
		DARKBLUE,
		PURPLE,
		VIOLET,
		DARKPURPLE,
		BEIGE,
		BROWN,
		DARKBROWN
	};
	
	this->kinematics.position = position;
	this->kinematics.rotation = (float)(rand() % 200) / 100 * M_PI;
	this->color = colors[rand() % 20];

	this->optionManager = new OptionManager(&this->kinematics);
	this->reasoner = new KeyboardReasoner(this->optionManager);
}

Npc::~Npc() {
	delete reasoner;
	delete optionManager;
}

void Npc::draw() {
	float position_x = this->kinematics.position.x;
	float position_z = this->kinematics.position.y;
	// draw main body
	DrawCapsule(
		(Vector3) {position_x, 1.0f, position_z},
		(Vector3) {position_x, 3.0f, position_z},
		1,
		32,
		32,
		this->color
	);
	// draw nose
	Vector2 nose_position = Vector2Add(kinematics.position, Vector2Rotate({1, 0}, kinematics.rotation));
	DrawSphere(
		{nose_position.x, 2.5f, nose_position.y},
		0.5f,
		SKYBLUE
	);
}

void Npc::update(float delta_time) {
	// //***************** Sense *****************
	// sensorManager.update(delta_time);
	// //***************** Think *****************
	// reasonerManager.update(delta_time);
	this->reasoner->update(delta_time, &privateBlackboard, sharedBlackboard);
	// //***************** Act   *****************
	this->optionManager->update(delta_time, &privateBlackboard, sharedBlackboard);

	// this->move(kinematics.movementVelocity);
	// this->rotate(kinematics.rotationVelocity);

	// update position and rotation
	moveAndRotate();
}

void Npc::setSharedBlackboard(Blackboard *sharedBlackboard) {
	this->sharedBlackboard = sharedBlackboard;
}

Kinematics *Npc::getKinematics() {
	return &this->kinematics;
}

void Npc::moveAndRotate() {
	Vector2 newPosition = Vector2Add(kinematics.position, kinematics.movementVelocity);
	this->kinematics.position = Vector2{
		Clamp(newPosition.x, -40, 40),
		Clamp(newPosition.y, -40, 40)
	};
	this->kinematics.rotation = kinematics.rotation + kinematics.rotationVelocity;
}