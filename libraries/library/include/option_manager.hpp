#ifndef OPTION_MANAGER_HPP
#define OPTION_MANAGER_HPP

#include "option.hpp"
#include "blackboard.hpp"
#include "kinematics.hpp"

class OptionManager {
	public:
		OptionManager(Kinematics *kinematics);
		void update(
			float delta_time,
			Blackboard *privateBlackboard,
			Blackboard *sharedBlackboard
		);
		void clearOption();
		void setOption(Option* option);
	private:
	// managed
		Option *option;
		// not managed
		Kinematics *kinematics;
};

#endif // OPTION_MANAGER_HPP