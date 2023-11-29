#include "world.hpp"
#include "buddy_knowledge.hpp"

World::World() : World(10) {}

World::World(int number_of_npcs) {
	sharedBlackboard = new Blackboard();
	for(int i= 0; i < number_of_npcs; i++) {
		Npc *npc = new Npc();
		this->npcs_in_world.push_back(npc);
		npc->setSharedBlackboard(sharedBlackboard);
	}
	sharedBlackboard->setKnowledge(
		"buddies",
		new BuddyKnowledge(this->npcs_in_world)
	);
}

World::~World() {
	delete sharedBlackboard;
	for (Npc *npc : this->npcs_in_world) {
		delete npc;
	}
	this->npcs_in_world.clear();
}

void World::update(float delta_time) {
	for (Npc *npc : this->npcs_in_world) {
		npc->update(delta_time);
	}
}

void World::draw() {
	for (Npc *npc : this->npcs_in_world) {
		npc->draw();
	}
}

Blackboard *World::getSharedBlackboard() {
	return sharedBlackboard;
}