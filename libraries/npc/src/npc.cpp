#include <cstdlib>

#include "raylib.h"
#include "raymath.h"

#include "npc.hpp"

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

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

void Npc::init(Vector2 position, float rotation, Color color) {
	this->position = position;
	this->rotation = rotation;
	this->color = color;
}

void Npc::move(Vector2 delta_position) {
	this->position = Vector2Add(this->position, delta_position);
}

void Npc::rotate(float angle) {
	this->rotation += angle;
}

void Npc::change_color(Color color) {
	this->color = color;
}

void Npc::draw() {
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
		SKYBLUE //this->color
	);
}