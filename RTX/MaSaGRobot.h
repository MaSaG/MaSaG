#pragma once

#include "RTX.h"
#include "Manipulator.h"

enum {INWARD, OUTWARD};

class MaSaGRobot
{
public:
	RTX				_RTX;
	Manipulator*	RArm;
	Manipulator*	LArm;
	
	MaSaGRobot();
	~MaSaGRobot();
	
	int  initRobot();
	void updateFeedback();
	void updateState();
	void updateSharedMemory();
	void MotionTrajGen();
	void ControlLaw();
	void commandOutput();

	void shoulderPOS(int arm_index, int direction_index, float angle);


private:
	
	

};