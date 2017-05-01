#pragma once

#include "Motion.h"

enum {PRESSING = 101, RUBBING, TAPPING, STROKING};
enum {SLOWEST, SLOW, NORMAL, FAST, FASTEST};


class MaSaGTech : public Motion
{
public:
	MaSaGTech();

	void pressing(Manipulator* arm, float depth, int speed, float T);
	void rubbing (Manipulator* arm, float R, float w, float T);
	void tapping (Manipulator* arm, float d1, float d2);
	void stroking(Manipulator* arm);

	void pressing_timer(Manipulator* arm);
	void rubbing_timer (Manipulator* arm);
	void stroking_timer(Manipulator* arm);
	
	// determine which massage technique
	int  technique;

	// pressing parameters
	float pre_eta, pre_a, pre_T;
	// rubbing parameters
	float rub_depth, rub_R, rub_t1, rub_T, rub_freq;
};