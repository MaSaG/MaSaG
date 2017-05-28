#include "RTX.h"

RTX::RTX()
{
	shHandle = NULL;
	obHandle = NULL;
	masterId = 0;
	SharedMemory_Init();
	RTX_Event_Init();
}

int RTX::WaitForSingleObject(int msec)
{
	ret = RtWaitForSingleObject(obHandle, msec);
	return ret;
}

void RTX::SharedMemory_Init()
{
	shHandle = RtCreateSharedMemory((DWORD)PAGE_READWRITE, (DWORD)0, (DWORD) sizeof(USER_DAT), SHM_NAME, &location);
	if (shHandle == NULL)
	{
		RtPrintf("RtCreateSharedMemory failed.\n");
		ExitProcess(0);
	}
	pData = (USER_DAT*)(location);
}

void RTX::RTX_Event_Init()
{
	obHandle = RtCreateEvent(NULL, 0, FALSE, EVN_NAME);
	if (obHandle == NULL)
	{
		RtPrintf("RtCreateEvent failed.\n");
		ExitProcess(0);
	}
}

int RTX::Get_Drivers_ID()
{
	// Left 1, EPOS 3
	ret = NEC_CoE402GetAxisId(masterId, 0, &pData->_rtxLArm.mAxis[1]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 1); return 1; }
	// Right 1, EPOS 3
	ret = NEC_CoE402GetAxisId(masterId, 1, &pData->_rtxRArm.mAxis[1]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 1); return 1; }
	// Left 0, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 2, &(pData->_rtxLArm.mAxis[0]));
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 0); return 1; }
	// Left 2, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 3, &(pData->_rtxLArm.mAxis[2]));
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 2); return 1; }
	// Left 3, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 4, &(pData->_rtxLArm.mAxis[3]));
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 3); return 1; }
	// Left 4, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 5, &(pData->_rtxLArm.mAxis[4]));
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 4); return 1; }
	// Right 0, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 6, &pData->_rtxRArm.mAxis[0]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 0); return 1; }
	// Right 2, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 7, &pData->_rtxRArm.mAxis[2]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 2); return 1; }
	// Right 3, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 8, &pData->_rtxRArm.mAxis[3]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 3); return 1; }
	// Right 4, MAXPOS
	ret = NEC_CoE402GetAxisId(masterId, 9, &pData->_rtxRArm.mAxis[4]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 4); return 1; }
	// ON 0, Left F/T Sensor
	ret = NEC_CoE402GetAxisId(masterId, 10, &pData->_rtxLArm.mAxis[7]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 7); return 1; }
	// Left 5, mcDSA-E65
	ret = NEC_CoE402GetAxisId(masterId, 11, &pData->_rtxLArm.mAxis[5]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 5); return 1; }
	// Left 6, mcDSA-E65
	ret = NEC_CoE402GetAxisId(masterId, 12, &pData->_rtxLArm.mAxis[6]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! L %d", 6); return 1; }
	// ON 1, Right F/T Sensor
	ret = NEC_CoE402GetAxisId(masterId, 13, &pData->_rtxRArm.mAxis[7]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 7); return 1; }
	// Right 5, mcDSA-E65
	ret = NEC_CoE402GetAxisId(masterId, 14, &pData->_rtxRArm.mAxis[5]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 5); return 1; }
	// Right 6, mcDSA-E65
	ret = NEC_CoE402GetAxisId(masterId, 15, &pData->_rtxRArm.mAxis[6]);
	if (ret != 0) { RtPrintf("NEC_CoE402GetAxisId failed! R %d", 6); return 1; }

	return 0;
}

