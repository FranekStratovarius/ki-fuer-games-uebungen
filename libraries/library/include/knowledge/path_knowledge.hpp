#ifndef PATH_KNOWLEDGE
#define PATH_KNOWLEDGE

#include "raylib.h"
#include "knowledge.hpp"

class PathKnowledge : public Knowledge {
	public:
		PathKnowledge(Vector2 *path, int pathSize) {
			this->path = path;
			this->pathSize = pathSize;
		}
		Vector2 *path;
		int pathSize;
	private:	
};

#endif // PATH_KNOWLEDGE