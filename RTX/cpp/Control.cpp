#include "Control.h"
#include "Manipulator.h"

Control::Control()
{
	initParams();
}

void Control::Cartesian_Impedance(Manipulator* arm)
{
	// input:  plnTCP_LArm, plnTCP_RArm
	// output: torqueLArm, torqueRArm
	int i;
	Vectornf gravity;
	arm->dyn.GravityComp(arm->curJoint, gravity);
	for (i = 1; i < ARM_DOF; i++)
		arm->Fext(i) = Kd[i] * arm->plnTCP(i);

	arm->tarTorque = arm->Jacobian.transpose()*arm->Fext + gravity;
}

void Control::Joint_Impdeance(Manipulator* arm)
{
	// input:  q0LArm, q0RArm
	// output: torqueLArm, torqueRArm
	int i;
	float q, q0;
	Vectornf gravity;
	arm->dyn.GravityComp(arm->curJoint, gravity);
	for (i = 0; i < ARM_DOF; i++)
	{
		q  = arm->curJoint(i);
		q0 = arm->plnJoint(i);
		torque = DigitalModel(Kim[i], q0, q, arm->q1[i], arm->q2[i], mDATA[i]);
		damper = DamperGenerator(Dim[i], q, arm->q1[i]);
		Integrator(intAcc[i], iGain[i], q0, q);
		arm->tarTorque[i] = torque + damper + intAcc[i];
	}
	arm->tarTorque += gravity;
}

void Control::Free_Mode(Manipulator* arm)
{
	Vectornf gravity;
	arm->tarTCP_T = arm->curTCP_T;
	arm->tarTCP = arm->curTCP;
	arm->plnTCP = arm->tarTCP;
	arm->dyn.GravityComp(arm->curJoint, gravity);
	arm->tarTorque = gravity;

}

void Control::initParams()
{

	Kd[0] = 200;		//unused
	Kd[1] = 200;
	Kd[2] = 200;
	Kd[3] = 200;
	Kd[4] = 100;
	Kd[5] = 100;
	Kd[6] = 100;

	iGain[0] = 0.02;
	iGain[1] = 0.06;
	iGain[2] = 0.025;
	iGain[3] = 0.04;
	iGain[4] = 0.025;
	iGain[5] = 0.02;
	iGain[6] = 0.02;

	Dim[0] = 0;
	Dim[1] = 0;
	Dim[2] = 0;
	Dim[3] = 0;
	Dim[4] = 0;
	Dim[5] = 0;
	Dim[6] = 0;

	Kim[0] = 60;
	Kim[1] = 160; //80
	Kim[2] = 200; //100
	Kim[3] = 60;
	Kim[4] = 100;
	Kim[5] = 60;
	Kim[6] = 60;

	damper = 0;
	torque = 0;
	intAcc.setZero();

}

void Control::Integrator(float& acc, float iGain, float q0, float q)	//¿n¤À
{
	// gain*error = gain*(q0-q)*T = iGain*(q0-q) 
	acc += iGain*(q0 - q);
}

float Control::DamperGenerator(float Dim, float q, float q1)
{
	float damper = Dim*(q - q1) / SERVOLOOP_TIME;
	return damper;
}

float Control::DigitalModel(float Kim, float q0, float q, float q1, float q2, MotorDATA m)
{
	float T = SERVOLOOP_TIME;
	// float v0 = m.Im/T/T;
	// float v1 = (m.Cm + m.Km*m.Kb / m.R) / T;
	float torque = (q0 - q)*Kim; // -q*(v0 + v1) + q1*(2 * v0 + v1) - q2*v0;
	return torque;
}