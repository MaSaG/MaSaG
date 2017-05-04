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

	curTCP_T.matrix().setZero();
	curTCP.setZero();
	tarTCP_T = curTCP_T;
	tarTCP = curTCP;
	plnTCP = curTCP;
	errTCP.setZero();
	velTCP.setZero();

	curJoint.setZero();
	tarJoint = curJoint;
	plnJoint = curJoint;
	errJoint.setZero();
	velJoint.setZero();

}

void Manipulator::encoderFB()
{
	int i;
	for (i = 0; i < ARM_DOF-2; i++)
	{
		joint[i]->updateJoint();
		cntJoint(i) = joint[i]->driver->_countEncoder;
		curJoint(i) = joint[i]->_angle;
	}
}

void Manipulator::torqueCMD()
{
	int i;
	for (i = 1; i < ARM_DOF; i++)
		joint[i]->driver->cmdTorque(torque(i));
}

void Manipulator::update()
{
	// current TCP Transoformation matrix
	curTCP_T = kin.ForwardKinematics(curJoint);
	curTCP = kin.Transform2Vector6f(curTCP_T);
	// Jacobian
	kin.updateJacobian(curJoint, Jacobian);
	// TCP velocity
	velTCP = Jacobian*curJoint;
	// TCP error, TCP is defined as [x y z a b c]
	errTCP = tarTCP - curTCP;

	// k, k-1, k-2 update
	q1 = curJoint;		
	q2 = q1;
	// joint error
	errJoint = tarJoint - curJoint;
	// joint angular velocity
	velJoint = (curJoint - q1) / (float) SERVOLOOP_TIME;
}

Manipulator::~Manipulator()
{
	int i;
	for (i = 0; i < ARM_DOF; i++)
		delete joint[i];
	delete mtn;
}