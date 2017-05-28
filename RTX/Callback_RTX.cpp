#include "Callback_RTX.h"
#include "MaSaGRobot.h"

extern MaSaGRobot* robot;

void __RtCyclicCallback(void *UserDataPtr)
{
	USER_DAT	*pData = (USER_DAT *)UserDataPtr;
	U16_T		state;

	NEC_RtGetMasterState(pData->_rtxCMD_ST.masterId, &state);
	pData->_rtxCMD_ST.MasterState = state;
	switch (state)
	{
	case ECM_STA_OPERATION:
		NEC_CoE402CyclicProcess();
		
		// encorder feedback
		robot->updateFeedback();
		// State Update
		robot->updateState();
		// Motion Plan: Massage Techniques
		robot->MotionTrajGen();
		// control algorithm
		robot->ControlLaw();
		// output command
		// robot->commandOutput();
		// update shared memory
		robot->updateSharedMemory();

		break;
	}
}

void __RtEventCallback(void *UserDataPtr, U32_T EventCode)
{
	RTN_ERR ret;
	USER_DAT *pData = (USER_DAT *)UserDataPtr;
	U16_T state;

	switch (EventCode)
	{
	case EVENT_ECM_STATE_CHANGE:
		ret = NEC_RtGetMasterState(pData->_rtxCMD_ST.masterId, &state);
		if (ret != ECERR_SUCCESS)
			RtPrintf("error code: %d \n", ret);
		RtPrintf("State change event! state change to: %d \n", state);
		break;
	}
}

void __RtErrorCallback(void *UserDataPtr, I32_T ErrorCode)
{
	//RTN_ERR ret;
	USER_DAT *pData = (USER_DAT *)UserDataPtr;

	RtPrintf("\n\n\n ********************************************************************** \n");
	RtPrintf("[x] ERROR!! __RtErrorCallback() ErrorCode = %d \n", ErrorCode);
	RtPrintf("    Stop master!!\n");
	RtPrintf("********************************************************************** \n\n\n");
}
