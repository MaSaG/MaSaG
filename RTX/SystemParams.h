#ifndef SYSTEM_PARAMS
#define SYSTEM_PARAMS

#define SERVOLOOP_TIME 0.001 // unit : ms   (Set Servo Loop Interrupt time)

const int	resEncoder_ARM[7]   = {2000, 2000, 4096, 4096, 4096, 4096, 4096}; // 編碼器之值
const float gearRatio_ARM[7]    = {100.0, 100.0, 200.0, 193.75, 196.153846, 96.875, 196.774194};
const int	resEncoder_Head[2]  = {777, 777};
const int	gearRatio_Head[2]   = {99, 99};
const int	resEncoder_Torso[3] = {4096, 4096, 4096};
const int	gearRatio_Torso[3]  = {989, 989, 989};
const int	resEncoder_Wheel[4] = {4096, 4096, 4096, 4096};
const int	gearRatio_Wheel[4]  = {246, 246, 246, 246};

enum{ TYPE_MAXPOS, TYPE_EPOS3, TYPE_mcDSA_E65, TYPE_MCDC3006_CF};
enum{ PP_Mode, PV_Mode, PT_Mode, PVT_Mode, CSP_Mode, CSV_Mode, CST_Mode};

// CMD TABLE
enum{ READY_CMD,			// 0       
	  TEACH_CMD,			// 1
	  PLAY_CMD,				// 2
	  TEST3_CMD,			// 3
	  TEST4_CMD,			// 4
	  TEST5_CMD,			// 5
	  TEST6_CMD,			// 6
	  TEST7_CMD,			// 7
	  FREE_MODE_CMD,		// 8
	  MIRROR_CMD,			// 9
	  MIMMIC_CMD,			// 10
	  ALIGN_CMD,			// 11
	  TEST12_CMD,			// 12
	  TEST13_CMD,			// 13
	  TEST14_CMD,			// 14
	  TEST15_CMD,			// 15
	  TEST16_CMD,			// 16
	  TEST17_CMD,			// 17
	  SERVOON_CMD = 21,		// 21
	  SERVOOFF_CMD,			// 22
	  HOME_CMD,				// 23
	  FAULTRESET_CMD,		// 24
	  PRINT_CMD,			// 25
	  ESCAPE_CMD = 27		// 27
};	


const float PI  = 3.1415926f;
const float Mg1 = 39.2f;			// 2*9.8
const float Mg2 = 24.5f;			// 2*9.8
const float L1  = 0.13f;			// 臂長
const float L2  = 0.12f;			// 臂長


/* ****************************************************************************************************
to be checked, sy, 2016.12.5

*******************************************************************************************************/
/*

const float OUTPUT_TORQUE_FACTOR[2][6]=
{
	{	MAX_OUTPUT_VOLTAGE / M_DATA[0].nominal_torque / REDUCER50,
		MAX_OUTPUT_VOLTAGE / M_DATA[1].nominal_torque / REDUCER50 * (-1),
		MAX_OUTPUT_VOLTAGE / M_DATA[2].nominal_torque / REDUCER50,
		MAX_OUTPUT_VOLTAGE / M_DATA[3].nominal_torque / REDUCER50,
		MAX_OUTPUT_VOLTAGE / M_DATA[4].nominal_torque / REDUCER100,
		MAX_OUTPUT_VOLTAGE / M_DATA[5].nominal_torque / REDUCER100	      },

	{	MAX_OUTPUT_VOLTAGE / M_DATA[0].nominal_torque / REDUCER100,
		MAX_OUTPUT_VOLTAGE / M_DATA[1].nominal_torque / REDUCER100 * (-1),
		MAX_OUTPUT_VOLTAGE / M_DATA[2].nominal_torque / REDUCER100,
		MAX_OUTPUT_VOLTAGE / M_DATA[3].nominal_torque / REDUCER100,
		MAX_OUTPUT_VOLTAGE / M_DATA[4].nominal_torque / REDUCER100,
		MAX_OUTPUT_VOLTAGE / M_DATA[5].nominal_torque / REDUCER100	      }
};

const float ENC2RAD_FACTOR[2][6]=
{
	{	2*PI / encoder_res[0] / REDUCER50 * (-1),
		2*PI / encoder_res[1] / REDUCER50,
		2*PI / encoder_res[2] / REDUCER50 * (-1),
		2*PI / encoder_res[3] / REDUCER50 * (-1),
		2*PI / encoder_res[4] / REDUCER100,
		2*PI / encoder_res[5] / REDUCER100,			},
	
	{	2*PI / encoder_res[0] / REDUCER100 * (-1),
		2*PI / encoder_res[1] / REDUCER100,
		2*PI / encoder_res[2] / REDUCER100 * (-1),
		2*PI / encoder_res[3] / REDUCER100 * (-1),
		2*PI / encoder_res[4] / REDUCER100,
		2*PI / encoder_res[5] / REDUCER100,			}
};
*/


#endif