#pragma once
#include "SystemParams.h"
#include "kinematics.h"
#include "Joint.h"

class dynamics
{
public:
	void GravityComp(Vectornf& q, Vectornf& gravityTorque);


};