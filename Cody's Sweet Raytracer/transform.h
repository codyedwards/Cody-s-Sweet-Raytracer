#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <algorithm>
#include <math.h>
#include <stdio.h>

#include "MathLib.h"
#include "hvector.h"
#include "vector3.h"
#include "vector2.h"

template <class T> class transform;

template <class T> vector3<T> operator * (const transform<T>& a, const vector3<T>& v);

template <class T> inline transform<T> operator -(const transform<T>& a);
template <class T> inline transform<T> operator +(const transform<T>& a, const transform<T>& b);
template <class T> inline transform<T> operator -(const transform<T>& a, const transform<T>& b);
template <class T> inline transform<T> operator *(const transform<T>& a, const transform<T>& b);
template <class T> inline transform<T> operator *(const transform<T>& a, const double d);
template <class T> inline transform<T> operator *(const double d, const transform<T>& a);
template <class T> inline transform<T> operator /(const transform<T>& a, const double d);
template <class T> inline bool operator ==(const transform<T>& a, const transform<T>& b);
template <class T> inline bool operator !=(const transform<T>& a, const transform<T>& b);

template <class T>
class transform {

	//---[ Private Variable Declarations ]-----------------
	// matrix elements in row-major order
	T n[16];

public:

	bool isZero() { return n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0 && n[4] == 0 && n[5] == 0 && n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0 && n[10] == 0 && n[11] == 0 && n[12] == 0 && n[13] == 0 && n[14] == 0 && n[15] == 0; }

	//---[ Constructors ]----------------------------------

	transform()
	{
		memset(n, 0, 16 * sizeof(T)); n[0] = 1; n[5] = 1; n[10] = 1; n[15] = 1;
	}
	transform(T n0, T n1, T n2, T n3, T n4, T n5, T n6, T n7, T n8, T n9, T n10, T n11, T n12, T n13, T n14, T n15)
	{
		n[0] = n0; n[1] = n1; n[2] = n2; n[3] = n3;
		n[4] = n4; n[5] = n5; n[6] = n6; n[7] = n7;
		n[8] = n8; n[9] = n9; n[10] = n10; n[11] = n11;
		n[12] = n12; n[13] = n13; n[14] = n14; n[15] = n15;
	}
	transform(const transform<T>& m)
	{
		memcpy(n, m.n, 16 * sizeof(T));
	}
	transform(const hvector<T>& v0, const hvector<T>& v1, const hvector<T>& v2, const hvector<T>& v3) {
		n[0] = v0[0]; n[1] = v0[1]; n[2] = v0[2]; n[3] = v0[3];
		n[4] = v1[0]; n[5] = v1[1]; n[6] = v1[2]; n[7] = v1[3];
		n[8] = v2[0]; n[9] = v2[1]; n[10] = v2[2]; n[11] = v2[3];
		n[12] = v3[0]; n[13] = v3[1]; n[14] = v3[2]; n[15] = v3[3];
	}

	//---[ Equal Operators ]-------------------------------

	transform<T>& operator =(const transform<T>& m)
	{
		memcpy(n, m.n, 16 * sizeof(T)); return *this;
	}
	transform<T>& operator +=(const transform<T>& m)
	{
		n[0] += m.n[0]; n[1] += m.n[1]; n[2] += m.n[2]; n[3] += m.n[3];
		n[4] += m.n[4]; n[5] += m.n[5]; n[6] += m.n[6]; n[7] += m.n[7];
		n[8] += m.n[8]; n[9] += m.n[9]; n[10] += m.n[10]; n[11] += m.n[11];
		n[12] += m.n[12]; n[13] += m.n[13]; n[14] += m.n[14]; n[15] += m.n[15];
		return *this;
	}
	transform<T>& operator -=(const transform<T>& m)
	{
		n[0] -= m.n[0]; n[1] -= m.n[1]; n[2] -= m.n[2]; n[3] -= m.n[3];
		n[4] -= m.n[4]; n[5] -= m.n[5]; n[6] -= m.n[6]; n[7] -= m.n[7];
		n[8] -= m.n[8]; n[9] -= m.n[9]; n[10] -= m.n[10]; n[11] -= m.n[11];
		n[12] -= m.n[12]; n[13] -= m.n[13]; n[14] -= m.n[14]; n[15] -= m.n[15];
		return *this;
	}
	transform<T>& operator *=(const T d)
	{
		n[0] *= d; n[1] *= d; n[2] *= d; n[3] *= d;
		n[4] *= d; n[5] *= d; n[6] *= d; n[7] *= d;
		n[8] *= d; n[9] *= d; n[10] *= d; n[11] *= d;
		n[12] *= d; n[13] *= d; n[14] *= d; n[15] *= d;
		return *this;
	}
	transform<T>& operator /=(const T d)
	{
		n[0] /= d; n[1] /= d; n[2] /= d; n[3] /= d;
		n[4] /= d; n[5] /= d; n[6] /= d; n[7] /= d;
		n[8] /= d; n[9] /= d; n[10] /= d; n[11] /= d;
		n[12] /= d; n[13] /= d; n[14] /= d; n[15] /= d;
		return *this;
	}

