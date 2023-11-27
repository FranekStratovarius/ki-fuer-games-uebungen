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

	this->init(
		position,
		(float)(rand() % 200) / 100 * M_PI,
		colors[rand() % 20]
	);
}

Npc::Npc(Vector2 position, float rotation, Color color) {
	this->init(position, rotation, color);
}

Npc::~Npc() {
	delete reasoner;
	delete optionManager;
}

void Npc::draw() {
	float position_x = kinematics.position.x;
	float position_z = kinematics.position.y;
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
	reasoner->update(delta_time, &privateBlackboard, sharedBlackboard);
	// //***************** Act   *****************
	optionManager->update(delta_time, &privateBlackboard, sharedBlackboard);

	// this->move(kinematics.movementVelocity);
	// this->rotate(kinematics.rotationVelocity);

	// update position and rotation
	moveAndRotate();
}

void Npc::setSharedBlackboard(Blackboard *sharedBlackboard) {
	this->sharedBlackboard = sharedBlackboard;
}

void Npc::init(Vector2 position, float rotation, Color color) {
	kinematics.position = position;
	kinematics.rotation = rotation;
	this->color = color;
	this->reasoner = new KeyboardReasoner(optionManager);
}

void Npc::moveAndRotate() {
	Vector2 newPosition = Vector2Add(kinematics.position, kinematics.movementVelocity);
	kinematics.position = Vector2{
		Clamp(newPosition.x, -10, 10),
		Clamp(newPosition.y, -10, 10)
	};
	kinematics.rotation = kinematics.rotation + kinematics.rotationVelocity;
}