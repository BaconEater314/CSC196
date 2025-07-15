#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace bacon::math {
	constexpr float pi = 3.14159265358979323846264338327950288419f;
	constexpr float twoPi = 2 * pi;
	constexpr float halfPi = pi / 2;

	//converts an angle from radians to degrees or vice versa
	constexpr float RadToDeg(float rad) { return rad * (180 / pi); }
	constexpr float DegToRad(float deg) { return deg * (pi / 180); }

	/*template <typename T>
	T min(T a, T b) {
		return std::min(a,b)//(a < b) ? a : b;
	}*/
	using std::min;
	using std::max;
	using std::clamp;
	using std::sqrt;
	using std::sqrtf;
	using std::sin;
	using std::sinf;
	using std::cos;
	using std::cosf;
	using std::tan;
	using std::tanf;
	using std::atan2;
	using std::atan2f;
}
	