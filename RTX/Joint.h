#ifndef _JOINT_H
#define _JOINT_H

#include "absDriver.h"


class Joint
{
public:
	Joint(void* mAxis, float gear, int encoder, float rated_torque, int driver_type);
	void updateJoint(int cntOffset);
	~Joint();

	float		_angle;
	absDriver*	driver;
	float		_gearRatio;

private:

};


#endif