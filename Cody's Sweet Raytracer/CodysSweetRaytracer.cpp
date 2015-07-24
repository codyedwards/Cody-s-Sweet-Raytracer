#include <stdio.h>
#include <iostream>

#include "MathLib.h"
#include "vector2.h"

using namespace std;

MathLib ml;

int main(int argc, const char* argv[])
{
	vector2f v1 = vector2f(1.0f, 3.4f);
	vector2f v2 = v1;
	v2 += v2;
	cout << "(" << v1[0] << ", " << v1[1] << ")";
	cout << "(" << v2[0] << ", " << v2[1] << ")";
	getchar();
	return 0;
}