#ifndef MATHLIB_H
#define MATHLIB_H
#define LARGE_VAL 1e10


class MathLib
{
public:
	

	// structure that stores upto 5 floating point numbers
	struct retval
	{
		unsigned short num_val;
		double value[5];
	};

	MathLib() { }

	// returns a / b (0 / 0 = 0, overflow = LARGE_VAL with correct sign)
	double safeDiv(double a, double b)
	{
		if (b == 0)
		{
			if (a == 0)
				return 0;
			else
				return LARGE_VAL * sign(a);
		}
		else
		{
			if (a == 0)
				return 0;
			else
			{
				if ((a + b) == a)
					return LARGE_VAL * sign(a) * sign(b);
				else
					return a / b;
			}
		}
	}

	float safeDiv(float a, float b)
	{
		if (b == 0)
		{
			if (a == 0)
				return 0;
			else
				return LARGE_VAL * sign(a);
		}
		else
		{
			if (a == 0)
				return 0;
			else
			{
				if ((a + b) == a)
					return LARGE_VAL * sign(a) * sign(b);
				else
					return a / b;
			}
		}
	}

	//signum function
	int sign(double x)
	{
		return (x == 0 ? 0 : (x < 0 ? -1 : 1));
	}

	int sign(float x)
	{
		return (x == 0 ? 0 : (x < 0 ? -1 : 1));
	}

	int sign(int x)
	{
		return (x == 0 ? 0 : (x < 0 ? -1 : 1));
	}

	// root of linear equation c1 * x + c0 = 0
	// if successful, returns ret.value[0] = x
	void linearRoot(retval & ret, double c1, double c0)
	{
		if (c1 == 0)
			ret.num_val = 0;
		else
		{
			ret.num_val = 1;
			*(ret.value) = safeDiv(-c0, c1);
		}
	}

	void linearRoot(retval & ret, float c1, float c0)
	{
		if (c1 == 0)
			ret.num_val = 0;
		else
		{
			ret.num_val = 1;
			*(ret.value) = safeDiv(-c0, c1);
		}
	}

	// distinct real roots x1, x2 of quadratic equation:
	//   c2 * x^2 + c1 * x + c0 = 0
	// if successful, returns ret.value[0] = x1 & ret.value[1] = x2
	// if roots are equal, ret.value[0] = root
	void quadRoot(retval & ret, double c2, double c1, double c0)
	{
		double divisor;

		if (c2 == 0)
		{
			linearRoot(ret, c1, c0);
		}
		else
		{
			divisor = (c1 * c1) - (4 * c2 * c0);

			if (divisor == 0)
			{
				ret.num_val = 1;
				*(ret.value) = safeDiv(-c1, 2 * c2);
			}
			else if (divisor > 0)
			{
				*(ret.value) = safeDiv(-c1 + divisor, 2 * c2);
				ret.value[1] = safeDiv(-c1 - divisor, 2 * c2);
			}
			else
			{
				ret.num_val = 0;
			}
		}
	}

	void quadRoot(retval & ret, float c2, float c1, float c0)
	{
		float divisor;

		if (c2 == 0)
		{
			linearRoot(ret, c1, c0);
		}
		else
		{
			divisor = (c1 * c1) - (4 * c2 * c0);

			if (divisor == 0)
			{
				ret.num_val = 1;
				*(ret.value) = safeDiv(-c1, 2 * c2);
			}
			else if (divisor > 0)
			{
				*(ret.value) = safeDiv(-c1 + divisor, 2 * c2);
				ret.value[1] = safeDiv(-c1 - divisor, 2 * c2);
			}
			else
			{
				ret.num_val = 0;
			}
		}
	}
};

#endif