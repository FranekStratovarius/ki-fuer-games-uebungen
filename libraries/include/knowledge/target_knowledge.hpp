#ifndef TARGET_KNOWLEDGE
#define TARGET_KNOWLEDGE

#include "raylib.h"
#include "knowledge.hpp"

class TargetKnowledge : public Knowledge {
	public:
		TargetKnowledge(Vector2 targetPosition) {
			this->targetPosition = targetPosition;
		}
		Vector2 targetPosition;
	private:	
};

#endif // TARGET_KNOWLEDGE