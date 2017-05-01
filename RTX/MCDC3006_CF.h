#ifndef _MCDC3006_CF_H
#define _MCDC3006_CF_H

#include "absDriver.h"

class MCDC3006_CF : public absDriver
{
public:
	void	initialization();
	int		servoOn();
	int		servoOff();
	int		Halt();
	int		readEncoder();
	int		readVelocity();
	int		readTorque();
	int		cmdPosition(int pos);
	int		cmdVelocity(int vel);
	int		cmdTorque(float torque);
};

#endif