#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>
#include <algorithm>

#define NAME "Nick\n"

using namespace bacon;

int main() {
	const float num = math::RadToDeg(math::pi);
	math::min(5, 3);
	math::clamp(1,2,3);

	std::cout << NAME;
	std::cout << "Hello World\n";
	std::cout << math::pi << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << random::getRandomFloat() << std::endl;
	}
}