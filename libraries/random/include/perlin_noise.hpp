#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include "octave.hpp"

class PerlinNoise1D {
	public:
		PerlinNoise1D(int ranks, float persistence);
		float get(float t);
		float update(float delta_time);
	private:
		int ranks;
		float persistence;
		// array of octaves
		Octave* octaves;
		// used for continuous update
		float elapsed_time = 0.0f;
};

#endif // PERLIN_NOISE_HPP