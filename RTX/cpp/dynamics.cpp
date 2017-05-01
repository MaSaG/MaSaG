#include "dynamics.h"
#include <cmath>

void dynamics::GravityComp(Vectornf& q, Vectornf& gravityTorque)
{
	float s1 = sin(q(1));
	float c1 = cos(q(1));
	float s2 = sin(q(2));
	float c2 = cos(q(2));
	float s3 = sin(q(3));
	float c3 = cos(q(3));
	float s4 = sin(q(4));
	float c4 = cos(q(4));
	float s5 = sin(q(5));
	float c5 = cos(q(5));
	float s6 = sin(q(6));
	float c6 = cos(q(6));

	float r1 = L1 / 5.0;
	float r2 = L2 / 3.0;

	float m1, m2, m3, m4, m5, m6;

	// Algorithm for Gravity Compensation
	gravityTorque(0) = 0;
	gravityTorque(1) = 0.0735f*c3*m3*s1*s2 - 3.5f*c2*m4*s1 - 3.5f*c2*m5*s1 - 3.5f*c2*m6*s1 - 1.4f*c2*c4*m5*s1 - 
		2.8f*c2*c4*m6*s1 - 1.75f*c2*m3*s1 + 0.147f*c3*m4*s1*s2 - 0.0735f*c2*m4*s1*s4 + 0.147f*c3*m5*s1*s2 - 
		0.147f*c2*m5*s1*s4 + 0.147f*c3*m6*s1*s2 - 0.147f*c2*m6*s1*s4 - 0.0735f*c3*c4*m4*s1*s2 - 0.147f*c3*c4*m5*s1*s2 - 
		0.147f*c3*c4*m6*s1*s2 - 0.686f*c2*c4*m6*s1*s6 + 1.4f*c3*m5*s1*s2*s4 + 2.8f*c3*m6*s1*s2*s4 + 
		0.686f*c2*c5*c6*m6*s1*s4 + 0.686f*c3*m6*s1*s2*s4*s6 + 0.686f*c6*m6*s1*s2*s3*s5 + 0.686f*c3*c4*c5*c6*m6*s1*s2;
	gravityTorque(2) = 0.0735f*c2*m3*s1*s3 - 0.147f*c1*c3*m4 - 0.147f*c1*c3*m5 - 0.147f*c1*c3*m6 - 1.4f*c1*c3*m5*s4 - 
		2.8f*c1*c3*m6*s4 - 0.0735f*c1*c3*m3 + 0.147f*c2*m4*s1*s3 + 0.147f*c2*m5*s1*s3 + 0.147f*c2*m6*s1*s3 + 
		0.0735f*c1*c3*c4*m4 + 0.147f*c1*c3*c4*m5 + 0.147f*c1*c3*c4*m6 - 0.0735f*c2*c4*m4*s1*s3 - 0.147f*c2*c4*m5*s1*s3 - 
		0.147f*c2*c4*m6*s1*s3 - 0.686f*c1*c3*m6*s4*s6 - 0.686f*c1*c6*m6*s3*s5 + 1.4f*c2*m5*s1*s3*s4 + 2.8f*c2*m6*s1*s3*s4 - 
		0.686f*c1*c3*c4*c5*c6*m6 - 0.686f*c2*c3*c6*m6*s1*s5 + 0.686f*c2*m6*s1*s3*s4*s6 + 0.686f*c2*c4*c5*c6*m6*s1*s3;
	gravityTorque(3) = 1.75f*c1*m3*s3 - 0.0735f*m3*s1*s2 + 1.75f*c2*c3*m3*s1 - 1.4f*c1*c4*m5*s3 - 2.8f*c1*c4*m6*s3 - 
		0.0735f*c4*m4*s1*s2 - 0.0735f*c1*m4*s3*s4 - 0.147f*c4*m5*s1*s2 - 0.147f*c1*m5*s3*s4 - 0.147f*c4*m6*s1*s2 - 
		0.147f*c1*m6*s3*s4 + 1.4f*m5*s1*s2*s4 + 2.8f*m6*s1*s2*s4 - 1.4f*c2*c3*c4*m5*s1 - 2.8f*c2*c3*c4*m6*s1 - 
		0.0735f*c2*c3*m4*s1*s4 - 0.147f*c2*c3*m5*s1*s4 - 0.147f*c2*c3*m6*s1*s4 - 0.686f*c1*c4*m6*s3*s6 + 0.686f*m6*s1*s2*s4*s6 - 
		0.686f*c2*c3*c4*m6*s1*s6 + 0.686f*c4*c5*c6*m6*s1*s2 + 0.686f*c1*c5*c6*m6*s3*s4 + 0.686f*c2*c3*c5*c6*m6*s1*s4;
	gravityTorque(4) = 0.0735f*c1*c3*m4 - 0.0735f*c2*m4*s1*s3 + 0.686f*c1*c3*c5*c6*m6 - 0.686f*c2*c5*c6*m6*s1*s3 + 
		0.686f*c1*c4*c6*m6*s3*s5 - 0.686f*c6*m6*s1*s2*s4*s5 + 0.686f*c2*c3*c4*c6*m6*s1*s5;
	gravityTorque(5) = 1.4f*c1*c3*m5*s5 - 1.4f*c1*c4*c5*m5*s3 - 0.686f*c4*c6*m6*s1*s2 - 0.686f*c1*c6*m6*s3*s4 - 
		0.686f*c1*c3*m6*s5*s6 - 1.4f*c2*m5*s1*s3*s5 + 1.4f*c5*m5*s1*s2*s4 - 1.4f*c2*c3*c4*c5*m5*s1 - 0.686f*c2*c3*c6*m6*s1*s4 + 
		0.686f*c1*c4*c5*m6*s3*s6 + 0.686f*c2*m6*s1*s3*s5*s6 - 0.686f*c5*m6*s1*s2*s4*s6 + 0.686f*c2*c3*c4*c5*m6*s1*s6;
	gravityTorque(6) = 0.686f*c4*c6*m6*s1*s2 + 0.686f*c1*c6*m6*s3*s4 + 0.686f*c1*c3*m6*s5*s6 + 0.686f*c2*c3*c6*m6*s1*s4 - 
		0.686f*c1*c4*c5*m6*s3*s6 - 0.686f*c2*m6*s1*s3*s5*s6 + 0.686f*c5*m6*s1*s2*s4*s6 - 0.686f*c2*c3*c4*c5*m6*s1*s6;

}

