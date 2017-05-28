#ifndef _MOTORPARAM_H_
#define _MOTORPARAM_H_

//各軸馬達所需參數 (依序為  U16_T Index, U8_T SubIndex, U8_T LenOfByte, I32_T Value)

// Left 0: MAXPOS + RE40 (PP mode)
const int PARAM_L0[][4] =
{
	{ 0x6060, 0x00, 1, 1 },					//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 },		//Max Position Limit
	{ 0x607F, 0x00, 4, 6940 },				//Max Profile Velocity
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x60C5, 0x00, 4, 5000 }				//Max Acceleration
};

// Left 1: EPOS3 + RE50 (CST mode)
const int PARAM_L1[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x6410, 0x01, 2, 10000 },				//Nominal Current
	{ 0x6410, 0x06, 4, 38500 },				//Motor Torque Constant
	{ 0x6410, 0x04, 4, 9500 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x60F6, 0x01, 4, 121 },				//P (auto tune後結果)
	{ 0x60F6, 0x02, 4, 28 },				//I (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }			//Max Position Limit
};

// Left 2:  MAXPOS + RE40 (CST mode)
const int PARAM_L2[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }		//Max Position Limit
};

// Left 3: MAXPOS + RE40 (CST mode)
const int PARAM_L3[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }		//Max Position Limit
};

// Left 4: MAXPOS + RE40 (CST mode)
const int PARAM_L4[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }		//Max Position Limit
};

// Left 5: mcDSA-E65 + RE25 (PT mode)
const int PARAM_L5[][4] =
{
	{ 0x6040, 0x00, 2, 0x07 },				//ControlWord_1
	{ 0x6040, 0x00, 2, 0x8F },				//ControlWord_2
	{ 0x2011, 0x03, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_1
	{ 0x2011, 0x06, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_2
	{ 0x6402, 0x00, 2, 0x8000 },			//MotorType
	{ 0x3910, 0x00, 1, 2 },					//MOTOR_Microsteps
	{ 0x3911, 0x00, 2, 0 },					//MOTOR_Polarity
	{ 0x3350, 0x00, 4, 0x96A },				//VEL_Feedback
	{ 0x3550, 0x00, 4, 0x96A },				//SVEL_Feedback
	{ 0x3962, 0x00, 2, 4096 },				//Encoder resolution in counts
	{ 0x3830, 0x00, 4, 50000 },				//PWM_Frequency
	{ 0x3830, 0x01, 1, 1 },					//PWM_Mode
	{ 0x3901, 0x00, 2, 14000 },				//Motor rated revolutions 
	{ 0x3902, 0x00, 2, 24000 },				//Motor rated voltage
	{ 0x3210, 0x00, 2, 60 },				//PI-Current controller - proportional factor
	{ 0x3211, 0x00, 2, 74 },				//PI-Current controller - integral factor
	{ 0x3221, 0x00, 4, 5000 },				//Current limit - max. positive
	{ 0x3223, 0x00, 4, 5000 },				//Current limit - max. negative
	{ 0x3224, 0x00, 1, 1 },					//Dynamic current limit I*t - mode
	{ 0x3224, 0x01, 4, 4500 },				//Dynamic current limit I*t - peak current
	{ 0x3224, 0x02, 4, 1500 },				//Dynamic current limit I*t - continues current
	{ 0x3224, 0x03, 2, 200 },				//Dynamic current limit I*t - time
	{ 0x6060, 0x00, 1, 4 },					//Modes of operation //4: Torque profile mode (tq)
	{ 0x6075, 0x00, 4, 1500 },				//Motor rated current
	{ 0x6072, 0x00, 2, 1000 },				//Maximal torque
	{ 0x608A, 0x00, 1, 0xAC },				//Position dimension index
	{ 0x6065, 0x00, 4, 10000 },				//Following error window
	{ 0x6071, 0x00, 2, 0}					//Target Torque
};

// Left 6: mcDSA-E65 + RE25 (PT mode)
const int PARAM_L6[][4] =
{
	{ 0x6040, 0x00, 2, 0x07 },				//ControlWord_1
	{ 0x6040, 0x00, 2, 0x8F },				//ControlWord_2
	{ 0x2011, 0x03, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_1
	{ 0x2011, 0x06, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_2
	{ 0x6402, 0x00, 2, 0x8000 },			//MotorType
	{ 0x3910, 0x00, 1, 2 },					//MOTOR_Microsteps
	{ 0x3911, 0x00, 2, 0 },					//MOTOR_Polarity
	{ 0x3350, 0x00, 4, 0x96A },				//VEL_Feedback
	{ 0x3550, 0x00, 4, 0x96A },				//SVEL_Feedback
	{ 0x3962, 0x00, 2, 4096 },				//Encoder resolution in counts
	{ 0x3830, 0x00, 4, 50000 },				//PWM_Frequency
	{ 0x3830, 0x01, 1, 1 },					//PWM_Mode
	{ 0x3901, 0x00, 2, 14000 },				//Motor rated revolutions 
	{ 0x3902, 0x00, 2, 24000 },				//Motor rated voltage
	{ 0x3210, 0x00, 2, 60 },				//PI-Current controller - proportional factor
	{ 0x3211, 0x00, 2, 74 },				//PI-Current controller - integral factor
	{ 0x3221, 0x00, 4, 5000 },				//Current limit - max. positive
	{ 0x3223, 0x00, 4, 5000 },				//Current limit - max. negative
	{ 0x3224, 0x00, 1, 1 },					//Dynamic current limit I*t - mode
	{ 0x3224, 0x01, 4, 4500 },				//Dynamic current limit I*t - peak current
	{ 0x3224, 0x02, 4, 1500 },				//Dynamic current limit I*t - continues current
	{ 0x3224, 0x03, 2, 200 },				//Dynamic current limit I*t - time
	{ 0x6060, 0x00, 1, 4 },					//Modes of operation //4: Torque profile mode (tq)
	{ 0x6075, 0x00, 4, 1500 },				//Motor rated current
	{ 0x6072, 0x00, 2, 1000 },				//Maximal torque
	{ 0x608A, 0x00, 1, 0xAC },				//Position dimension index
	{ 0x6065, 0x00, 4, 10000 },				//Following error window
	{ 0x6071, 0x00, 2, 0}					//Target Torque
};

//-----------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------//

// Right 0: MAXPOS + RE40 (PP mode)
const int PARAM_R0[][4] =
{ 
	{ 0x6060, 0x00, 1, 1 },					//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 },		//Max Position Limit
	{ 0x607F, 0x00, 4, 6940 },				//Max Profile Velocity
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x60C5, 0x00, 4, 5000 }				//Max Acceleration
};

// Right 1: EPOS3 + RE50 (CST mode)
const int PARAM_R1[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x6410, 0x01, 2, 10000 },				//Nominal Current
	{ 0x6410, 0x06, 4, 38500 },				//Motor Torque Constant
	{ 0x6410, 0x04, 4, 9500 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x60F6, 0x01, 4, 121 },				//P (auto tune後結果)
	{ 0x60F6, 0x02, 4, 28 },				//I (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }			//Max Position Limit
};

// Right 2:  MAXPOS + RE40 (CST mode)
const int PARAM_R2[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }			//Max Position Limit
};

// Right 3: MAXPOS + RE40 (CST mode)
const int PARAM_R3[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }			//Max Position Limit
};

