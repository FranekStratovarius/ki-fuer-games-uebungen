#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random {
	public:
		// initialize seed
		Random();
		// get random int in range (start inclusive, end exclusive)
		int random_uniform_distribution_int(int start, int end);
		// get random float in range (inclusive)
		float random_uniform_distribution_float(float start, float end);

		// get random int in range (start inclusive, end exclusive)
		int random_normal_distribution_int(int start, int end);
		int random_normal_distribution_int(
			int start, int end,
			float mean, float stddev
		);
		// get random float in range (inclusive)
		float random_normal_distribution_float(float start, float end);
		float random_normal_distribution_float(
			float start, float end,
			float mean, float stddev
		);
	private:
		float roll_normal_deviation(float mean, float stddev);
};

#endif // RANDOM_HPP