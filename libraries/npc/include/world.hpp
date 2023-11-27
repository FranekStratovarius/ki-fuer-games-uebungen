#ifndef WORLD_HPP
#define WORLD_HPP

#include "npc.hpp"
#include "blackboard.hpp"

class World {
	public:
		World();
		World(int number_of_npcs);
		~World();
		void update(float delta_time);
		void draw();
		Blackboard *getSharedBlackboard();
	private:
		std::vector<Npc*> npcs_in_world;
		Blackboard *sharedBlackboard;
};

#endif // WORLD_HPP