// Right 4: MAXPOS + RE40 (CST mode)
const int PARAM_R4[][4] =
{
	{ 0x6060, 0x00, 1, 10 },				//Modes of operation //10:Cyclic Synchronous Torque Mode (cst) //1: Profile position mode (pp)
	{ 0x3001, 0x01, 2, 5000 },				//Nominal Current
	{ 0x3001, 0x05, 4, 30200 },				//Motor Torque Constant
	{ 0x6080, 0x00, 4, 12000 },				//Max Motor Speed
	{ 0x6085, 0x00, 4, 1500 },				//Quick Stop Deceleration
	{ 0x6084, 0x00, 4, 1000 },				//Profile Deceleration
	{ 0x30A0, 0x01, 4, 145368 },			//P (auto tune後結果)
	{ 0x30A0, 0x02, 4, 2437 },				//I (auto tune後結果)
	{ 0x30A0, 0x03, 4, 28573 },				//FF (auto tune後結果)
	{ 0x607D, 0x01, 4, -2147483647 },		//Min Position Limit
	{ 0x607D, 0x02, 4, 2147483647 }			//Max Position Limit
};

// Right 5: mcDSA-E65 + RE25 (PT mode)
const int PARAM_R5[][4] =
{
	{ 0x6040, 0x00, 2, 0x07 },				//ControlWord_1
	{ 0x6040, 0x00, 2, 0x8F },				//ControlWord_2
	{ 0x2011, 0x03, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_1
	{ 0x2011, 0x06, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_2
	{ 0x6402, 0x00, 2, 0x8000 },			//MotorType
	{ 0x3910, 0x00, 1, 2 },					//MOTOR_Microsteps
	{ 0x3911, 0x00, 2, 0 },					//MOTOR_Polarity
	{ 0x3350, 0x00, 4, 0x96A },				//VEL_Feedback
	{ 0x3550, 0x00, 4, 0x96A },				//SVEL_Feedback
	{ 0x3962, 0x00, 2, 4096 },				//Encoder resolution in counts
	{ 0x3830, 0x00, 4, 50000 },				//PWM_Frequency
	{ 0x3830, 0x01, 1, 1 },					//PWM_Mode
	{ 0x3901, 0x00, 2, 14000 },				//Motor rated revolutions 
	{ 0x3902, 0x00, 2, 24000 },				//Motor rated voltage
	{ 0x3210, 0x00, 2, 60 },				//PI-Current controller - proportional factor
	{ 0x3211, 0x00, 2, 74 },				//PI-Current controller - integral factor
	{ 0x3221, 0x00, 4, 5000 },				//Current limit - max. positive
	{ 0x3223, 0x00, 4, 5000 },				//Current limit - max. negative
	{ 0x3224, 0x00, 1, 1 },					//Dynamic current limit I*t - mode
	{ 0x3224, 0x01, 4, 4500 },				//Dynamic current limit I*t - peak current
	{ 0x3224, 0x02, 4, 1500 },				//Dynamic current limit I*t - continues current
	{ 0x3224, 0x03, 2, 200 },				//Dynamic current limit I*t - time
	{ 0x6060, 0x00, 1, 4 },					//Modes of operation //4: Torque profile mode (tq)
	{ 0x6075, 0x00, 4, 1500 },				//Motor rated current
	{ 0x6072, 0x00, 2, 1000 },				//Maximal torque
	{ 0x608A, 0x00, 1, 0xAC },				//Position dimension index
	{ 0x6065, 0x00, 4, 10000 },				//Following error window
	{ 0x6071, 0x00, 2, 0 }					//Target Torque
};

// Right 6: mcDSA-E65 + RE25 (PT mode)
const int PARAM_R6[][4] =
{
	{ 0x6040, 0x00, 2, 0x07 },				//ControlWord_1
	{ 0x6040, 0x00, 2, 0x8F },				//ControlWord_2
	{ 0x2011, 0x03, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_1
	{ 0x2011, 0x06, 4, 0x64616F6C },		//RestoreDefaultParameters_Application_2
	{ 0x6402, 0x00, 2, 0x8000 },			//MotorType
	{ 0x3910, 0x00, 1, 2 },					//MOTOR_Microsteps
	{ 0x3911, 0x00, 2, 0 },					//MOTOR_Polarity
	{ 0x3350, 0x00, 4, 0x96A },				//VEL_Feedback
	{ 0x3550, 0x00, 4, 0x96A },				//SVEL_Feedback
	{ 0x3962, 0x00, 2, 4096 },				//Encoder resolution in counts
	{ 0x3830, 0x00, 4, 50000 },				//PWM_Frequency
	{ 0x3830, 0x01, 1, 1 },					//PWM_Mode
	{ 0x3901, 0x00, 2, 14000 },				//Motor rated revolutions 
	{ 0x3902, 0x00, 2, 24000 },				//Motor rated voltage
	{ 0x3210, 0x00, 2, 60 },				//PI-Current controller - proportional factor
	{ 0x3211, 0x00, 2, 74 },				//PI-Current controller - integral factor
	{ 0x3221, 0x00, 4, 5000 },				//Current limit - max. positive
	{ 0x3223, 0x00, 4, 5000 },				//Current limit - max. negative
	{ 0x3224, 0x00, 1, 1 },					//Dynamic current limit I*t - mode
	{ 0x3224, 0x01, 4, 4500 },				//Dynamic current limit I*t - peak current
	{ 0x3224, 0x02, 4, 1500 },				//Dynamic current limit I*t - continues current
	{ 0x3224, 0x03, 2, 200 },				//Dynamic current limit I*t - time
	{ 0x6060, 0x00, 1, 4 },					//Modes of operation //4: Torque profile mode (tq)
	{ 0x6075, 0x00, 4, 1500 },				//Motor rated current
	{ 0x6072, 0x00, 2, 1000 },				//Maximal torque
	{ 0x608A, 0x00, 1, 0xAC },				//Position dimension index
	{ 0x6065, 0x00, 4, 10000 },				//Following error window
	{ 0x6071, 0x00, 2, 0}					//Target Torque
};



#endif

