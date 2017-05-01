#include "Motion.h"
#include "Manipulator.h"

#define EPSILON_TCP 0.1
#define CNT_NUM_TCP 50
#define EPSILON_TCP_VEL 0.1

#define EPSILON_JOINT 0.1
#define CNT_NUM_JOINT 50
#define EPSILON_JOINT_VEL 0.1

Motion::Motion()
{
	initParams();
}

void Motion::MOV_TCP(Manipulator* arm, Transform& movT, float t)
{
	// movT: traget transformation matrix of TCP
	// t: moving time
	arm->tarTCP_T = movT;
	arm->tarTCP   = arm->kin.Transform2Vector6f(arm->tarTCP_T);

	// cubic parameter calculation
	tcpCubic(arm, arm->tarTCP, t);

	arm->planner_mode = Cubic_TCP_Timer;
	arm->control_mode = Cartesian_Mode;
	arm->timer_cnt = 0;
	arm->is_busy = true;

	int total_cnt = static_cast<int> (t / SERVOLOOP_TIME);
	while(1)
		if (arm->timer_cnt >= total_cnt)
		{
			arm->is_busy = false;
			break;
		}
}

void Motion::MOV_TCP(Manipulator* arm, Transform& movT)
{
	// movT: traget transformation matrix of TCP
	arm->tarTCP_T = movT;
	arm->tarTCP = arm->kin.Transform2Vector6f(arm->tarTCP_T);

	arm->planner_mode = OTG_TCP_Timer;
	arm->control_mode = Cartesian_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errTCP.norm() < EPSILON_TCP || arm->velTCP.norm() < EPSILON_TCP_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_TCP)
		{
			arm->is_busy = false;
			break;
		}
	}
}

void Motion::MOV_TCP_RAPID(Manipulator* arm, Transform& movT)
{
	// movT: traget transformation matrix of TCP
	arm->tarTCP_T = movT;
	arm->tarTCP   = arm->kin.Transform2Vector6f(arm->tarTCP_T);
	arm->plnTCP   = arm->tarTCP;

	arm->planner_mode = Planner_Idle;
	arm->control_mode = Cartesian_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errTCP.norm() < EPSILON_TCP || arm->velTCP.norm() < EPSILON_TCP_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_TCP)
		{
			arm->is_busy = false;
			break;
		}
	}

}

void Motion::MOV_JOINT(Manipulator* arm, float q, int n, float t)
{
	// q: angle, n: n-th joint, t: moving time
	arm->tarJoint = arm->curJoint;
	arm->tarJoint(n) = q;
	
	// cubic parameters  calculation
	jointCubic(arm, arm->tarJoint, t);

	arm->planner_mode = Cubic_Joint_Timer;
	arm->control_mode = Joint_Mode;
	arm->timer_cnt = 0;
	arm->is_busy = true;

	int total_cnt = static_cast<int> (t / SERVOLOOP_TIME);
	while (1)
		if (arm->timer_cnt >= total_cnt)
		{
			arm->is_busy = false;
			break;
		}
}

void Motion::MOV_JOINT(Manipulator* arm, Vectornf vec_q, float t)
{
	// vec_q: target angle, t: moving time
	arm->tarJoint = vec_q;

	// cubic parameters calculation
	jointCubic(arm, arm->tarJoint, t);

	arm->planner_mode = Cubic_Joint_Timer;
	arm->control_mode = Joint_Mode;
	arm->timer_cnt = 0;
	arm->is_busy = true;
	
	int total_cnt = static_cast<int> (t / SERVOLOOP_TIME);
	while (1)
		if (arm->timer_cnt >= total_cnt)
		{
			arm->is_busy = false;
			break;
		}
}

void Motion::MOV_JOINT(Manipulator* arm, float q, int n)
{
	arm->tarJoint = arm->curJoint;
	arm->tarJoint(n) = q;

	arm->planner_mode = OTG_Joint_Timer;
	arm->control_mode = Joint_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errJoint.norm() < EPSILON_JOINT || arm->velJoint.norm() < EPSILON_JOINT_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_JOINT)
		{
			arm->is_busy = false;
			break;
		}
	}
}

void Motion::MOV_JOINT(Manipulator* arm, Vectornf vec_q)
{
	// target joint position: vec_q
	arm->tarJoint = vec_q;

	arm->planner_mode = OTG_Joint_Timer;
	arm->control_mode = Joint_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errJoint.norm() < EPSILON_JOINT || arm->velJoint.norm() < EPSILON_JOINT_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_JOINT)
		{
			arm->is_busy = false;
			break;
		}
	}
}

void Motion::MOV_JOINT_RAPID(Manipulator* arm, float q, int n)
{
	arm->tarJoint = arm->curJoint;
	arm->tarJoint(n) = q;
	arm->plnJoint = arm->tarJoint;

	arm->planner_mode = Planner_Idle;
	arm->control_mode = Joint_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errJoint.norm() < EPSILON_JOINT || arm->velJoint.norm() < EPSILON_JOINT_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_JOINT)
		{
			arm->is_busy = false;
			break;
		}
	}
}

