#ifndef HVECTOR_H
#define HVECTOR_H

#include "MathLib.h"

template <class T> class hvector;

template <class T> T operator*(const hvector<T>& a, const hvector<T>& b);
template <class T> hvector<T> operator-(const hvector<T>& v);
template <class T> hvector<T> operator*(const hvector<T>& a, const double d);
template <class T> hvector<T> operator*(const double d, const hvector<T>& a);
template <class T> hvector<T> operator/(const hvector<T>& a, const double d);
template <class T> hvector<T> operator^(const hvector<T>& a, const hvector<T>& b);
template <class T> bool operator==(const hvector<T>& a, const hvector<T>& b);
template <class T> bool operator!=(const hvector<T>& a, const hvector<T>& b);

template <class T>
class hvector
{
	// x, y, z, w
	T n[4];

public:


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

	hvector<T> operator-(const hvector<T>& a) { return hvector<T>(n[0] - a.n[0], n[1] - a.n[1], n[2] - a.n[2]); n[3] - a.n[3]); }
	hvector<T> operator+(const hvector<T>& a) { return hvector<T>(a.n[0] + n[0], a.n[1] + n[1], a.n[2] + n[2]); a.n[3] + n[3]); }

};

typedef hvector<int> hvectori;
typedef hvector<float> hvectorf;
typedef hvector<double> hvectord;

// Dot product
template <class T>
inline T& operator * (const hvector<T> & a, const hvector<T> & b)
{
	return (a.n[0] * b.n[0]) + (a.n[1] * b.n[1]) + (a.n[2] * b.n[2]);
}

// Cross product
template <class T>
inline hvector<T>& operator ^ (const hvector<T> & a, const hvector<T> & b)
{
	return hvector<T>((a.n[1] * b.n[2]) - (a.n[2] * b.n[1]),
		(a.n[2] * b.n[0]) - (a.n[0] * b.n[2]),
		(a.n[0] * b.n[1]) - (a.n[1] * b.n[0]));
}

template <class T>
inline bool operator==(const hvector<T>& a, const hvector<T>& b)
{
	return a.n[0] == b.n[0] && a.n[1] == b.n[1] && a.n[2] == b.n[2];
}


template <class T>
inline bool operator!=(const hvector<T>& a, const hvector<T>& b)
{
	return !(a == b);
}


#endif