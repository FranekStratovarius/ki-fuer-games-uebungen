#ifndef OCTAVE_HPP
#define OCTAVE_HPP

class Octave {
	public:
		Octave(int rank);
	private:
		int rank;
		// array with signal values s_i as touple (t, s)
		float* signal_values;
};

#endif // OCTAVE_HPP