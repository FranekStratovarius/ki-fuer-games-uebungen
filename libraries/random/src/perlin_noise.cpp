#include "perlin_noise.hpp"
#include "octave.hpp"
#include <cmath>
#include <cstdlib>

PerlinNoise1D::PerlinNoise1D(int ranks, float persistence) {
	this->ranks = ranks;
	this->persistence = persistence;
	octaves = (Octave*)malloc(ranks * sizeof(Octave));

	for (int i = 1; i <= ranks; i++) {
		octaves[i] = Octave(i);
	}
}

float PerlinNoise1D::get(float t) {
	float sum = 0.0f;
	for (int i = 1; i <= ranks; i++) {
		sum += octaves[i].get(t) * std::pow(persistence, i);
	}

	return sum;
}

float PerlinNoise1D::update(float delta_time) {
	elapsed_time += delta_time;
	if (elapsed_time >= 1.0f) {
		elapsed_time = std::fmod(elapsed_time, 1.0f);

		for (int i = 1; i <= ranks; i++) {
			octaves[i].reroll();
		}
	}

	return this->get(elapsed_time);
}