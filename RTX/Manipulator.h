#ifndef _MANIPULATOR_H
#define _MANIPULATOR_H

#include "SystemParams.h"
#include "MotorData.h"
#include "Joint.h"
#include "kinematics.h"
#include "dynamics.h"
#include "Control.h"
#include "MaSaGTech.h"

class Manipulator
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	Joint*			joint[ARM_DOF];
	kinematics		kin;
	dynamics		dyn;
	Control			ctrl;
	MaSaGTech*		mtn;

	// current TCP
	Transform		curTCP_T;
	Vector6f		curTCP;
	// target TCP
	Transform		tarTCP_T;
	Vector6f		tarTCP;
	// planned TCP 
	Vector6f		plnTCP;
	// TCP position error: [x y z a b c]
	Vector6f		errTCP;
	// tcp velocity
	Vector6f		velTCP;

	// current joint position
	Vectornf		curJoint;
	// target joint position
	Vectornf		tarJoint;
	// joint position error
	Vectornf		errJoint;
	// q0 indicates the planned joint angle
	Vectornf		plnJoint;
	// q1, q2 are used to save the last data, where time sequence: k-2, k-1, k  is represented as q2, q1, curJoint
	Vectornf		q1, q2;;
	// encoder count
	Vectorni		cntJoint;
	// joint velocity
	Vectornf		velJoint;
	// torque output
	Vectornf		tarTorque;
	// actual torque output
	Vectornf		actTorque;


	// impedance force
	Vector6f		Fext;
	// Jacobain
	Matrix6nf		Jacobian;

	// Roation matrix in Object Coordinate
	Eigen::Matrix3f objR;

	// Joint and Cartesian Motion
	int	 planner_mode;	 // motion planner mode
	int	 control_mode;   // control mode

	int	 is_busy;
	int  timer_cnt;
	int  static_cnt;

	void encoderFB();
	void torqueFB();
	void torqueCMD();
	void update();
	void updatePastData();

	Manipulator(RTX_ARM_DATA* _rtxArm);
	~Manipulator();
	
	int  cntOffset[ARM_DOF];
private:

};


#endif