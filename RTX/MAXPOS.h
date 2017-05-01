#ifndef _MAXPOS_PP_H
#define _MAXPOS_PP_H

#include "absDriver.h"
#include "MaSaG_RTSS.h"

class MAXPOS : public absDriver
{
public:
	MAXPOS();
	int		servoOn();
	int		servoOff();
	int		haltOn();
	int		haltOff();
	int		faultReset();
	int		home();
	int		readEncoder();
	int		readVelocity();
	int		readTorque(float& torque);
	int		cmdPosition(int pos, int option);
	int		cmdVelocity(int vel);
	int		cmdTorque(float torque);

private:
	RTN_ERR     ret;
};

#endif