#pragma once
#include <cstdlib>

namespace bacon::random {
	//generates a random integer value
	inline int getRandom() { return rand(); }

	//generates a random integer in the range [0, max)
	inline int getRandom(int max) { return rand() % max; }

	//generates a random integer in the range (min, max)
	inline int getRandom(int max, int min) { return min + getRandom(max - min + 1); }

	//generates a random float in the range [0.0, 1.0]
	inline float getRandomFloat() { return rand() / (float)RAND_MAX; }
}