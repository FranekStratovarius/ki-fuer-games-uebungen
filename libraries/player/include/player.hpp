#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"

#include "blackboard.hpp"

class Player {
	public:
		Player();
		void update(Vector2 moveDirection, float delta_time, Blackboard *sharedBlackboard);
		void draw();
		Vector2 getPosition();
	private:
		Vector2 position;
		float rotation;
		Color color;
		float speed = 10.0f;
};

#endif // PLAYER_HPP