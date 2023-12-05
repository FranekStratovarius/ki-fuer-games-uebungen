#include "perlin_noise.hpp"
#include "octave.hpp"
#include <cmath>
#include <cstdlib>

PerlinNoise1D::PerlinNoise1D(int ranks, float persistence) {
	this->ranks = ranks;
	this->persistence = persistence;
	this->octaves = (Octave*)malloc(this->ranks * sizeof(Octave));

	for (int i = 1; i <= this->ranks; i++) {
		this->octaves[i] = Octave(i);
	}
}

float PerlinNoise1D::get(float t) {
	float sum = 0.0f;
	for (int i = 1; i <= this->ranks; i++) {
		sum += this->octaves[i].get(t) * std::pow(this->persistence, i);
	}

	return sum;
}

float PerlinNoise1D::update(float delta_time) {
	this->elapsed_time += delta_time;
	if (this->elapsed_time >= 1.0f) {
		this->elapsed_time = std::fmod(this->elapsed_time, 1.0f);

		for (int i = 1; i <= this->ranks; i++) {
			this->octaves[i].reroll();
		}
	}

	return this->get(this->elapsed_time);
}