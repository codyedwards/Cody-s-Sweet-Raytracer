#ifndef VECTOR3_H
#define VECTOR3_H

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
	// x, y, z
	T n[3];

public:


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

	vector3<T> operator-(const vector3<T>& a) { return vector3<T>(n[0] - a.n[0], n[1] - a.n[1], n[2] - a.n[2]); }
	vector3<T> operator+(const vector3<T>& a) { return vector3<T>(a.n[0] + n[0], a.n[1] + n[1], a.n[2] + n[2]); }

};

typedef vector3<int> vector3i;
typedef vector3<float> vector3f;
typedef vector3<double> vector3d;

// Dot product
template <class T>
inline T& operator * (const vector3<T> & a, const vector3<T> & b)
{
	return (a.n[0] * b.n[0]) + (a.n[1] * b.n[1]) + (a.n[2] * b.n[2]);
}

// Cross product
template <class T>
inline vector3<T>& operator ^ (const vector3<T> & a, const vector3<T> & b)
{
	return vector3<T>((a.n[1] * b.n[2]) - (a.n[2] * b.n[1]),
						(a.n[2] * b.n[0]) - (a.n[0] * b.n[2]),
						(a.n[0] * b.n[1]) - (a.n[1] * b.n[0]));
}

template <class T>
inline bool operator==(const vector3<T>& a, const vector3<T>& b)
{
	return a.n[0] == b.n[0] && a.n[1] == b.n[1] && a.n[2] == b.n[2];
}


template <class T>
inline bool operator!=(const vector3<T>& a, const vector3<T>& b)
{
	return !(a == b);
}


#endif