	//---[ Access Operators ]------------------------------

	T* operator [](int i)
	{
		return &n[i * 4];
	}
	const T* operator [](int i) const
	{
		return &n[i * 4];
	}

	//---[ Ordering Methods ]------------------------------

	transform<T> transpose() const
	{
		return transform<T>(n[0], n[4], n[8], n[12],
			n[1], n[5], n[9], n[13],
			n[2], n[6], n[10], n[14],
			n[3], n[7], n[11], n[15]);
	}
	double trace() const { return n[0] + n[5] + n[10] + n[15]; }

	//---[ Transformation Matrices ]-----------------------

	static transform<T> createRotation(T angle, float x, float y, float z);
	static transform<T> createTranslation(T x, T y, T z);
	static transform<T> createScale(T sx, T sy, T sz);
	static transform<T> createShear(T shx, T shy, T shz);

	//---[ Inversion ]-------------------------------------

	transform<T> inverse() const {	    // Gauss-Jordan elimination with partial pivoting
		transform<T> a(*this);			// As a evolves from original mat into identity
		transform<T> b; 					// b evolves from identity into inverse(a)
		int	 i, j, i1;

		// Loop over cols of a from left to right, eliminating above and below diag
		for (j = 0; j<4; j++) {		// Find largest pivot in column j among rows j..2
			i1 = j;					// Row with largest pivot candidate
			for (i = j + 1; i<4; i++)
			if (fabs(a[i][j]) > fabs(a[i1][j]))
				i1 = i;

			// Swap rows i1 and j in a and b to put pivot on diagonal
			for (i = 0; i < 4; i++) {
				std::swap(a[i1][i], a[j][i]);
				std::swap(b[i1][i], b[j][i]);
			}

			// Scale row j to have a unit diagonal
			//			if (a[j][j]==0.)
			//				throw SingularMatrixException();

			double scale = a[j][j];
			for (i = 0; i < 4; i++) {
				b[j][i] /= scale;
				a[j][i] /= scale;
			}

			// Eliminate off-diagonal elems in col j of a, doing identical ops to b
			for (i = 0; i<4; i++)
			if (i != j) {
				scale = a[i][j];
				for (i1 = 0; i1 < 4; i1++) {
					b[i][i1] -= scale*b[j][i1];
					a[i][i1] -= scale*a[j][i1];
				}
			}
		}
		return b;
	}

	typedef transform<int> transformi;
	typedef transform<float> transformf;
	typedef transform<double> transformd;

