#ifndef _EPOS3_CST_H
#define _EPOS3_CST_H

#include "absDriver.h"
#include "MaSaG_RTSS.h"

class EPOS3 : public absDriver
{
public:
	EPOS3();
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