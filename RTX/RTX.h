#pragma once

#include "Callback_RTX.h"

class RTX
{
public:
	int			rflag;
	USER_DAT	*pData;

	RTX();
	int			WaitForSingleObject(int msec);
	int			Get_Drivers_ID();
	int			MotorParams_Init();
	int			Init();
	void		Info();
	void		Close_Process();


private:

	HANDLE		shHandle;
	HANDLE		obHandle;
	RTN_ERR     ret;
	U16_T       masterId;
	TClintParam clientParam;
	void		SharedMemory_Init();
	void		RTX_Event_Init();
	

};
