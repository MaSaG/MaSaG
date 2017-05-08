#include "Joint.h"
#include "SystemParams.h"
#include "EPOS3.h"
#include "MAXPOS.h"
#include "mcDSA-E65.h"
#include "MCDC3006_CF.h"

Joint::Joint(void* mAxis, float gear, int encoder, float rated_torque, int driver_type)
{
	switch (driver_type)
	{
	case TYPE_MAXPOS:
		driver = new MAXPOS;
		break;

	case TYPE_EPOS3:
		driver = new EPOS3;
		break;

	case TYPE_mcDSA_E65:
		driver = new mcDSA_E65;
		break;

	case TYPE_MCDC3006_CF:
		// to do
		break;
	}
	_gearRatio= gear;
	driver->_nodeID = mAxis;
	driver->_resEncoder = encoder;
	driver->_ratedTorque = rated_torque;
}

void Joint::updateJoint(int cntOffset)
{
	driver->readEncoder();
	_angle = (float)(driver->_countEncoder + cntOffset) / _gearRatio / driver->_resEncoder * 2*M_PI;
}

Joint::~Joint()
{
	delete driver;
}