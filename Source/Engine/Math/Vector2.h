#pragma once
#include <cassert>
#include <math.h>

template<typename T>
struct Vector2 {
	T x, y;

	Vector2() = default;
	Vector2(T x, T y) : x{ x }, y{ y } {}

	T operator [] (unsigned int index) const { asser(index < 2); return (&x)[index]; }
	T& operator [] (unsigned int index) { asser(index < 2); return (&x)[index]; }

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
	float LengthSqr() const { return ((x * x) + (y * y); }
	float Length() const { return bacon::math::sqrtf(LengthSqr()); }
};

using ivec2 = Vector2<int>;
using vec2 = Vector2<float>;
using dvec2 = Vector2<double>;