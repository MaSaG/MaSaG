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
	for (i = 1; i < ARM_DOF; i++)
		arm->Fext(i) = Kd[i] * arm->plnTCP(i);

	arm->torque = arm->Jacobian.transpose()*arm->Fext;
}

void Control::Joint_Impdeance(Manipulator* arm)
{
	// input:  q0LArm, q0RArm
	// output: torqueLArm, torqueRArm
	int i;
	float q, q0;
	for (i = 0; i < ARM_DOF; i++)
	{
		q  = arm->curJoint(i);
		q0 = arm->plnJoint(i);
		torque = DigitalModel(Kim[i], q0, q, arm->q1[i], arm->q2[i], mDATA[i]);
		damper = DamperGenerator(Dim[i], q, arm->q1[i]);
		Integrator(intAcc[i], iGain[i], q0, q);
		arm->torque[i] = torque + damper + intAcc[i];
	}
}

void Control::Free_Mode(Manipulator* arm)
{
	Vectornf gravity;
	arm->tarTCP_T = arm->curTCP_T;
	arm->tarTCP = arm->curTCP;
	arm->plnTCP = arm->tarTCP;
	arm->dyn.GravityComp(arm->curJoint, gravity);
	arm->torque = gravity;
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

	iGain[0] = 0.2;
	iGain[1] = 0.2;
	iGain[2] = 0.2;
	iGain[3] = 0.2;
	iGain[4] = 0.2;
	iGain[5] = 0.2;
	iGain[6] = 0.2;

	Dim[0] = 10;
	Dim[1] = 10;
	Dim[2] = 10;
	Dim[3] = 10;
	Dim[4] = 10;
	Dim[5] = 10;
	Dim[6] = 10;

	Kim[0] = 2000;
	Kim[1] = 2000;
	Kim[2] = 2000;
	Kim[3] = 2000;
	Kim[4] = 2000;
	Kim[5] = 2000;
	Kim[6] = 2000;

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
	float damper = -Dim*(q - q1) / SERVOLOOP_TIME;
	return damper;
}

float Control::DigitalModel(float Kim, float q0, float q, float q1, float q2, MotorDATA m)
{
	float T = SERVOLOOP_TIME;
	float v0 = m.Im/T/T;
	float v1 = (m.Cm + m.Km*m.Kb / m.R) / T;
	float torque = q0*Kim - q*(Kim + v0 + v1 ) + q1*(2*v0 + v1) - q2*v0;
	return torque;
}