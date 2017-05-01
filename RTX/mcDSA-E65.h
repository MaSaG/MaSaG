#ifndef _MCDSA_E65_PT_H
#define _MCDSA_E65_PT_H

#include "absDriver.h"
#include "MaSaG_RTSS.h"

class mcDSA_E65 : public absDriver
{
public:
	mcDSA_E65();
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