#include "world.hpp"

World::World() : World(10) {}

World::World(int number_of_npcs) {
	sharedBlackboard = new Blackboard();
	for(int i= 0; i < number_of_npcs; i++) {
		Npc *npc = new Npc();
		npcs_in_world.push_back(npc);
		npc->setSharedBlackboard(sharedBlackboard);
	}
}

World::~World() {
	delete sharedBlackboard;
	for (Npc *npc : npcs_in_world) {
		delete npc;
	}
	npcs_in_world.clear();
}

void World::update(float delta_time) {
	for (Npc *npc : npcs_in_world) {
		npc->update(delta_time);
	}
}

void World::draw() {
	for (Npc *npc : npcs_in_world) {
		npc->draw();
	}
}

Blackboard *World::getSharedBlackboard() {
	return sharedBlackboard;
}