#include <cstdio>

#include "player.hpp"
#include "knowledge/target_knowledge.hpp"

Player::Player() {
	this->position = Vector2{0.0, 0.0};
	this->rotation = 0.0f;
	this->color = RED;
}

void Player::update(Vector2 moveDirection, float delta_time, Blackboard *sharedBlackboard) {
	this->position = Vector2Add(
		this->position,
		Vector2Scale(
			moveDirection,
			delta_time * this->speed
		)
	);
	if (moveDirection.x != 0 || moveDirection.y != 0) {
		this->rotation = atan2(
			moveDirection.y,
			moveDirection.x
		);
	}
	sharedBlackboard->setKnowledge("target_position", new TargetKnowledge(position));
	sharedBlackboard->setKnowledge("food_place", new TargetKnowledge(position));
}

void Player::draw() {
	float position_x = this->position.x;
	float position_z = this->position.y;
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
	Vector2 nose_position = Vector2Add(this->position, Vector2Rotate({1, 0}, this->rotation));
	DrawSphere(
		{nose_position.x, 2.5f, nose_position.y},
		0.5f,
		SKYBLUE
	);
}

Vector2 Player::getPosition() {
	return this->position;
}