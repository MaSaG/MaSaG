#include "MaSaGRobot.h"

#define RAD2DEG  (180/M_PI)

MaSaGRobot::MaSaGRobot()
{
	LArm = new Manipulator(&_RTX.pData->_rtxLArm);
	RArm = new Manipulator(&_RTX.pData->_rtxRArm);
	LArm->cntOffset[2] *= -1;								// special defined 
	RArm->cntOffset[6] *= -1;								// special defined 
	RArm->joint[0]->driver->_resEncoder = 4096;				// special defined since we use RE40 motors with different specifications
	
	int i;
	float limit_ratio = 1;
	for (i = 0; i < ARM_DOF; i++)
	{
		LArm->joint[i]->driver->_ratedTorque *= limit_ratio;
		RArm->joint[i]->driver->_ratedTorque *= limit_ratio;
	}
}

int MaSaGRobot::initRobot()
{
	int ret;
	ret = _RTX.Init();
	// appoint the addresses of slave devices
	for (int i = 0; i < ARM_DOF; i++)
	{
		LArm->joint[i]->driver->_nodeID = _RTX.pData->_rtxLArm.mAxis[i];
		RArm->joint[i]->driver->_nodeID = _RTX.pData->_rtxRArm.mAxis[i];
	}
	return ret;
}

void MaSaGRobot::updateFeedback()
{
	LArm->encoderFB();
	RArm->encoderFB();

	LArm->torqueFB();
	RArm->torqueFB();

	LArm->curJoint[3] *= -1;
	LArm->curJoint[4] *= -1;
	RArm->curJoint[2] *= -1;
	RArm->curJoint[3] *= -1;
	RArm->curJoint[6] *= -1;

	LArm->actTorque[3] *= -1;
	LArm->actTorque[4] *= -1;
	RArm->actTorque[2] *= -1;
	RArm->actTorque[3] *= -1;
	RArm->actTorque[6] *= -1;

}

void MaSaGRobot::updateState()
{
	LArm->update();
	RArm->update();
}

