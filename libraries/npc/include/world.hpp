#ifndef WORLD_HPP
#define WORLD_HPP

#include "npc.hpp"

class World {
	public:
		void draw_npcs_in_world();
	private:
		Npc* npcs_in_world;
};

#endif // WORLD_HPP