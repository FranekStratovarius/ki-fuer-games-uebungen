#ifndef NPC_HPP
#define NPC_HPP

#include "raylib.h"

class Npc {
	public:
		Npc();
		Npc(Vector2 position, float rotation, Color color);
		void move(Vector2 delta_position);
		void rotate(float angle);
		void change_color(Color color);
		void draw();
	private:
		void init(Vector2 position, float rotation, Color color);
		Vector2 position;
		float rotation;
		Color color;
};

#endif // NPC_HPP