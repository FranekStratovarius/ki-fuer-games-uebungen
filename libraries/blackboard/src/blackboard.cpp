#include "blackboard.hpp"

Blackboard::~Blackboard() {
	for (const std::pair<const std::string, Knowledge*> &element : blackboard) {
		delete element.second;
	}
}

void Blackboard::setKnowledge(std::string key, Knowledge *knowledge) {
	// key is already used, delete knowledge first and then replace it
	if (blackboard.find(key) != blackboard.end()) {
		delete blackboard[key];
	}
	blackboard[key] = knowledge;
}

Knowledge *Blackboard::getKnowledge(std::string key) {
	return blackboard[key];
}