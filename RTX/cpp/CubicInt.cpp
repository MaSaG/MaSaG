#include "CubicInt.h"

void CubicInt::cal(float x0, float xf, float t)
{
	a0 = x0;
	a1 = 0;
	a2 = 3 / t / t*(xf - x0);
	a3 = -2 / t / t / t*(xf - x0);
}

float CubicInt::x(float t)
{
	return a3*t*t*t + a2*t*t + a1*t + a0;
}

float CubicInt::v(float t)
{
	return 3*a3*t*t + 2*a2*t + a1;
}

float CubicInt::a(float t)
{
	return 6*a3*t + 2*a2;
}

