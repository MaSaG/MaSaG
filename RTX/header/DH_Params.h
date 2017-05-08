#pragma once

struct DH_Params
{
	float a;
	float d;
	float al;
	float th;
};

const DH_Params dhParams[] =
{
	{      0,       0,  M_PI/2, -M_PI/2 },
	{      0,       0, -M_PI/2,  M_PI/2 },
	{  0.015, -0.3575,  M_PI/2,		0 },
	{ -0.015,       0,  M_PI/2,		0 },
	{      0,  0.2855,  M_PI/2,		0 },
	{   0.14,       0,		0,	M_PI/2 }
};
