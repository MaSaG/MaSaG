#include "kinematics.h"

#define SINGULARITY 0.49999

Transform kinematics::ForwardKinematics(Vectornf& q)
{
	int i;
	Transform T = transformDH(dhParams[0], q(1));
	for (i = 1; i < 6; i++)
		T = T * transformDH(dhParams[i], q(i+1));
	return T;
}

Transform kinematics::FK_MaSaG(Vectornf& q)
{
	Transform t;

	float s1 = sin(q(1));
	float s2 = sin(q(2));
	float s3 = sin(q(3));
	float s4 = sin(q(4));
	float s5 = sin(q(5));
	float s6 = sin(q(6));
	float c1 = cos(q(1));
	float c2 = cos(q(2));
	float c3 = cos(q(3));
	float c4 = cos(q(4));
	float c5 = cos(q(5));
	float c6 = cos(q(6));


	float c123 = c1*c2*c3;
	float s13 = s1*s3;
	float c13 = c1*c3;
	float c12s3 = c1*c2*s3;
	float c13s2 = c1*c3*s2;
	float c23s1 = c2*c3*s1;
	float c1s24 = c1*s2*s4;
	float c34s2 = c3*c4*s2;
	float c2s4 = c2*s4;
	float c24 = c2*c4;
	float c3s1 = c3*s1;
	float s124 = s1*s2*s4;
	float s235 = s2*s3*s5;
	float c3s24 = c3*s2*s4;
	float c1s3 = c1*s3;
	float s12 = s1*s2;
	float c14s2 = c1*c4*s2;


	t.matrix()(0, 0) = -c6*(c5*(c4*(s13 - c123) + c1s24) - s5*(c3s1 + c12s3)) - s6*(s4*(s13 - c123) - c14s2);
	t.matrix()(0, 1) = s6*(c5*(c4*(s13 - c123) + c1s24) - s5*(c3s1 + c12s3)) - c6*(s4*(s13 - c123) - c14s2);
	t.matrix()(0, 2) = -s5*(c4*(s13 - c123) + c1s24) - c5*(c3s1 + c12s3);
	t.matrix()(0, 3) = 0.3575f*c1*s2 - 0.14f*c6*(c5*(c4*(s13 - c123) + c1s24) - s5*(c3s1 + c12s3)) - 0.015f*s13 + 0.015f*c4*(s13 - c123) - 0.2855f*s4*(s13 - c123) - 0.14f*s6*(s4*(s13 - c123) - c14s2) + 0.015f*c1s24 + 0.015f*c123 + 0.2855f*c14s2;

	t.matrix()(1, 0) = s6*(s4*(c1s3 + c23s1) + c4*s12) + c6*(c5*(c4*(c1s3 + c23s1) - s124) - s5*(c13 - c2*s13));
	t.matrix()(1, 1) = c6*(s4*(c1s3 + c23s1) + c4*s12) - s6*(c5*(c4*(c1s3 + c23s1) - s124) - s5*(c13 - c2*s13));
	t.matrix()(1, 2) = s5*(c4*(c1s3 + c23s1) - s124) + c5*(c13 - c2*s13);
	t.matrix()(1, 3) = 0.015f*c1s3 + 0.3575f*s12 + 0.14f*s6*(s4*(c1s3 + c23s1) + c4*s12) - 0.015f*c4*(c1s3 + c23s1) + 0.2855f*s4*(c1s3 + c23s1) + 0.14f*c6*(c5*(c4*(c1s3 + c23s1) - s124) - s5*(c13 - c2*s13)) + 0.2855f*c4*s12 + 0.015f*s124 + 0.015f*c23s1;

	t.matrix()(2, 0) = c6*(c5*(c2s4 + c34s2) + s235) - s6*(c24 - c3s24);
	t.matrix()(2, 1) = -s6*(c5*(c2s4 + c34s2) + s235) - c6*(c24 - c3s24);
	t.matrix()(2, 2) = s5*(c2s4 + c34s2) - c5*s2*s3;
	t.matrix()(2, 3) = 0.015f*c3*s2 - 0.2855f*c24 - 0.3575f*c2 - 0.015f*c2s4 + 0.14f*c6*(c5*(c2s4 + c34s2) + s235) - 0.14f*s6*(c24 - c3s24) + 0.2855f*c3s24 - 0.015f*c34s2;

	return t;
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

Transform kinematics::transformDH(DH_Params dh, float th)
{
	Transform T;
	float al = dh.al;

	T.matrix().block(0, 0, 3, 4) << cos(th), -cos(al)*sin(th), sin(al)*sin(th), dh.a*cos(th),
		sin(th), cos(al)*cos(th), -sin(al)*cos(th), dh.a*sin(th),
		0, sin(al), cos(al), dh.d;
	return T;
}

Vector6f kinematics::Transform2Vector6f(Transform& t)
{
	Vector6f vec6;
	Eigen::Vector3f vec3;

	//// according to eulerAngles() in Eigen, the domain is located in [0:pi]x[-pi:pi]x[-pi:pi]
	//// convention: roll-pitch-yaw angles 
	//// limitation: range of yaw is located in [0:pi]
	//vec3 = t.rotation().eulerAngles(1, 2, 0);
	//t.rotation();
	//t.rotation().eulerAngles(1,2,0);

	vec6(0) = t.matrix()(0, 3);
	vec6(1) = t(1, 3);
	vec6(2) = t(2, 3);

	Eigen::Matrix3f m = t.matrix().block(0, 0, 3, 3);

	Eigen::Quaternionf qu(m);
	Eigen::Vector3f vec;

	quaternion2euler(qu, vec);

	vec6(3) = vec(0);
	vec6(4) = vec(1);
	vec6(5) = vec(2);

	return vec6;
}

void kinematics::quaternion2euler(Eigen::Quaternionf& qu, Eigen::Vector3f& vec)
{
	qu.normalize();
	float qw = qu.w();
	float qx = qu.x();
	float qy = qu.y();
	float qz = qu.z();

	float roll, yaw, pitch;
	double test = qx*qy + qz*qw;
	if (test > SINGULARITY)
	{ // singularity at north pole
		roll = 2 * atan2(qx, qw);
		yaw = M_PI / 2;
		pitch = 0;
		vec << roll, yaw, pitch;
		return;
	}
	if (test < -SINGULARITY)
	{ // singularity at south pole
		roll = -2 * atan2(qx, qw);
		yaw = -M_PI / 2;
		pitch = 0;
		vec << roll, yaw, pitch;
		return;
	}

	roll = atan2(2 * qy*qw - 2 * qx*qz, 1 - 2 * qy*qy - 2 * qz*qz);
	yaw = asin(2 * qx*qy + 2 * qz*qw);
	pitch = atan2(2 * qx*qw - 2 * qy*qz, 1 - 2 * qx*qx - 2 * qz*qz);

	vec << roll, yaw, pitch;
}