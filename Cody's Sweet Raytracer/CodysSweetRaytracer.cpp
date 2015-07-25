#include <stdio.h>
#include <iostream>

#include "MathLib.h"
#include "vector2.h"
#include "vector3.h"
#include "ray.h"

using namespace std;

MathLib ml;

int main(int argc, const char* argv[])
{
	vector3d v1 = vector3d(1.0, 3.4, 4.0);
	vector3d v2 = v1;
	v2 += v2;
	ray r = ray(v1, v2);
	vector3d l = r.line(22.0);
	cout << "(" << v1[0] << ", " << v1[1] << ")";
	cout << "(" << v2[0] << ", " << v2[1] << ")";
	return 0;
}