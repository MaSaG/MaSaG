#ifndef _JOINT_H
#define _JOINT_H

#include "absDriver.h"


class Joint
{
public:
	Joint(void* mAxis, float gear, int encoder, int driver_type);
	void updateJoint();
	~Joint();

	float		_angle;
	absDriver*	driver;
private:
	float		_gearRatio;

};


#endif