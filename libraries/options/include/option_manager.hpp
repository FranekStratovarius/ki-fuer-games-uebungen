#ifndef OPTION_MANAGER_HPP
#define OPTION_MANAGER_HPP

#include "option.hpp"
#include "blackboard.hpp"
#include "kinematics.hpp"
#include "steering_behaviour_seek.hpp"
#include "steering_behaviour_flee.hpp"
#include "steering_behaviour_arrive.hpp"

class OptionManager {
	public:
		OptionManager(Kinematics *kinematics);
		void update(
			float delta_time,
			Blackboard *privateVlackboard,
			Blackboard *sharedBlackboard
		);
		void clearOption();
		void setOption(Option* option);
	private:
		void moveAndRotate();
		SteeringBehaviourFlee steeringBehaviour;
		Kinematics *kinematics;
};

#endif // OPTION_MANAGER_HPP