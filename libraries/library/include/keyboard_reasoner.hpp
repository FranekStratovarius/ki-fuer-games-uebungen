#ifndef KEYBOARD_REASONER_HPP
#define KEYBOARD_REASONER_HPP

#include "option_manager.hpp"
#include "reasoner.hpp"

class KeyboardReasoner : public Reasoner {
	public:
		void update(
			float delta_time,
			Blackboard *privateBlackboard,
			Blackboard *sharedBlackboard
		) override;
	private:
};

#endif // KEYBOARD_REASONER_HPP