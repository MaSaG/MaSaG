#pragma once

class CubicInt
{
public:
	void cal(float x0, float xf, float t);
	float a0, a1, a2, a3;
	float x(float t);
	float v(float t);
	float a(float t);
};
