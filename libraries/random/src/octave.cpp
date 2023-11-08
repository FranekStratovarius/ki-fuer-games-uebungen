#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "octave.hpp"
#include "random.hpp"

Octave::Octave(int rank) {
	this->rank = rank;

	signal_values_count = std::pow(2, rank - 1) + 1;
	signal_values = (float*)malloc(signal_values_count * sizeof(int));

	Random random = Random();

	for (int i = 0; i < signal_values_count; i++) {
		// add random number
		signal_values[i] = random.random_uniform_distribution_float(0.0f, 1.0f);
	}
}

float s_curve_interpolation(float t) {
	return std::pow(t, 3) * (10 + t * (-15 + 6 * t));
}

float Octave::get(float t) {
	int tj = std::floor(t * (signal_values_count - 1));
	int tk = std::floor(t * (signal_values_count - 1)) + 1;
	float sj = signal_values[tj];
	float sk = signal_values[tk];

	return sj + (sk - sj) * s_curve_interpolation(
		(
			t
			- (float)tj / (signal_values_count - 1)
		) / (
			(float)tk / (signal_values_count - 1)
			- (float)tj / (signal_values_count - 1)
		)
	);
}