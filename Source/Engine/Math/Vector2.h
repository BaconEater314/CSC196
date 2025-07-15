#pragma once
#include <cassert>
#include "math.h"

namespace bacon {
	template<typename T>
	struct Vector2 {
		union {
			struct { T x, y; };
			struct { T a, b; };
		};

		Vector2() = default;
		Vector2(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const { assert(index < 2); return (&x)[index]; }
		T& operator [] (unsigned int index) { assert(index < 2); return (&x)[index]; }

		Vector2 operator + (const Vector2& v) { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator * (const Vector2& v) { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator / (const Vector2& v) { return Vector2{ x / v.x, y / v.y }; }

		Vector2 operator + (float s) const { return Vector2{ x + s, y + s }; }
		Vector2 operator - (float s) const { return Vector2{ x - s, y - s }; }
		Vector2 operator * (float s) const { return Vector2{ x * s, y * s }; }
		Vector2 operator / (float s) const { return Vector2{ x / s, y / s }; }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; };
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; };
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; };
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; };

		Vector2& operator -= (float s) { x -= s.x; y -= s.y; return *this; };
		Vector2& operator += (float s) { x += s.x; y += s.y; return *this; };
		Vector2& operator *= (float s) { x *= s.x; y *= s.y; return *this; };
		Vector2& operator /= (float s) { x /= s.x; y /= s.y; return *this; };

		// square root of (x^2 + y^2)
		float LengthSqr() const { return (x * x) + (y * y); }
		float Length() const { return bacon::math::sqrtf(LengthSqr()); }

		/// <summary>
		/// Returns a normalized (unit length) version of the vector.
		/// </summary>
		/// <returns> A Vector2 representing the normalized for of the current vector. </returns>
		Vector2 Normalized() const { return *this / Length(); }

		/// <summary>
		/// Returns the angle, in radians, between the positive x-axis and the points (x,y).
		/// </summary>
		/// <returns> The angle in radians, measured form the positive x-axis to the point (x,y). </returns>
		float Angle() const { return math::atan2f(y, x); }

		/// <summary>
		/// Returns a new vecotr that is hte result of rotaing the vector by the specified amount
		/// </summary>
		/// <param name="radians"></param>
		/// <returns></returns>
		Vector2 Rotate(float radians) const {
			Vector2 v;

			v.x = x * math::cosf(radians) - y * math::sinf(radians);
			v.y = x * math::sinf(radians) + y * math::cosf(radians);

			return v;
		}
	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
	using dvec2 = Vector2<double>;
}