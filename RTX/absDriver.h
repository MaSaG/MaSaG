#ifndef _ABSDRIVER_h
#define _ABSDRIVER_h

enum {REL_MOTION, ABS_MOTION};

class absDriver
{
public:
	virtual int	 servoOn() = 0;
	virtual int  servoOff() = 0;
	virtual int  haltOn() = 0;
	virtual int  haltOff() = 0;
	virtual int  faultReset() = 0;
	virtual int  home() = 0;
	virtual int  readEncoder() = 0;
	virtual int  readVelocity() = 0;
	virtual int  readTorque(float &torque)  = 0;
	virtual int  cmdPosition(int pos, int option) = 0;
	virtual int  cmdVelocity(int vel) = 0;
	virtual int  cmdTorque(float torque) = 0;
	
	void*	_nodeID;				// node ID for EtherCAT or CANOpen
	int		_countEncoder;
	int		_resEncoder;
	int		_actualVelocity;
	short   _actualTorque;			// 0~1000
	short   _targetTorque;			// 0~1000
	unsigned int _maxVel;
	unsigned int _profileAcc;
	unsigned int _profileDec;
	float	_ratedTorque;

};

#endif