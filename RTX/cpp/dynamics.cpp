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

	// Algorithm for Gravity Compensation
	gravityTorque(0) = 0;
	gravityTorque(1) = Mg2*(0.357*c1*s2 - 0.015*s3*s1 + 0.015*c4*(s3*s1 - c3*c1*c2) + 0.015*c3*c1*c2 + 0.015*s4*c1*s2 + L2*(-s4*(s3*s1 - c3*c1*c2) + c4*c1*s2)) + L1*Mg1*c1*s2;
	gravityTorque(2) = Mg2*(0.015*s4*c2*s1 + 0.357*c2*s1 - L2*(s4*c3*s1*s2 - c4*c2*s1) - 0.015*c3*s1*s2 + 0.015*c4*(c3*s1*s2)) + L1*Mg1*c2*s1;
	gravityTorque(3) = Mg2*(-0.015*s3*c2*s1 + 0.015*c4*(s3*c2*s1 - c3*c1) + L2*(-s4*(s3*c2*s1 - c3*c1)) + 0.015*c3*c1);
	gravityTorque(4) = Mg2*(L2*(c4*(c3*c2*s1 + s3*c1) - s4*s1*s2) + 0.015*s4*(c3*c2*s1 + s3*c1) + 0.015*c4*s1*s2);
	gravityTorque(5) = 0;
	gravityTorque(6) = 0;

}

