#pragma once

#include "CubicInt.h"
#include "kinematics.h"
#include "USER_Data.h"

class Manipulator;

enum {Planner_Idle, Cubic_TCP_Timer, Cubic_Joint_Timer, OTG_TCP_Timer, OTG_Joint_Timer};

class Motion
{
public:
	Motion();
	void MOV_TCP(Manipulator* arm, Transform& movT, float t);		// cubic interpolation
	void MOV_TCP(Manipulator* arm, Transform& movT);				// OTG approach
	void MOV_TCP_RAPID(Manipulator* arm, Transform& movT);			// without motion planner
	void MOV_JOINT(Manipulator* arm, float q, int n, float t);		// cubic interpolation 1
	void MOV_JOINT(Manipulator* arm, Vectornf vec_q, float t);		// cubic interpolation 2
	void MOV_JOINT(Manipulator* arm, float q, int n);				// OTG approach 1
	void MOV_JOINT(Manipulator* arm, Vectornf vec_q);				// OTG approach 2
	void MOV_JOINT_RAPID(Manipulator* arm, float q, int n);			// without motion planner 1
	void MOV_JOINT_RAPID(Manipulator* arm, Vectornf vec_q);			// without motion planner 2
	void FREE_MODE(Manipulator* arm);								// gravity compesation only


	void otgTCP_timer(Manipulator* arm);
	void cubicTCP_timer(Manipulator* arm);
	void otgJoint_timer(Manipulator* arm);
	void cubicJoint_timer(Manipulator* arm);

	// parameters of cubic interpolation
	CubicInt jointParam[ARM_DOF];		// joint
	CubicInt tcpParam[6];				// tcp

	Vectornf amaxTCP;
	Vectornf vmaxTCP;
	Vectornf amaxJoint;
	Vectornf vmaxJoint;

private:
	void tcpCubic(Manipulator* arm, Vector6f xf, float t);
	void jointCubic(Manipulator* arm, Vectornf thf, float t);

	void  initParams();
	float minVel(float v1, float v2, float v3, float v4);
};

