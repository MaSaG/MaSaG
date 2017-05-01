#include "kinematics.h"


Transform kinematics::ForwardKinematics(Vectornf& q)
{
	int i;
	Transform T = transformDH(dhParams[0]);
	for (i = 1; i < 6; i++)
		T = transformDH(dhParams[i])*T;
	return T;
}

void kinematics::updateJacobian(Vectornf& q, Matrix6nf& J)
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

	J(0, 0) = 0;
	J(0, 1) = -0.3575f*s1*s2 - 0.14f*(s6*(s4*(c1*s3 + c2*c3*s1) + c4*s1*s2) + c6*(c5*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) - s5*(c1*c3 - c2*s1*s3))) - 0.2855f* (s4*(c1*s3 + c2*c3*s1) + c4*s1*s2) + 0.015f*(c4*(c1*s3 + c2*c3*s1) - c1*s3 - s1*s2*s4 - c2*c3*s1);
	J(0, 2) = -c1*(0.015f*(c3*s2 - c2*s4 - c3*c4*s2) - 0.3575f*c2 - 0.2855f*(c2*c4 - c3*s2*s4) + 0.14f*(-c2*c4*s6 + c2*c5*c6*s4 + c3*s2*s4*s6 + c6*s2*s3*s5 + c3*c4*c5*c6*s2));
	J(0, 3) = 0.015f* (c4*(c3*s1 + c1*c2*s3) - c3*s1 - c1*c2*s3) - 0.2855f*s4*(c3*s1 + c1*c2*s3) - 0.14f*(c6*(s5*(s1*s3 - c1*c2*c3) + c4*c5*(c3*s1 + c1*c2*s3)) + s4*s6*(c3*s1 + c1*c2*s3));
	J(0, 4) = 0.14f*(c5*c6*(s4*(s1*s3 - c1*c2*c3) - c1*c4*s2) - s6*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4)) - 0.2855f*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4) + 0.015f*(c1*c4*s2 - s4*(s1*s3 - c1*c2*c3));
	J(0, 5) = 0.14f * c6*(s5*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4) + c5*(c3*s1 + c1*c2*s3));
	J(0, 6) = 0.14f*(s6*(c5*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4) - s5*(c3*s1 + c1*c2*s3)) - c6*(s4*(s1*s3 - c1*c2*c3) - c1*c4*s2));
	J(1, 0) = 0;
	J(1, 1) = 0.3575f*c1*s2 - 0.14f*(s6*(s4*(s1*s3 - c1*c2*c3) - c1*c4*s2) + c6*(c5*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4) - s5*(c3*s1 + c1*c2*s3))) + 0.2855f*(c1*c4*s2 - s4*(s1*s3 - c1*c2*c3)) + 0.015f*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4 + c1*c2*c3 - s1*s3);
	J(1, 2) = -s1 * (0.015f* (c3*s2 - c2*s4 - c3*c4*s2) + 0.2855f*(c3*s2*s4 - c2*c4) - 0.3575f*c2 + 0.14f*(c2*c5*c6*s4 - c2*c4*s6 + c3*s2*s4*s6 + c6*s2*s3*s5 + c3*c4*c5*c6*s2));
	J(1, 3) = 0.015f*(c1*c3 - c2*s1*s3 - c4*(c1*c3 - c2*s1*s3)) + 0.2855f*s4*(c1*c3 - c2*s1*s3) + 0.14f*(c6*(s5*(c1*s3 + c2*c3*s1) + c4*c5*(c1*c3 - c2*s1*s3)) + s4*s6*(c1*c3 - c2*s1*s3));
	J(1, 4) = 0.14f* (s6*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) - c5*c6*(s4*(c1*s3 + c2*c3*s1) + c4*s1*s2)) + 0.2855f*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) + 0.015f*(s4*(c1*s3 + c2*c3*s1) + c4*s1*s2);
	J(1, 5) = -0.14f*c6*(s5*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) + c5*(c1*c3 - c2*s1*s3));
	J(1, 6) = 0.14f*(c6*(s4*(c1*s3 + c2*c3*s1) + c4*s1*s2) - s6*(c5*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) - s5*(c1*c3 - c2*s1*s3)));
	J(2, 0) = 0;
	J(2, 1) = 0;
	J(2, 2) = 0.3575f*s2 + 0.2855f*(c4*s2 + c2*c3*s4) + 0.015f*(s2*s4 - c2*c3*c4 + c2*c3) - 0.14f*(c6*(c5*(s2*s4 - c2*c3*c4) - c2*s3*s5) - s6*(c4*s2 + c2*c3*s4));
	J(2, 3) = -s2*(0.015f*(s3 - c4*s3) + 0.2855f*s3*s4 + 0.14f*(s3*s4*s6 - c3*c6*s5 + c4*c5*c6*s3));
	J(2, 4) = 0.2855f* (c2*s4 + c3*c4*s2) + 0.015f*(c3*s2*s4 - c2*c4) + 0.14f* (s6*(c2*s4 + c3*c4*s2) + c5*c6*(c2*c4 - c3*s2*s4));
	J(2, 5) = -0.14f*c6*(s5*(c2*s4 + c3*c4*s2) - c5*s2*s3);
	J(2, 6) = -0.14f*(s6*(c5*(c2*s4 + c3*c4*s2) + s2*s3*s5) + c6*(c2*c4 - c3*s2*s4));
	J(3, 0) = 0;
	J(3, 1) = 0;
	J(3, 2) = s1;
	J(3, 3) = -c1*s2;
	J(3, 4) = c3*s1 + c1*c2*s3;
	J(3, 5) = c1*c4*s2 - s4*(s1*s3 - c1*c2*c3);
	J(3, 6) = -s5*(c4*(s1*s3 - c1*c2*c3) + c1*s2*s4) - c5*(c3*s1 + c1*c2*s3);
	J(4, 0) = 0;
	J(4, 1) = 0;
	J(4, 2) = -c1;
	J(4, 3) = -s1*s2;
	J(4, 4) = c2*s1*s3 - c1*c3;
	J(4, 5) = s4*(c1*s3 + c2*c3*s1) + c4*s1*s2;
	J(4, 6) = s5*(c4*(c1*s3 + c2*c3*s1) - s1*s2*s4) + c5*(c1*c3 - c2*s1*s3);
	J(5, 0) = 0;
	J(5, 1) = 1.f;
	J(5, 2) = 0;
	J(5, 3) = c2;
	J(5, 4) = s2*s3;
	J(5, 5) = c3*s2*s4 - c2*c4;
	J(5, 6) = s5*(c2*s4 + c3*c4*s2) - c5*s2*s3;
} 

void kinematics::InversKinematics()
{


}

Transform kinematics::transformDH(DH_Params dh)
{
	Transform T;
	float th = dh.th / M_PI * 180.0f;
	float al = dh.al / M_PI * 180.0f;
	
	T.matrix().block(0, 0, 3, 4) << cos(th), -cos(al)*sin(th), sin(al)*sin(th), dh.a*cos(th),
									sin(th), cos(al)*cos(th), -sin(al)*cos(th), dh.a*sin(th),
									0, sin(al), cos(al), dh.d;
	return T;
}

Vector6f kinematics::Transform2Vector6f(Transform& t)
{
	
	Vector6f vec;
	
	vec(0) = t(3, 0);
	vec(1) = t(3, 1);
	vec(2) = t(3, 2);
	
	// according to eulerAngles() in Eigen, the domain is located in [0:pi]x[-pi:pi]x[-pi:pi]
	// vec.segment(3, 3) = t.rotation().eulerAngles(2, 1, 0).reverse();
	
	return vec;
}