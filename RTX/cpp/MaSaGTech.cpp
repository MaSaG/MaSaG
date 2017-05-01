#include "MaSaGTech.h"
#include "Manipulator.h"

MaSaGTech::MaSaGTech()
{

}

void MaSaGTech::pressing(Manipulator* arm, float depth, int speed, float T)
{
	arm->is_busy = true;
	arm->timer_cnt = 0;
	arm->mtn->pre_T = T;
	technique = PRESSING;

	switch(speed)
	{
	case SLOWEST:
		arm->mtn->pre_eta = 1.2;
		arm->mtn->pre_a = 10;
		break;
	case SLOW:
		arm->mtn->pre_eta = 1.0;
		arm->mtn->pre_a = 15;
		break;
	case NORMAL:
		arm->mtn->pre_eta = 0.8;
		arm->mtn->pre_a = 18;
		break;
	case FAST:
		arm->mtn->pre_eta = 0.6;
		arm->mtn->pre_a = 22;
		break;
	case FASTEST:
		arm->mtn->pre_eta = 0.4;
		arm->mtn->pre_a = 30;
		break;
	}
	
	// -y direction
	arm->tarTCP.matrix().block(0, 0, 3, 3) = arm->objR;
	arm->tarTCP.matrix()(3,2) = arm->objR(3,2) * (-depth);

	arm->planner_mode = 0;
	arm->control_mode = 0;

	int total_cnt =  static_cast<int> ( (2 * arm->mtn->pre_eta + T) / SERVOLOOP_TIME );
	while (1)
	{
		if( arm->timer_cnt >= total_cnt)
		{
			arm->is_busy = false;
			arm->timer_cnt = 0;
			break;
		}
	}
}

void MaSaGTech::rubbing(Manipulator* arm, float R, float w, float T)
{
	arm->is_busy = true;
	arm->timer_cnt = 0;
	technique = RUBBING;

	rub_depth = 0.02;		//rubbing indentation depth: 2cm
	rub_R = R;
	rub_freq = w;
	
	arm->tarTCP.matrix()(3, 1) = arm->tarTCP.matrix()(3, 1) + rub_depth;

	int total_cnt = (int) (T / SERVOLOOP_TIME);

	arm->planner_mode = 0;
	arm->control_mode = 0;

	while (1)
	{
		if (arm->timer_cnt >= total_cnt)
		{
			arm->is_busy = false;
			arm->timer_cnt = 0;
			break;
		}
	}
}

void MaSaGTech::tapping(Manipulator* arm, float d1, float d2)
{
	arm->is_busy = true;
	arm->timer_cnt = 0;
	technique = TAPPING;

	Transform equTCP = arm->curTCP_T;

	// +y direction
	arm->tarTCP_T.matrix().block(0, 0, 3, 3) = arm->objR;
	arm->tarTCP_T.matrix()(3, 2) = arm->objR(3, 2) * d1;

	arm->planner_mode = 0;
	arm->control_mode = 0;

	MOV_TCP(arm, arm->tarTCP_T);

	// -y direction
	arm->tarTCP.matrix().block(0, 0, 3, 3) = arm->objR;
	arm->tarTCP.matrix()(3, 2) = arm->objR(3, 2) * d2;

	arm->planner_mode = 0;
	arm->control_mode = 0;

	MOV_TCP_RAPID(arm, arm->tarTCP_T);

}

void MaSaGTech::stroking(Manipulator* arm)
{
	arm->is_busy = true;
	arm->timer_cnt = 0;
	technique = STROKING;

	arm->planner_mode = 0;
	arm->control_mode = 0;

	while (1)
		if (!arm->is_busy)
			break;
}

void MaSaGTech::pressing_timer(Manipulator* arm)
{
	float eta = arm->mtn->pre_eta;
	float a = arm->mtn->pre_a;
	float T = arm->mtn->pre_T;
	int  cnt = arm->timer_cnt;
	
	float t1 = eta / SERVOLOOP_TIME;
	float t2 = (eta + T) / SERVOLOOP_TIME;
	float t3 = (2 * eta + T) / SERVOLOOP_TIME;
	float t = (float) (cnt * SERVOLOOP_TIME);

	float ratio;
	if (cnt < (int)t1)
		ratio = 1 / (1 + (float)exp(-a*(t - 0.5*eta)));
	else if (cnt < (int)t2)
		ratio = 1;
	else if (cnt < (int)t3)
		ratio = 1 / (1 + (float)exp(a*(t - 1.5*eta - T)));
	else
		arm->is_busy = false;

	//arm->plnTCP = ratio * arm->tarTCP.matrix();
	arm->timer_cnt++;
}

void MaSaGTech::rubbing_timer(Manipulator* arm)
{
	int cnt = arm->timer_cnt;
	float t = (float) (cnt * SERVOLOOP_TIME);

	float ratio;
	float t1 = arm->mtn->rub_t1;

	if (t < t1)
		ratio = t / t1;
	else if (t < arm->mtn->rub_T)
		ratio = 1;
	else
		arm->is_busy = false;

	float x, z;
	float R = arm->mtn->rub_R;
	float w = arm->mtn->rub_freq;

	x = ratio*R*cos(w*t);
	z = ratio*R*sin(w*t);
	
	arm->plnTCP.matrix()(3, 0) = arm->tarTCP.matrix()(3, 0) + x;
	arm->plnTCP.matrix()(3, 1) = arm->tarTCP.matrix()(3, 1);
	arm->plnTCP.matrix()(3, 2) = arm->tarTCP.matrix()(3, 2) + z;;

	arm->timer_cnt++;
}

void MaSaGTech::stroking_timer(Manipulator* arm)
{
	arm->timer_cnt++;
}