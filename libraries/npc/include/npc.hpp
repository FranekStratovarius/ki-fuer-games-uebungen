#ifndef NPC_HPP
#define NPC_HPP

#include <vector>

#include "raylib.h"

#include "kinematics.hpp"
#include "blackboard.hpp"
// #include "sensor_manager.hpp"
// #include "reasoner_manager.hpp"
#include "reasoner.hpp"
#include "option_manager.hpp"

class Npc {
	public:
		Npc();
		Npc(Vector2 position, float rotation, Color color);
		~Npc();
		void draw();
		void update(float delta_time);
		void setSharedBlackboard(Blackboard *sharedBlackboard);
	private:
		void init(Vector2 position, float rotation, Color color);
		void moveAndRotate();

		// current status of the npc
		Color color;
		// kinematic information
		Kinematics kinematics = {
			Vector2{0.0f, 0.0f},
			0.0f,
			Vector2{0.0f, 0.0f},
			0.0f,
			0.3f,
			0.1f,
			0.1f,
			0.3f,
		};
		// blackboards for shared and private informations
		Blackboard privateBlackboard;
		Blackboard *sharedBlackboard;

		/*
		 * der sensor schaut in die spielwelt und sammelt alle nötigen
		 * informationen in das private blackboard des npcs
		 */
		// SensorManager sensorManager;
		/*
		 * der reasoner bekommt die blackboards des npcs und den pointer zur
		 * aktuellen option und kann diese dann abändern
		 */
		// ReasonerManager reasonerManager;
		Reasoner *reasoner;
		/*
		 * die option bekommt die kinematik des npcs und kann diese von den
		 * blackboards abhängig anpassen
		 *
		 * ggf kann man der option auch mehr schnittstellen zum npc wie die
		 * farbe geben, aber aktuell ist nicht mehr nötig
		 */
		OptionManager *optionManager = new OptionManager(&kinematics);
};

#endif // NPC_HPP