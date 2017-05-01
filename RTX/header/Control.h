#pragma once
#include "kinematics.h"
#include "User_Data.h"
#include "motorData.h"

class Manipulator;

enum { Free_Mode, Cartesian_Mode, Joint_Mode };

class Control
{
public:
	Control();
	void Cartesian_Impedance(Manipulator* arm);
	void Joint_Impdeance(Manipulator* arm);
	void Free_Mode(Manipulator* arm);
		
private:
	void  initParams();
	void  Integrator(float& acc, float iGain, float q0, float q);
	float DamperGenerator(float Dim, float q, float q1);
	float DigitalModel(float Kim, float q0, float q, float q1, float q2, MotorDATA m);

	Vectornf Md, Dd, Kd;
	Vectornf intAcc;
	Vectornf iGain, Dim, Kim;
	float damper, torque;
	
};