int RTX::MotorParams_Init()
{
	int		i, size;

	// Left 0: MAXPOS + RE40 (PP mode)
	size = sizeof(PARAM_L0) / sizeof(PARAM_L0[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[0], PARAM_L0[i][0], PARAM_L0[i][1], PARAM_L0[i][2], PARAM_L0[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L0\n", ret, i); return 1; }
	}

	// Left 1: EPOS3 + RE50 (CST mode)
	size = sizeof(PARAM_L1) / sizeof(PARAM_L1[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[1], PARAM_L1[i][0], PARAM_L1[i][1], PARAM_L1[i][2], PARAM_L1[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L1\n", ret, i); return 1; }
	}

	// Left 2:  MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_L2) / sizeof(PARAM_L2[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[2], PARAM_L2[i][0], PARAM_L2[i][1], PARAM_L2[i][2], PARAM_L2[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L2\n", ret, i); return 1; }
	}

	// Left 3: MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_L3) / sizeof(PARAM_L3[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[3], PARAM_L3[i][0], PARAM_L3[i][1], PARAM_L3[i][2], PARAM_L3[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L3\n", ret, i); return 1; }
	}

	// Left 4: MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_L4) / sizeof(PARAM_L4[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[4], PARAM_L4[i][0], PARAM_L4[i][1], PARAM_L4[i][2], PARAM_L4[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L4\n", ret, i); return 1; }
	}
	
	// Left 5: mcDSA-E65 + RE25 (PT mode)
	size = sizeof(PARAM_L5) / sizeof(PARAM_L5[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[5], PARAM_L5[i][0], PARAM_L5[i][1], PARAM_L5[i][2], PARAM_L5[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L5\n", ret, i); return 1; }
	}

	// Left 6: mcDSA-E65 + RE25 (PT mode)
	size = sizeof(PARAM_L6) / sizeof(PARAM_L6[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxLArm.mAxis[6], PARAM_L6[i][0], PARAM_L6[i][1], PARAM_L6[i][2], PARAM_L6[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of L6\n", ret, i); return 1; }
	}

	//----------------------------------------------------------------------------------------------------------------------//

	// Right 0: MAXPOS + RE40 (PP mode)
	size = sizeof(PARAM_R0) / sizeof(PARAM_R0[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[0], PARAM_R0[i][0], PARAM_R0[i][1], PARAM_R0[i][2], PARAM_R0[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R0\n", ret, i); return 1; }
	}

	// Right 1: EPOS3 + RE50 (CST mode)
	size = sizeof(PARAM_R1) / sizeof(PARAM_R1[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[1], PARAM_R1[i][0], PARAM_R1[i][1], PARAM_R1[i][2], PARAM_R1[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R1\n", ret, i); return 1; }
	}

	// Right 2:  MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_R2) / sizeof(PARAM_R2[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[2], PARAM_R2[i][0], PARAM_R2[i][1], PARAM_R2[i][2], PARAM_R2[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R2\n", ret, i); return 1; }
	}

	// Right 3: MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_R3) / sizeof(PARAM_R3[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[3], PARAM_R3[i][0], PARAM_R3[i][1], PARAM_R3[i][2], PARAM_R3[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R3\n", ret, i); return 1; }
	}

	// Right 4: MAXPOS + RE40 (CST mode)
	size = sizeof(PARAM_R4) / sizeof(PARAM_R4[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[4], PARAM_R4[i][0], PARAM_R4[i][1], PARAM_R4[i][2], PARAM_R4[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R4\n", ret, i); return 1; }
	}

	// Right 5: mcDSA-E65 + RE25 (PT mode)
	size = sizeof(PARAM_R5) / sizeof(PARAM_R5[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[5], PARAM_R5[i][0], PARAM_R5[i][1], PARAM_R5[i][2], PARAM_R5[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R5\n", ret, i); return 1; }
	}

	// Right 6: mcDSA-E65 + RE25 (PT mode)
	size = sizeof(PARAM_R6) / sizeof(PARAM_R6[0]);
	for (i = 0; i < size; i++)
	{
		ret = NEC_CoE402SetParameter(pData->_rtxRArm.mAxis[6], PARAM_R6[i][0], PARAM_R6[i][1], PARAM_R6[i][2], PARAM_R6[i][3]);
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402SetParameter() error %d Parameter %d of R6\n", ret, i); return 1; }
	}

	return 0;
}

int RTX::Init()
{
	RTN_ERR     ret;
	U16_T       coeAxisAddr = 0;
	U16_T       slaveCnt;
	
	RtPrintf("this event is opened.\n");

	ret = NEC_RtInitMaster(masterId);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtInitMaster() error %d \n", ret); return 1; }

	ret = NEC_CoE402Reset();
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402Reset() error %d \n", ret); return 1; }

	ret = NEC_RtGetSlaveCount(masterId, &slaveCnt);
	RtPrintf(" \n\nEni slave count = %d \n", slaveCnt);


	// Get Drivers ID
	rflag = Get_Drivers_ID();
	if (rflag)	return 1;

	RtPrintf("%d\n", pData->_rtxLArm.mAxis[0]);
	RtPrintf("%d\n", pData->_rtxLArm.mAxis[1]);
	RtPrintf("%d\n", pData->_rtxLArm.mAxis[2]);


	ret = NEC_RtSetParameter(masterId, NEC_PARA_S_ECM_CYCLETIMEUS, 1000);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtSetParameter() error %d \n", ret); return 1; }

	RtPrintf("start master!.\n");
	
	// Register client
	clientParam.version = NEC_RtRetVer();
	clientParam.userDataPtr = pData;
	clientParam.cyclicCallback = __RtCyclicCallback;
	clientParam.eventCallback  = __RtEventCallback;
	clientParam.errorCallback  = __RtErrorCallback;

	ret = NEC_RtRegisterClient(masterId, &clientParam);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtRegisterClient() error %d \n", ret); return 1; }
	ret = NEC_RtStartMaster(masterId);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtStartMaster() error %d \n", ret); return 1; }
	ret = NEC_RtSetMasterStateWait(masterId, ECM_STA_SAFEOP, 5000);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtSetMasterStateWait() error %d \n", ret); }

	//Update PDO Mapping & Fault Reset
	for (int i = 0; i < ARM_DOF; i++)
	{
		ret = NEC_CoE402UpdatePdoMapping(pData->_rtxLArm.mAxis[i]);
		if (ret != 0) { RtPrintf("NEC_CoE402UpdatePdoMapping failed! %d L %d \n", ret, i); return 1; }
		ret = NEC_CoE402UpdatePdoMapping(pData->_rtxRArm.mAxis[i]);
		if (ret != 0) { RtPrintf("NEC_CoE402UpdatePdoMapping failed! %d R %d \n", ret, i); return 1; }
		ret = NEC_CoE402FaultReset(pData->_rtxLArm.mAxis[i], 5000);
		if (ret != 0) { RtPrintf("NEC_CoE402FaultReset failed!%d L %d \n", ret, i); return 1; }
		ret = NEC_CoE402FaultReset(pData->_rtxRArm.mAxis[i], 5000);
		if (ret != 0) { RtPrintf("NEC_CoE402FaultReset failed!%d R %d \n", ret, i); return 1; }
	}

	ret = NEC_RtChangeStateToOP(masterId, 5000);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtChangeStateToOP() error %d \n", ret); }

	RtPrintf("Change state to op, going to set mode of operation\n");

	// Initialization of Motor's Parameters
	rflag = MotorParams_Init();
	if (rflag)	return 1;

	RtPrintf("motor paramters initialization\n");

	//Servo On
	for (int i = 0; i < ARM_DOF; i++)
	{
		ret = NEC_CoE402ServoOn(pData->_rtxLArm.mAxis[i], 1);  // 0:ServoOff, 1:ServoOn
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402ServoOn() error %d L %d \n", ret, i); return 1; }
		ret = NEC_CoE402ServoOn(pData->_rtxRArm.mAxis[i], 1);  // 0:ServoOff, 1:ServoOn
		if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402ServoOn() error %d R %d \n", ret, i); return 1; }
	}

	RtPrintf("Servo On\n");

	RtPrintf("initial finished\n");

	return 0;
}

void RTX::Info()
{
	U32_T       runSec = 10;    // time for running. Unit: second. Users can set their wanted running time.
	I32_T       cycleTime = 1000; // cycle time for EtherCAT communication. Unit: microsecond
	F64_T       run_times = (runSec * 1000000) / cycleTime;

	RtPrintf("cycle time:%d\n", cycleTime);
	pData->_rtxCMD_ST.runTime = (U32_T)run_times;
	RtPrintf("run time:%d\n", pData->_rtxCMD_ST.runTime);
	pData->_rtxCMD_ST.startFlag = 0;
}

void RTX::Close_Process()
{
	RtPrintf("Going to Stop\n");

	ret = NEC_RtStopMaster(masterId);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtStopMaster() error %d \n", ret); }

	ret = NEC_RtUnregisterClient(masterId, &clientParam);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtUnregisterClient() error %d \n", ret); }

	ret = NEC_CoE402Close();
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_CoE402Close() error %d \n", ret); }

	ret = NEC_RtCloseMaster(masterId);
	if (ret != ECERR_SUCCESS) { RtPrintf("NEC_RtCloseMaster() error %d \n", ret); }

	RtCloseHandle(obHandle);
	RtCloseHandle(shHandle);
	ExitProcess(0);
}