void Motion::MOV_JOINT_RAPID(Manipulator* arm, Vectornf vec_q)
{
	arm->tarJoint = vec_q;
	arm->plnJoint = arm->tarJoint;

	arm->planner_mode = Planner_Idle;
	arm->control_mode = Joint_Mode;
	arm->static_cnt = 0;
	arm->is_busy = true;

	while (1)
	{
		if (arm->errJoint.norm() < EPSILON_JOINT || arm->velJoint.norm() < EPSILON_JOINT_VEL)
			arm->static_cnt++;
		if (arm->static_cnt >= CNT_NUM_JOINT)
		{
			arm->is_busy = false;
			break;
		}
	}
}

void Motion::FREE_MODE(Manipulator* arm)
{
	arm->planner_mode = Planner_Idle;
	arm->control_mode = Free_Mode;
}

void Motion::cubicTCP_timer(Manipulator* arm)
{
	// determine the target tcp position according to the time index
	// output: planned tcp position
	int i;
	for (i = 0; i < 6; i++)
	{
		CubicInt& cub = arm->mtn->tcpParam[i];
		arm->plnTCP(i) = cub.x(static_cast<float> (arm->timer_cnt*SERVOLOOP_TIME));
	}

	arm->timer_cnt++;
}

void Motion::cubicJoint_timer(Manipulator* arm)
{
	// determine the target joint position according to the time index
	// planned joint position

	int i;
	for (i = 0; i < ARM_DOF; i++)
	{
		CubicInt& cub = arm->mtn->jointParam[i];
		arm->plnJoint(i) = cub.x(static_cast<float> (arm->timer_cnt*SERVOLOOP_TIME));
	}

	arm->timer_cnt++;
}

void Motion::otgTCP_timer(Manipulator* arm)
{
	// input:  velTcp
	// output: plnTCP

	int i;
	float velPln;
	float T = SERVOLOOP_TIME;
	for (i = 0; i < ARM_DOF; i++)
	{
		float v  = arm->velTCP(i);
		float S  = arm->errTCP(i);
		float dS = S / T;
		
		if (dS >= 0)
			velPln = minVel(dS, v + amaxTCP(i)*T, vmaxTCP(i), sqrt(2 * amaxTCP(i)*S));
		else
			velPln = -1 * minVel(-dS, -v - amaxTCP(i)*T, -vmaxTCP(i), -sqrt(2 * amaxTCP(i)*S));
		arm->plnTCP(i) = velPln;
	}

}

void Motion::otgJoint_timer(Manipulator* arm)
{
	// input:  velJoint
	// output: q0
	int i;
	float velPln;
	float T = SERVOLOOP_TIME;
	for(i = 0; i < ARM_DOF; i++)
	{
		float v  = arm->velJoint(i);
		float S  = arm->errJoint(i);
		float dS = S / T;

		if (dS >= 0)
			velPln = minVel(dS, v + amaxJoint(i)*T, vmaxJoint(i), sqrt(2*amaxJoint(i)*S));
		else
			velPln = -1 * minVel(-dS, -v - amaxJoint(i)*T, -vmaxJoint(i), -sqrt(2*amaxJoint(i)*S));
		arm->plnJoint(i) = velPln;
	}

}

void Motion::tcpCubic(Manipulator* arm, Vector6f xf, float t)
{
	int i;
	for (i = 0; i < 6; i++)
		tcpParam[i].cal(arm->curTCP(i), xf(i), t);
}

void Motion::jointCubic(Manipulator* arm, Vectornf thf, float t)
{
	int i;
	for (i = 0; i < ARM_DOF; i++)
		jointParam[i].cal(arm->curJoint(i), thf(i), t);
}

float Motion::minVel(float v1, float v2, float v3, float v4)
{
	float min = v1;
	if (min > v2)
		min = v2;
	if (min > v3)
		min = v3;
	if (min > v4)
		min = v4;
	return min;
}

void Motion::initParams()
{
	amaxTCP[0] = 1;
	amaxTCP[1] = 1;
	amaxTCP[2] = 1;
	amaxTCP[3] = 1;
	amaxTCP[4] = 1;
	amaxTCP[5] = 1;
	amaxTCP[6] = 1;

	vmaxTCP[0] = 0.5;
	vmaxTCP[1] = 0.5;
	vmaxTCP[2] = 0.5;
	vmaxTCP[3] = 0.5;
	vmaxTCP[4] = 0.5;
	vmaxTCP[5] = 0.5;
	vmaxTCP[6] = 0.5;

	amaxJoint[0] = 1;
	amaxJoint[1] = 1;
	amaxJoint[2] = 1;
	amaxJoint[3] = 1;
	amaxJoint[4] = 1;
	amaxJoint[5] = 1;
	amaxJoint[6] = 1;

	vmaxJoint[0] = 0.5;
	vmaxJoint[1] = 0.5;
	vmaxJoint[2] = 0.5;
	vmaxJoint[3] = 0.5;
	vmaxJoint[4] = 0.5;
	vmaxJoint[5] = 0.5;
	vmaxJoint[6] = 0.5;
}