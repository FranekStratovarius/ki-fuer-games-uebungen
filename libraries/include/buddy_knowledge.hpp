#ifndef BUDDY_KNOWLEDGE
#define BUDDY_KNOWLEDGE

#include "raylib.h"
#include "knowledge.hpp"
#include "npc.hpp"

class BuddyKnowledge : public Knowledge {
	public:
		BuddyKnowledge(std::vector<Npc*> buddies) {
			this->buddies = buddies;
		}
		std::vector<Npc*> buddies;
	private:	
};

#endif // BUDDY_KNOWLEDGE