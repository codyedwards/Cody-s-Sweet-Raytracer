#ifndef VECTOR3_H
#define VECTOR3_H

#include <assert.h>
#include <math.h> 
#include <stdio.h>

#include "MathLib.h"

template <class T> class vector3;

template <class T> T operator*(const vector3<T>& a, const vector3<T>& b);
template <class T> vector3<T> operator-(const vector3<T>& v);
template <class T> vector3<T> operator*(const vector3<T>& a, const double d);
template <class T> vector3<T> operator*(const double d, const vector3<T>& a);
template <class T> vector3<T> operator/(const vector3<T>& a, const double d);
template <class T> vector3<T> operator^(const vector3<T>& a, const vector3<T>& b);
template <class T> bool operator==(const vector3<T>& a, const vector3<T>& b);
template <class T> bool operator!=(const vector3<T>& a, const vector3<T>& b);

template <class T>
class vector3
{
	

public:
	// x, y, z
	T n[3];

	// Constructors
	vector3() { n[0] = 0.0; n[1] = 0.0; n[2] = 0.0; }
	vector3(const T x, const T y, const T z)
	{
		n[0] = x; n[1] = y; n[2] = z;
	}
	vector3(const vector3<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1]; n[2] = v.n[2];
	}

	//---[ Equal Operators ]---------------------

	vector3<T>& operator=(const vector3<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1]; n[2] = v.n[2];  return *this;
	}
	vector3<T>& operator +=(const vector3<T>& v)
	{
		n[0] += v.n[0]; n[1] += v.n[1]; n[2] += v.n[2]; return *this;
	}
	vector3<T>& operator -= (const vector3<T>& v)
	{
		n[0] -= v.n[0]; n[1] -= v.n[1]; n[2] -= v.n[2]; return *this;
	}
	vector3<T>& operator *= (const T d)
	{
		n[0] *= d; n[1] *= d; n[2] *= d; return *this;
	}
	vector3<T>& operator /= (const T d)
	{
		n[0] /= d; n[1] /= d; n[2] /= d; return *this;
	}

	//---[ Access Operators ]--------------------

	T& operator [](int i)
	{
		return n[i];
	}
	T operator [](int i) const
	{
		return n[i];
	}

	//---[ Arithmetic Operators ]----------------

	vector3<T> operator-(const vector3<T>& a) const { return vector3<T>(n[0] - a.n[0], n[1] - a.n[1], n[2] - a.n[2]); }
	vector3<T> operator+(const vector3<T>& a) const { return vector3<T>(a.n[0] + n[0], a.n[1] + n[1], a.n[2] + n[2]); }

	const T* getPointer() const { return n; }

	//---[ Length Methods ]----------------------

	double length2() const
	{
		return n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
	}
	double length() const
	{
		return sqrt(length2());
	}

	//---[ Normalization ]-----------------------

	void normalize() {
		double len = length();
		assert(len != 0);
		n[0] /= len; n[1] /= len; n[2] /= len;
	}

	void clamp() {
		int i;
		for (i = 0; i < 3; i++) {
			if (n[i] < 0) n[i] = 0.0;
			if (n[i] > 1) n[i] = 1.0;
		}
	}

	//---[ Zero Test ]---------------------------

	bool iszero() { return ((n[0] == 0 && n[1] == 0 && n[2] == 0) ? true : false); };
	void zeroElements() { memset(n, 0, sizeof(T)* 3); }

};

typedef vector3<int> vector3i;
typedef vector3<float> vector3f;
typedef vector3<double> vector3d;

template <class T>
inline vector3<T> operator -(const vector3<T>& v) {
	return vector3<T>(-v.n[0], -v.n[1], -v.n[2]);
}

template <class T>
inline vector3<T> operator *(const vector3<T>& a, const double d) {
	return vector3<T>(a.n[0] * d, a.n[1] * d, a.n[2] * d);
}

template <class T>
inline vector3<T> operator *(const double d, const vector3<T>& a) {
	return a * d;
}

template <class T>
inline T operator *(const vector3<T>& a, const vector3<T>& b){
	return a.n[0] * b.n[0] + a.n[1] * b.n[1] + a.n[2] * b.n[2];
}

template <class T>
inline vector3<T> operator /(const vector3<T>& a, const double d){
	return vector3<T>(a.n[0] / d, a.n[1] / d, a.n[2] / d);
}

template <class T>
inline vector3<T> operator ^(const vector3<T>& a, const vector3<T>& b) {
	return vector3<T>(a.n[1] * b.n[2] - a.n[2] * b.n[1],
		a.n[2] * b.n[0] - a.n[0] * b.n[2],
		a.n[0] * b.n[1] - a.n[1] * b.n[0]);
}

template <class T>
inline bool operator==(const vector3<T>& a, const vector3<T>& b)
{
	return (a.n[0] == b.n[0]) && (a.n[1] == b.n[1]) && (a.n[2] == b.n[2]);
}


template <class T>
inline bool operator!=(const vector3<T>& a, const vector3<T>& b)
{
	return !(a == b);
}


#endif