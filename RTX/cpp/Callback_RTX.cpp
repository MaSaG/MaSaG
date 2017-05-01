#include "Callback_RTX.h"

#include "JointSpace.h"
#include "MaSaGRobot.h"

extern MaSaGRobot* robot;

void __RtCyclicCallback(void *UserDataPtr)
{
	USER_DAT	*pData = (USER_DAT *)UserDataPtr;
	U16_T		state;
	// RTN_ERR		ret;
	

	NEC_RtGetMasterState(pData->masterId, &state);
	pData->MasterState = state;
	switch (state)
	{
	case ECM_STA_OPERATION:
		NEC_CoE402CyclicProcess();
		
		// encorder feedback
		robot->updateFeedback();

		// State Update
		robot->updateState();

		// control algorithm
		switch (robot->_RTX.pData->Control)
		{
		case Cartesian_Mode:
			break;

		case Joint_Mode:
			break;
		
		case Free_Mode:
			break;
		
		}




		// output command
		robot->commandOuput();

		// record the last state
		robot->updateData();


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
		ret = NEC_RtGetMasterState(pData->masterId, &state);
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
