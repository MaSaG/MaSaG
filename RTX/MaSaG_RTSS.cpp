//////////////////////////////////////////////////////////////////
//
// Sample2AxesControl_RTX.c - c file
//
// This file was generated using the RTX 2016 SDK 12.0.0.1324
// RTX Application Template.
//
// Created: 5/20/2016 2:30:58 PM 
// User: NET3640
//
//////////////////////////////////////////////////////////////////

#include "MaSaGRobot.h"
#include "User_Data.h"

MaSaGRobot*	robot;

int execProgram(int& cmd);

int main(int  argc,	char **argv)
{
	robot = new MaSaGRobot;
	RTN_ERR     ret;

	while (1)
	{
		robot->_RTX.Info();
		ret = robot->_RTX.WaitForSingleObject(-3);
		if (ret == 0)
		{
			ret = robot->initRobot();		if (ret) return 1;
			Sleep(2000);

			//MASSAGE PROGRAM!!!
			while (1)
				if (execProgram(robot->_RTX.pData->_rtxCMD_ST.Command))
					break;

			robot->_RTX.Close_Process();
		}
	}

	delete robot;

	return 0;
}

int execProgram(int& cmd)
{
	int i;
	Vectornf joint_pos;
	switch (cmd)
	{
	case TEACH_CMD:
		RtPrintf("teach command\n");
		robot->RArm->mtn->TEACH(robot->RArm);
		while (1)
			if (cmd != TEACH_CMD)
				break;
		break;

	case PLAY_CMD:
		RtPrintf("play command\n");
		robot->RArm->mtn->PLAY(robot->RArm);
		cmd = READY_CMD;
		break;

	case TEST3_CMD:
		RtPrintf("test3 command\n");
		cmd = READY_CMD;
		break;

	case TEST4_CMD:
		RtPrintf("test4 command\n");
		cmd = READY_CMD;
		break;

	case TEST5_CMD:
		RtPrintf("test5 command\n");
		cmd = READY_CMD;
		break;

	case TEST6_CMD:
		RtPrintf("test6 command\n");
		cmd = READY_CMD;
		break;

	case TEST7_CMD:
		RtPrintf("test7 command\n");
		cmd = READY_CMD;
		break;

	case FREE_MODE_CMD:
		RtPrintf("Free Mode command\n");
		robot->LArm->mtn->FREE_MODE(robot->LArm);
		robot->RArm->mtn->FREE_MODE(robot->RArm);
		cmd = READY_CMD;
		break;

	case MIRROR_CMD:
		RtPrintf("MIRROR\n");
		robot->RArm->mtn->MIRROR(robot->RArm);
		cmd = READY_CMD;
		break;

	case MIMMIC_CMD:
		RtPrintf("MIMMIC\n");
		robot->RArm->mtn->MIMMIC(robot->RArm);
		cmd = READY_CMD;
		break;

	case ALIGN_CMD:
		RtPrintf("test11 command\n");
		joint_pos = robot->LArm->curJoint * 180.0f / M_PI;
		robot->RArm->mtn->MOV_JOINT(robot->RArm, joint_pos, 5.0f);
		cmd = READY_CMD;
		break;

	case TEST12_CMD:
		RtPrintf("test12 command\n");
		cmd = READY_CMD;
		break;

	case TEST13_CMD:
		RtPrintf("test13 command\n");
		cmd = READY_CMD;
		break;

	case TEST14_CMD:
		RtPrintf("test14 command\n");
		cmd = READY_CMD;
		break;

	case TEST15_CMD:
		RtPrintf("test15 command\n");
		robot->RArm->mtn->MOV_JOINT(robot->RArm, 10.0, 4, 5.0);
		cmd = READY_CMD;
		break;

	case TEST16_CMD:
		RtPrintf("test16 command\n");
		robot->RArm->mtn->MOV_JOINT(robot->RArm, 0.0, 4, 5.0);
		cmd = READY_CMD;
		break;

	case TEST17_CMD:
		RtPrintf("test17 command\n");
		robot->RArm->mtn->MOV_JOINT(robot->RArm, 5.0, 4, 5.0);
		cmd = READY_CMD;
		break;
		
	case SERVOON_CMD:
		RtPrintf("Servo On command\n");
		for (i = 0; i < ARM_DOF; i++)
		{
			robot->LArm->joint[i]->driver->servoOn();
			robot->RArm->joint[i]->driver->servoOn();
		}
		cmd = READY_CMD;
		break;

	case SERVOOFF_CMD:
		for (i = 0; i < ARM_DOF; i++)
		{
			robot->LArm->joint[i]->driver->servoOff();
			robot->RArm->joint[i]->driver->servoOff();
		}
		RtPrintf("Servo Off command\n");
		cmd = READY_CMD;
		break;

	case HOME_CMD:
		RtPrintf("Home command\n");
		
		joint_pos[0] = 0;
		joint_pos[1] = -90;
		joint_pos[2] = 90;
		joint_pos[3] = 0;
		joint_pos[4] = 0;
		joint_pos[5] = 0;
		joint_pos[6] = 90;
		robot->RArm->mtn->MOV_JOINT(robot->RArm, joint_pos, 5.0f);
		
		cmd = READY_CMD;
		break;

	case FAULTRESET_CMD:
		RtPrintf("clear fault command\n");
		cmd = READY_CMD;
		break;

	case PRINT_CMD:
		RtPrintf("print command\n");
		cmd = PRINT_CMD;
		break;

	case ESCAPE_CMD:
		RtPrintf("escape command\n");
		break;
	}

	// out of the loop
	if (cmd == ESCAPE_CMD)
		return 1;
	else
		return 0;
}
