#include "option.hpp"

Option::Option() {}

Option::Option(float duration) {
	this->duration = duration;
}

void Option::start() {
	this->state = RUNNING;
}

void Option::stop() {
	this->state = DEAD;
	// maybe reset some attributes?
}

void Option::pause() {
	this->state = PAUSED;
}

void Option::set_cooldown(float cooldown) {
	this->cooldown = cooldown;
}

bool Option::is_alive() {
	return this->state == RUNNING;
}