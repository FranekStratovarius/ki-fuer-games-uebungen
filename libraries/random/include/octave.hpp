#ifndef OCTAVE_HPP
#define OCTAVE_HPP

class Octave {
	public:
		Octave(int rank);
		float get(float t);
	private:
		int rank;
		int signal_values_count;
		// array with signal values s_i as touple (t, s)
		float* signal_values;
};

#endif // OCTAVE_HPP