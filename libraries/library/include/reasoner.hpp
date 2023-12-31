#ifndef REASONER_HPP
#define REASONER_HPP

#include "option_manager.hpp"

class Reasoner {
	public:
		virtual ~Reasoner();
		void setOptionManager(OptionManager *optionManager);
		virtual void update(
			float delta_time,
			Blackboard *privateBlackboard,
			Blackboard *sharedBlackboard
		) = 0;
	protected:
		// object is not managed by reasoner class
		OptionManager *optionManager;
};

#endif // REASONER_HPP