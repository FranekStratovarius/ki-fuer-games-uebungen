#ifndef OCTAVE_HPP
#define OCTAVE_HPP

#include "random.hpp"

class Octave {
	public:
		Octave(int rank);
		float get(float t);
		void reroll();
	private:
		Random random = Random();
		int signal_values_count;
		// array with signal values s_i
		float* signal_values;
};

#endif // OCTAVE_HPP