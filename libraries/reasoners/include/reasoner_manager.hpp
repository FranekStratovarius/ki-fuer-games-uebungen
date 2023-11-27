#ifndef REASONER_MANAGER_HPP
#define REASONER_MANAGER_HPP

#include "blackboard.hpp"

class ReasonerManager {
	public:
		ReasonerManager();
		void update(
			float delta_time,
			Blackboard *privateBlackboard,
			Blackboard *sharedBlackboard
		);
	private:
};

#endif // REASONER_MANAGER_HPP