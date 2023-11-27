#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "octave.hpp"

Octave::Octave(int rank) {
	this->signal_values_count = std::pow(2, rank - 1) + 1;
	this->signal_values = (float*)malloc(this->signal_values_count * sizeof(int));

	for (int i = 0; i < this->signal_values_count; i++) {
		// add random number
		this->signal_values[i] = random.random_uniform_distribution_float(0.0f, 1.0f);
	}
}

float s_curve_interpolation(float t) {
	return std::pow(t, 3) * (10 + t * (-15 + 6 * t));
}

float Octave::get(float t) {
	// get signal_value time before t
	int tj = std::floor(t * (this->signal_values_count - 1));
	// get signal_value time after t
	int tk = std::floor(t * (this->signal_values_count - 1)) + 1;
	// get signal_value before t
	float sj = this->signal_values[tj];
	// get signal_value after t
	float sk = this->signal_values[tk];

	return sj + (sk - sj) * s_curve_interpolation(
		(
			t
			- (float)tj / (this->signal_values_count - 1)
		) / (
			(float)tk / (this->signal_values_count - 1)
			- (float)tj / (this->signal_values_count - 1)
		)
	);
}

/*
 * Reroll octave for continuous use.
 */
void Octave::reroll() {
	// last previous end is now the new beginning
	this->signal_values[0] = this->signal_values[this->signal_values_count - 1];
	for (int i = 1; i < this->signal_values_count; i++) {
		// reroll random number
		this->signal_values[i] = random.random_uniform_distribution_float(0.0f, 1.0f);
	}	
}