	template <class T>
	inline transform<T> transform<T>::createRotation(T angle, float x, float y, float z) {
		double c = cos(angle);
		double s = sin(angle);
		double t = 1.0 - c;

		vector3<T> a(x, y, z);
		a.normalize();
		return transform<T>(
			t*a[0] * a[0] + c, t*a[0] * a[1] - s*a[2], t*a[0] * a[2] + s*a[1], 0.0,
			t*a[0] * a[1] + s*a[2], t*a[1] * a[1] + c, t*a[1] * a[2] - s*a[0], 0.0,
			t*a[0] * a[2] - s*a[1], t*a[1] * a[2] + s*a[0], t*a[2] * a[2] + c, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	template <class T>
	inline transform<T> transform<T>::createTranslation(T x, T y, T z) {
		transform<T> trans;

		trans[0][3] = x;
		trans[1][3] = y;
		trans[2][3] = z;

		return trans;
	}

	template <class T>
	inline transform<T> transform<T>::createScale(T sx, T sy, T sz) {
		transform<T> scale;
		scale[0][0] = sx;
		scale[1][1] = sy;
		scale[2][2] = sz;

		return scale;
	}

	template <class T>
	inline transform<T> transform<T>::createShear(T shx, T shy, T shz) {
		transform<T> shear;
		std::cout << "unimplemented matrix command!" << std::endl;
		return shear;
	}

	template <class T>
	inline transform<T> operator -(const transform<T>& a) {
		return transform<T>(-a.n[0], -a.n[1], -a.n[2], -a.n[3],
			-a.n[4], -a.n[5], -a.n[6], -a.n[7],
			-a.n[8], -a.n[9], -a.n[10], -a.n[11],
			-a.n[12], -a.n[13], -a.n[14], -a.n[15]);
	}

	template <class T>
	inline transform<T> operator +(const transform<T>& a, const transform<T>& b) {
		return transform<T>(a.n[0] + b.n[0], a.n[1] + b.n[1], a.n[2] + b.n[2], a.n[3] + b.n[3],
			a.n[4] + b.n[4], a.n[5] + b.n[5], a.n[6] + b.n[6], a.n[7] + b.n[7],
			a.n[8] + b.n[8], a.n[9] + b.n[9], a.n[10] + b.n[10], a.n[11] + b.n[11],
			a.n[12] + b.n[12], a.n[13] + b.n[13], a.n[14] + b.n[14], a.n[15] + b.n[15]);
	}

	template <class T>
	inline transform<T> operator -(const transform<T>& a, const transform<T>& b) {
		return transform<T>(a.n[0] - b.n[0], a.n[1] - b.n[1], a.n[2] - b.n[2], a.n[3] - b.n[3],
			a.n[4] - b.n[4], a.n[5] - b.n[5], a.n[6] - b.n[6], a.n[7] - b.n[7],
			a.n[8] - b.n[8], a.n[9] - b.n[9], a.n[10] - b.n[10], a.n[11] - b.n[11],
			a.n[12] - b.n[12], a.n[13] - b.n[13], a.n[14] - b.n[14], a.n[15] - b.n[15]);
	}

	template <class T>
	inline transform<T> operator *(const transform<T>& a, const transform<T>& b) {
		return transform<T>(a.n[0] * b.n[0] + a.n[1] * b.n[4] + a.n[2] * b.n[8] + a.n[3] * b.n[12],
			a.n[0] * b.n[1] + a.n[1] * b.n[5] + a.n[2] * b.n[9] + a.n[3] * b.n[13],
			a.n[0] * b.n[2] + a.n[1] * b.n[6] + a.n[2] * b.n[10] + a.n[3] * b.n[14],
			a.n[0] * b.n[3] + a.n[1] * b.n[7] + a.n[2] * b.n[11] + a.n[3] * b.n[15],
			a.n[4] * b.n[0] + a.n[5] * b.n[4] + a.n[6] * b.n[8] + a.n[7] * b.n[12],
			a.n[4] * b.n[1] + a.n[5] * b.n[5] + a.n[6] * b.n[9] + a.n[7] * b.n[13],
			a.n[4] * b.n[2] + a.n[5] * b.n[6] + a.n[6] * b.n[10] + a.n[7] * b.n[14],
			a.n[4] * b.n[3] + a.n[5] * b.n[7] + a.n[6] * b.n[11] + a.n[7] * b.n[15],
			a.n[8] * b.n[0] + a.n[9] * b.n[4] + a.n[10] * b.n[8] + a.n[11] * b.n[12],
			a.n[8] * b.n[1] + a.n[9] * b.n[5] + a.n[10] * b.n[9] + a.n[11] * b.n[13],
			a.n[8] * b.n[2] + a.n[9] * b.n[6] + a.n[10] * b.n[10] + a.n[11] * b.n[14],
			a.n[8] * b.n[3] + a.n[9] * b.n[7] + a.n[10] * b.n[11] + a.n[11] * b.n[15],
			a.n[12] * b.n[0] + a.n[13] * b.n[4] + a.n[14] * b.n[8] + a.n[15] * b.n[12],
			a.n[12] * b.n[1] + a.n[13] * b.n[5] + a.n[14] * b.n[9] + a.n[15] * b.n[13],
			a.n[12] * b.n[2] + a.n[13] * b.n[6] + a.n[14] * b.n[10] + a.n[15] * b.n[14],
			a.n[12] * b.n[3] + a.n[13] * b.n[7] + a.n[14] * b.n[11] + a.n[15] * b.n[15]);
	}

	template <class T>
	inline transform<T> operator *(const transform<T>& a, const double d) {
		return transform<T>(a.n[0] * d, a.n[1] * d, a.n[2] * d, a.n[3] * d,
			a.n[4] * d, a.n[5] * d, a.n[6] * d, a.n[7] * d,
			a.n[8] * d, a.n[9] * d, a.n[10] * d, a.n[11] * d,
			a.n[12] * d, a.n[13] * d, a.n[14] * d, a.n[15] * d);
	}

	template <class T>
	inline transform<T> operator *(const double d, const transform<T>& a) {
		return transform<T>(a.n[0] * d, a.n[1] * d, a.n[2] * d, a.n[3] * d,
			a.n[4] * d, a.n[5] * d, a.n[6] * d, a.n[7] * d,
			a.n[8] * d, a.n[9] * d, a.n[10] * d, a.n[11] * d,
			a.n[12] * d, a.n[13] * d, a.n[14] * d, a.n[15] * d);
	}

	template <class T>
	inline transform<T> operator /(const transform<T>& a, const double d) {
		return transform<T>(a.n[0] / d, a.n[1] / d, a.n[2] / d, a.n[3] / d,
			a.n[4] / d, a.n[5] / d, a.n[6] / d, a.n[7] / d,
			a.n[8] / d, a.n[9] / d, a.n[10] / d, a.n[11] / d,
			a.n[12] / d, a.n[13] / d, a.n[14] / d, a.n[15] / d);
	}

	template <class T>
	inline bool operator ==(const transform<T>& a, const transform<T>& b) {
		return !memcmp(a.n, b.n, 16 * sizeof(T));
	}

	template <class T>
	inline bool operator !=(const transform<T>& a, const transform<T>& b) {
		return memcmp(a.n, b.n, 16 * sizeof(T));
	}

#endif TRANSFORM_H