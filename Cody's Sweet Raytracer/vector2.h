#ifndef VECTOR2_H
#define VECTOR2_H

#include "MathLib.h"

template <class T> class vector2;

template <class T> T operator*(const vector2<T>& a, const vector2<T>& b);
template <class T> vector2<T> operator-(const vector2<T>& v);
template <class T> vector2<T> operator*(const vector2<T>& a, const double d);
template <class T> vector2<T> operator*(const double d, const vector2<T>& a);
template <class T> vector2<T> operator/(const vector2<T>& a, const double d);
template <class T> vector2<T> operator^(const vector2<T>& a, const vector2<T>& b);
template <class T> bool operator==(const vector2<T>& a, const vector2<T>& b);
template <class T> bool operator!=(const vector2<T>& a, const vector2<T>& b);

template <class T>
class vector2
{
	// x, y
	T n[2];

public:
	

	// Constructors
	vector2() { n[0] = 0.0; n[1] = 0.0; }
	vector2(const T x, const T y)
	{
		n[0] = x; n[1] = y;
	}
	vector2(const vector2<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1];
	}

	//---[ Equal Operators ]---------------------

	vector2<T>& operator=(const vector2<T>& v)
	{
		n[0] = v.n[0]; n[1] = v.n[1]; return *this;
	}
	vector2<T>& operator +=(const vector2<T>& v)
	{
		n[0] += v.n[0]; n[1] += v.n[1]; return *this;
	}
	vector2<T>& operator -= (const vector2<T>& v)
	{
		n[0] -= v.n[0]; n[1] -= v.n[1]; return *this;
	}
	vector2<T>& operator *= (const T d)
	{
		n[0] *= d; n[1] *= d; return *this;
	}
	vector2<T>& operator /= (const T d)
	{
		n[0] /= d; n[1] /= d; return *this;
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

	vector2<T> operator-(const vector2<T>& a) { return vector2<T>(n[0] - a.n[0], n[1] - a.n[1]); }
	vector2<T> operator+(const vector2<T>& a) { return vector2<T>(a.n[0] + n[0], a.n[1] + n[1]); }

};

typedef vector2<int> vector2i;
typedef vector2<float> vector2f;
typedef vector2<double> vector2d;

// Dot product
template <class T>
inline T& operator * (const vector2<T> & a, const vector2<T> & b)
{
	return (a.n[0] * b.n[0]) + (a.n[1] * b.n[1]);
}

// Cross product
template <class T>
inline vector2<T>& operator ^ (const vector2<T> & a, const vector2<T> & b)
{
	return vector2<T>((a.n[0] * b.n[1]) - (a.n[1] * b.n[0]));
}

template <class T> 
inline bool operator==(const vector2<T>& a, const vector2<T>& b)
{
	return a.n[0] == b.n[0] && a.n[1] == b.n[1];
}


template <class T> 
inline bool operator!=(const vector2<T>& a, const vector2<T>& b)
{
	return !(a == b);
}


#endif