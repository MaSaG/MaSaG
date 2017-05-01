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
	switch (cmd)
	{
	case TEST1_CMD:
		RtPrintf("test1 command\n");
		robot->shoulderPOS(LEFT_ARM, INWARD, 5);
		cmd = READY_CMD;
		break;

	case TEST2_CMD:
		RtPrintf("test2 command\n");
		robot->shoulderPOS(LEFT_ARM, OUTWARD, 5);
		cmd = READY_CMD;
		break;

	case TEST3_CMD:
		RtPrintf("test3 command\n");
		robot->shoulderPOS(RIGHT_ARM, INWARD, 5);
		cmd = READY_CMD;
		break;

	case TEST4_CMD:
		RtPrintf("test4 command\n");
		robot->shoulderPOS(RIGHT_ARM, OUTWARD, 5);
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

	case TEST8_CMD:
		RtPrintf("test8 command\n");
		cmd = READY_CMD;
		break;

	case TEST9_CMD:
		RtPrintf("test9 command\n");
		cmd = READY_CMD;
		break;

	case TEST10_CMD:
		RtPrintf("test10 command\n");
		cmd = READY_CMD;
		break;

	case TEST11_CMD:
		RtPrintf("test11 command\n");
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
		cmd = READY_CMD;
		break;

	case TEST16_CMD:
		RtPrintf("test16 command\n");
		cmd = READY_CMD;
		break;

	case TEST17_CMD:
		RtPrintf("test17 command\n");
		cmd = READY_CMD;
		break;
		
	case SERVOON_CMD:
		RtPrintf("Servo On command\n");
		for (i = 0; i < ARM_DOF - 2; i++)
		{
			robot->LArm->joint[i]->driver->servoOn();
			robot->RArm->joint[i]->driver->servoOn();
		}
		cmd = READY_CMD;
		break;

	case SERVOOFF_CMD:
		for (i = 0; i < ARM_DOF - 2; i++)
		{
			robot->LArm->joint[i]->driver->servoOff();
			robot->RArm->joint[i]->driver->servoOff();
		}
		RtPrintf("Servo Off command\n");
		cmd = READY_CMD;
		break;

	case HOME_CMD:
		RtPrintf("Reset command\n");
		cmd = READY_CMD;
		break;

	case FAULTRESET_CMD:
		RtPrintf("clear fault command\n");
		cmd = READY_CMD;
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