void MaSaGRobot::updateSharedMemory()
{
	int i;

	// joint data 
	for (i = 0; i < ARM_DOF; i++)
	{
		_RTX.pData->_rtxLArm.curPos[i] = LArm->curJoint(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.curPos[i] = RArm->curJoint(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.tarPos[i] = LArm->tarJoint(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.tarPos[i] = RArm->tarJoint(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.errPos[i] = LArm->errJoint(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.errPos[i] = RArm->errJoint(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.plnPos[i] = LArm->plnJoint(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.plnPos[i] = RArm->plnJoint(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.curVel[i] = LArm->velJoint(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.curVel[i] = RArm->velJoint(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.tarTorque[i] = LArm->tarTorque(i);
		_RTX.pData->_rtxRArm.tarTorque[i] = RArm->tarTorque(i);
		_RTX.pData->_rtxLArm.actTorque[i] = LArm->actTorque(i);
		_RTX.pData->_rtxRArm.actTorque[i] = RArm->actTorque(i);
	}

	// tcp data
	for (i = 0; i < 3; i++)
	{
		_RTX.pData->_rtxLArm.curTCP[i] = LArm->curTCP(i);
		_RTX.pData->_rtxRArm.curTCP[i] = RArm->curTCP(i);
		_RTX.pData->_rtxLArm.tarTCP[i] = LArm->tarTCP(i);
		_RTX.pData->_rtxRArm.tarTCP[i] = RArm->tarTCP(i);
		_RTX.pData->_rtxLArm.errTCP[i] = LArm->errTCP(i);
		_RTX.pData->_rtxRArm.errTCP[i] = RArm->errTCP(i);
		_RTX.pData->_rtxLArm.plnTCP[i] = LArm->plnTCP(i);
		_RTX.pData->_rtxRArm.plnTCP[i] = RArm->plnTCP(i);
		_RTX.pData->_rtxLArm.velTCP[i] = LArm->velTCP(i);
		_RTX.pData->_rtxRArm.velTCP[i] = RArm->velTCP(i);
	}

	// angle unit: degree
	for (i = 3; i < 6; i++)
	{
		_RTX.pData->_rtxLArm.curTCP[i] = LArm->curTCP(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.curTCP[i] = RArm->curTCP(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.tarTCP[i] = LArm->tarTCP(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.tarTCP[i] = RArm->tarTCP(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.errTCP[i] = LArm->errTCP(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.errTCP[i] = RArm->errTCP(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.plnTCP[i] = LArm->plnTCP(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.plnTCP[i] = RArm->plnTCP(i)*RAD2DEG;
		_RTX.pData->_rtxLArm.velTCP[i] = LArm->velTCP(i)*RAD2DEG;
		_RTX.pData->_rtxRArm.velTCP[i] = RArm->velTCP(i)*RAD2DEG;
	}

	_RTX.pData->_rtxLArm.cntTimer = LArm->timer_cnt;
	_RTX.pData->_rtxRArm.cntTimer = RArm->timer_cnt;
}

void MaSaGRobot::MotionTrajGen()
{
	// Left Arm
	if (LArm->is_busy)
	{
		switch (LArm->planner_mode)
		{
		case Cubic_TCP_Timer:
			LArm->mtn->cubicTCP_timer(LArm);
			break;
		case Cubic_Joint_Timer:
			LArm->mtn->cubicJoint_timer(LArm);
			break;
		case OTG_TCP_Timer:
			LArm->mtn->otgTCP_timer(LArm);
			break;
		case OTG_Joint_Timer:
			LArm->mtn->otgJoint_timer(LArm);
			break;
		case Mimmic:
			LArm->mtn->Mimmic_timer(LArm, RArm);
			break;
		case Mirror:
			LArm->mtn->Mirror_timer(LArm, RArm);
			break;
		case Teach_Mode:
			LArm->mtn->Teach_timer(LArm);
			break;
		case Play_Mode:
			LArm->mtn->Play_timer(LArm);
			break;
		}
	}
	
	// Right Arm
	if(RArm->is_busy)
	{
		switch (RArm->planner_mode)
		{
		case Cubic_TCP_Timer:
			RArm->mtn->cubicTCP_timer(RArm);
			break;
		case Cubic_Joint_Timer:
			RArm->mtn->cubicJoint_timer(RArm);
			break;
		case OTG_TCP_Timer:
			RArm->mtn->otgTCP_timer(RArm);
			break;
		case OTG_Joint_Timer:
			RArm->mtn->otgJoint_timer(RArm);
			break;
		case Mimmic:
			RArm->mtn->Mimmic_timer(RArm, LArm);
			break;
		case Mirror:
			RArm->mtn->Mirror_timer(RArm, LArm);
			break;
		case Teach_Mode:
			RArm->mtn->Teach_timer(RArm);
			break;
		case Play_Mode:
			RArm->mtn->Play_timer(RArm);
			break;
		}
	}

}

void MaSaGRobot::ControlLaw()
{
	// Left Arm
	switch (LArm->control_mode)
	{
	case Cartesian_Mode:
		LArm->ctrl.Cartesian_Impedance(LArm);
		break;
	case Joint_Mode:
		LArm->ctrl.Joint_Impdeance(LArm);
		break;
	case Free_Mode:
		LArm->ctrl.Free_Mode(LArm);
		break;
	}

	// Right Arm
	switch (RArm->control_mode)
	{
	case Cartesian_Mode:
		RArm->ctrl.Cartesian_Impedance(RArm);
		break;
	case Joint_Mode:
		RArm->ctrl.Joint_Impdeance(RArm);
		break;
	case Free_Mode:
		RArm->ctrl.Free_Mode(RArm);
		break;
	}
}

void MaSaGRobot::commandOutput()
{
	LArm->tarTorque(3) *= -1;
	LArm->tarTorque(4) *= -1;
	LArm->torqueCMD();
	RArm->tarTorque(2) *= -1;
	RArm->tarTorque(3) *= -1;
	RArm->tarTorque(6) *= -1;
	RArm->torqueCMD();
}

MaSaGRobot::~MaSaGRobot()
{
	delete LArm;
	delete RArm;
}

void MaSaGRobot::shoulderPOS(int arm_index, int direction_index, float angle)
{
	RTN_ERR ret;

	int targetPos;

	if (arm_index == LEFT_ARM)
	{
		LArm->joint[0]->driver->haltOff();
		Sleep(100);

		targetPos = angle / 360.0f * LArm->joint[0]->driver->_resEncoder * LArm->joint[0]->_gearRatio;
		if (direction_index == INWARD)
			LArm->joint[0]->driver->cmdPosition(-targetPos, REL_MOTION);
		else if(direction_index == OUTWARD)
			LArm->joint[0]->driver->cmdPosition( targetPos, REL_MOTION);
	}
	else if (arm_index == RIGHT_ARM)
	{
		RArm->joint[0]->driver->haltOff();
		Sleep(100);

		targetPos = angle / 360.0f * RArm->joint[0]->driver->_resEncoder * RArm->joint[0]->_gearRatio;
		if (direction_index == INWARD)
			RArm->joint[0]->driver->cmdPosition( targetPos, REL_MOTION);
		else if (direction_index == OUTWARD)
			RArm->joint[0]->driver->cmdPosition(-targetPos, REL_MOTION);
	}

}