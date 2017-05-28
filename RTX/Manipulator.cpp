#include "Manipulator.h"

Manipulator::Manipulator(RTX_ARM_DATA* _rtxArm)
{
	joint[0] = new Joint(_rtxArm->mAxis[0],  gearRatio_ARM[0], resEncoder_ARM[0], mDATA[0].rated_torque, TYPE_MAXPOS);
	joint[1] = new Joint(_rtxArm->mAxis[1],  gearRatio_ARM[1], resEncoder_ARM[1], mDATA[1].rated_torque, TYPE_EPOS3);
	joint[2] = new Joint(_rtxArm->mAxis[2],  gearRatio_ARM[2], resEncoder_ARM[2], mDATA[2].rated_torque, TYPE_MAXPOS);
	joint[3] = new Joint(_rtxArm->mAxis[3],  gearRatio_ARM[3], resEncoder_ARM[3], mDATA[3].rated_torque, TYPE_MAXPOS);
	joint[4] = new Joint(_rtxArm->mAxis[4],  gearRatio_ARM[4], resEncoder_ARM[4], mDATA[4].rated_torque, TYPE_MAXPOS);
	joint[5] = new Joint(_rtxArm->mAxis[5],  gearRatio_ARM[5], resEncoder_ARM[5], mDATA[5].rated_torque, TYPE_mcDSA_E65);
	joint[6] = new Joint(_rtxArm->mAxis[6],  gearRatio_ARM[6], resEncoder_ARM[6], mDATA[6].rated_torque, TYPE_mcDSA_E65);

	mtn = new MaSaGTech;

	cntOffset[0] = 0;
	cntOffset[1] = -50000;
	cntOffset[2] = -204800;
	cntOffset[3] = 0;
	cntOffset[4] = 0;
	cntOffset[5] = 0;
	cntOffset[6] = 201497;
	
	curTCP_T.matrix().block(0, 0, 3, 3) << 0, 0, 1, -1, 0, 0, 0, -1, 0;
	curTCP_T.matrix()(0, 3) = 0;
	curTCP_T.matrix()(1, 3) = -0.7830;
	curTCP_T.matrix()(2, 3) = 0;

	curTCP = kin.Transform2Vector6f(curTCP_T);
	
	tarTCP_T = curTCP_T;
	tarTCP = curTCP;
	plnTCP = curTCP;
	errTCP.setZero();
	velTCP.setZero();

	curJoint.setZero();
	curJoint[1] = -M_PI/2;
	curJoint[2] = M_PI/2;
	curJoint[6] = M_PI/2;
	tarJoint = curJoint;
	plnJoint = curJoint;
	errJoint.setZero();
	velJoint.setZero();
	tarTorque.setZero();

	is_busy = false;
	control_mode = Free_Mode;
	planner_mode = Planner_Idle;
	timer_cnt = 0;
	static_cnt = 0;

}

void Manipulator::encoderFB()
{
	int i;
	for (i = 0; i < ARM_DOF; i++)
	{
		joint[i]->updateJoint(cntOffset[i]);
		cntJoint(i) = joint[i]->driver->_countEncoder;
		curJoint(i) = joint[i]->_angle;
	}
}

void Manipulator::torqueFB()
{
	int i;
	for (i = 0; i < ARM_DOF; i++)
	{
		joint[i]->driver->readTorque(actTorque[i]);
		actTorque[i] *= joint[i]->_gearRatio;
	}
}

void Manipulator::torqueCMD()
{
	int i;
	float _gearRatio;
	for (i = 1; i < ARM_DOF; i++)
	{
		_gearRatio = joint[i]->_gearRatio;
		joint[i]->driver->cmdTorque(tarTorque(i) / _gearRatio);
	}
}

void Manipulator::update()
{
	// current TCP Transoformation matrix
	curTCP_T = kin.FK_MaSaG(curJoint);
	curTCP = kin.Transform2Vector6f(curTCP_T);
	// Jacobian
	kin.updateJacobian(curJoint, Jacobian);
	// TCP velocity
	velTCP = Jacobian*curJoint;
	// TCP error, TCP is defined as [x y z a b c]
	errTCP = tarTCP - curTCP;

	// joint error
	errJoint = tarJoint - curJoint;
	// joint angular velocity
	velJoint = (curJoint - q1) / (float) SERVOLOOP_TIME;
}

void Manipulator::updatePastData()
{
	// k, k-1, k-2 update
	q2 = q1;
	q1 = curJoint;
}

Manipulator::~Manipulator()
{
	int i;
	for (i = 0; i < ARM_DOF; i++)
		delete joint[i];
	delete mtn;
}