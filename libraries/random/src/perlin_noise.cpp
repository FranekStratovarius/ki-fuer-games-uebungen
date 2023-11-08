#include "perlin_noise.hpp"
#include "octave.hpp"
#include <cmath>
#include <cstdlib>

PerlinNoise::PerlinNoise(int ranks, float persistence) {
	this->ranks = ranks;
	this->persistence = persistence;
	octaves = (Octave*)malloc(ranks * sizeof(Octave));

	for (int i = 0; i < ranks; i++) {
		octaves[i] = Octave(i + 1);
	}
}

float PerlinNoise::get(float t) {
	float sum = 0.0f;
	for (int i = 0; i < ranks; i++) {
		sum += octaves[i].get(t) * std::pow(persistence, i + 1);
	}

	return sum;
}