#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include "octave.hpp"

class PerlinNoise {
	public:
		PerlinNoise(int ranks, float persistence);
		float get(float t);
	private:
		int ranks;
		float persistence;
		// array of octaves
		Octave* octaves;
};

#endif // PERLIN_NOISE_HPP