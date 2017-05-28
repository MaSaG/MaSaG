#pragma once

#include "MaSaG_RTSS.h"

#define ARM_DOF		7
#define LEFT_ARM	0
#define RIGHT_ARM	1

typedef struct
{
	CANAxis_T	mAxis[ARM_DOF + 1];			// dof+1 for f/t sensors
	// joint information
	F32_T		curPos[ARM_DOF];
	F32_T		tarPos[ARM_DOF];
	F32_T		errPos[ARM_DOF];
	F32_T		plnPos[ARM_DOF];
	F32_T		curVel[ARM_DOF];
	// torque command and output
	F32_T		actTorque[ARM_DOF];
	F32_T		tarTorque[ARM_DOF];
	// TCP information
	F32_T		curTCP[6];
	F32_T		tarTCP[6];
	F32_T		errTCP[6];
	F32_T		plnTCP[6];
	F32_T		velTCP[6];
	F32_T		curROT[9];
	// force/torque feedback
	F32_T		FTSensor[6];
	// ethercat device information
	U16_T		slaveState[ARM_DOF];
	U8_T		controlMode[ARM_DOF];
	I32_T		cntTimer;
}RTX_ARM_DATA;

typedef struct
{
	//Master
	U16_T		masterId;
	U16_T		MasterState;
	I32_T		Control;
	I32_T		Command;
	I8_T		currentState[20];
	U32_T		runTime;
	BOOL_T		startFlag;
}RTX_CMD_STATE;


typedef	struct
{
	RTX_ARM_DATA	_rtxRArm;
	RTX_ARM_DATA	_rtxLArm;
	RTX_CMD_STATE	_rtxCMD_ST;
}USER_DAT;

