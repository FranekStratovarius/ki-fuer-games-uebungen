#ifndef BLACKBOARD_HPP
#define BLACKBOARD_HPP

#include <string>
#include <unordered_map>

#include "knowledge.hpp"

class Blackboard {
	public:
	// delete all entries in the blackboard
		~Blackboard();
		// set knowledge in blackboard
		void setKnowledge(std::string key, Knowledge *knowledge);
		// get knowledge from blackboard
		Knowledge *getKnowledge(std::string key);
	private:
		// hash map as knowledge database
		std::unordered_map<std::string, Knowledge*> blackboard;
};

#endif // BLACKBOARD_HPP