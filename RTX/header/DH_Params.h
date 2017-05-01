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
	{      0,       0,  90, -90 },
	{      0,       0, -90,  90 },
	{  0.015, -0.3575,  90,  90 },
	{ -0.015,       0,  90,   0 },
	{      0,  0.2855,  90,   0 },
	{   0.14,       0,   0,  90 }
};
