#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "random.hpp"

Random::Random() {
	std::srand(std::time(nullptr));
}

int Random::random_uniform_distribution_int(int start, int end) {
	return std::rand() % (end - start) + start;
}

float Random::random_uniform_distribution_float(float start, float end) {
	return (float)std::rand() / (float)RAND_MAX * (end - start) + start;
}
	
int Random::random_normal_distribution_int(int start, int end) {
	return random_normal_distribution_float(start, end);
}

int Random::random_normal_distribution_int(
	int start, int end,
	float mean, float stddev
) {
	return random_normal_distribution_float(start, end, mean, stddev);
}
	
float Random::random_normal_distribution_float(float start, float end) {
	return random_normal_distribution_float(
		start,
		end,
		start + (end - start) / 2.0f,
		4.0
	);
}

float Random::roll_normal_deviation(float mean, float stddev) {
	float standart_normal_distribution = (
		random_uniform_distribution_float(-1.0f, 1.0f)
		+ random_uniform_distribution_float(-1.0f, 1.0f)
		+ random_uniform_distribution_float(-1.0f, 1.0f))
		* stddev + mean;

	return standart_normal_distribution;
}

float Random::random_normal_distribution_float(
	float start, float end,
	float mean, float stddev
) {
	// roll normal distribution untill it is in bounds
	float normal_distribution = roll_normal_deviation(mean, stddev);
	//*
	while (normal_distribution < start
		|| normal_distribution > end) {
		normal_distribution = roll_normal_deviation(mean, stddev);
	}
	//*/

	return normal_distribution;
}