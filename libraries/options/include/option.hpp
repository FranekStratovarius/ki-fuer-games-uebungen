#ifndef OPTION_HPP
#define OPTION_HPP

#include "blackboard.hpp"
enum OptionState {
	DEAD,
	RUNNING,
	PAUSED
};

class Option {
	public:
		Option();
		Option(float duration);
		virtual ~Option();
		void start();
		void stop();
		void pause();
		void set_cooldown(float cooldown);
		virtual void update(float delta_time, Blackboard *privateBlackboard, Blackboard *sharedBlackboard) = 0;
		bool is_alive();
	private:
		OptionState state;
		float cooldown;
		float duration;
};

#endif // OPTION_HPP