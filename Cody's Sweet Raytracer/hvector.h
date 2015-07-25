#ifndef HVECTOR_H
#define HVECTOR_H

#include <assert.h>
#include <math.h> 
#include <stdio.h>

#include "MathLib.h"

template <class T> class hvector;

template <class T> T operator*(const hvector<T>& a, const hvector<T>& b);
template <class T> hvector<T> operator-(const hvector<T>& v);
template <class T> hvector<T> operator*(const hvector<T>& a, const double d);
template <class T> hvector<T> operator*(const double d, const hvector<T>& a);
template <class T> hvector<T> operator/(const hvector<T>& a, const double d);
template <class T> bool operator==(const hvector<T>& a, const hvector<T>& b);
template <class T> bool operator!=(const hvector<T>& a, const hvector<T>& b);

template <class T>
class hvector
{
	

public:
	// x, y, z, w
	T n[4];

	// Constructors
	hvector() { n[0] = 0.0; n[1] = 0.0; n[2] = 0.0; n[3] = 0.0; }
	hvector(const T x, const T y, const T z, const T w)
	{
		n[0] = x; n[1] = y; n[2] = z; n[3] = w;
	}
	hvector(const hvector<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1]; n[2] = v.n[2]; n[3] = v.n[3];
	}

	//---[ Equal Operators ]---------------------

	hvector<T>& operator=(const hvector<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1]; n[2] = v.n[2]; n[3] = v.n[3]; return *this;
	}
	hvector<T>& operator +=(const hvector<T>& v)
	{
		n[0] += v.n[0]; n[1] += v.n[1]; n[2] += v.n[2]; n[3] += v.n[3]; return *this;
	}
	hvector<T>& operator -= (const hvector<T>& v)
	{
		n[0] -= v.n[0]; n[1] -= v.n[1]; n[2] -= v.n[2]; n[3] -= v.n[3]; return *this;
	}
	hvector<T>& operator *= (const T d)
	{
		n[0] *= d; n[1] *= d; n[2] *= d; n[3] *= d; return *this;
	}
	hvector<T>& operator /= (const T d)
	{
		n[0] /= d; n[1] /= d; n[2] /= d; n[3] /= d; return *this;
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

	hvector<T> operator-(const hvector<T>& a) const { return hvector<T>(n[0] - a.n[0], n[1] - a.n[1], n[2] - a.n[2], n[3] - a.n[3]); }
	hvector<T> operator+(const hvector<T>& a) const { return hvector<T>(a.n[0] + n[0], a.n[1] + n[1], a.n[2] + n[2], a.n[3] + n[3]); }

	//---[ Length Methods ]----------------------

	double length2() const
	{
		return n[0] * n[0] + n[1] * n[1] + n[2] * n[2] + n[3] * n[3];
	}
	double length() const
	{
		return sqrt(length2());
	}

	//---[ Zero Test ]---------------------------

	bool isZero() const { return n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0; }
	void zeroElements() { memset(n, 0, 4 * sizeof(T)); }

	//---[ Normalization ]-----------------------

	void normalize() {
		double len = length();
		assert(len != 0);
		n[0] /= len; n[1] /= len; n[2] /= len; n[3] /= len;
	}

};

typedef hvector<int> hvectori;
typedef hvector<float> hvectorf;
typedef hvector<double> hvectord;

template <class T>
inline hvector<T> operator -(const hvector<T>& v) {
	return hvector<T>(-v.n[0], -v.n[1], -v.n[2], -v.n[3]);
}

template <class T>
inline hvector<T> operator *(const hvector<T>& a, const double d) {
	return hvector<T>(a.n[0] * d, a.n[1] * d, a.n[2] * d, a.n[3] * d);
}

template <class T>
inline hvector<T> operator *(const double d, const hvector<T>& a) {
	return a * d;
}

template <class T>
inline T operator *(const hvector<T>& a, const hvector<T>& b) {
	return a.n[0] * b.n[0] + a.n[1] * b.n[1] + a.n[2] * b.n[2] + a.n[3] * b.n[3];
}

template <class T>
inline hvector<T> operator /(const hvector<T>& a, const double d) {
	return hvector<T>(a.n[0] / d, a.n[1] / d, a.n[2] / d, a.n[3] / d);
}


template <class T>
inline bool operator==(const hvector<T>& a, const hvector<T>& b)
{
	return (a.n[0] == b.n[0]) && (a.n[1] == b.n[1]) && (a.n[2] == b.n[2]) && (a.n[3] == b.n[3]);
}


template <class T>
inline bool operator!=(const hvector<T>& a, const hvector<T>& b)
{
	return !(a == b);
}


#endif