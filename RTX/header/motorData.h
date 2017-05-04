#pragma once

#define mPI 3.14159

struct MotorDATA {      // ���F���򥻰Ѽ�  �j�������Ojoint space�|�Ψ�A�u��nominal torque�|�b�p��output_torque_factor�Ψ�A�ҥH�٬O�O�d�b�o��
	float rated_torque; // nominal torque (max. continuous torque)
	float R;			// terminal resistor [Ohm]
	float Km;			// torque constant [Nm/A]
	float Kb;			// back EMF coefficient [V/(rad/s)]
	float Im;			// rotor inertia [kg*cm^2]
	float Cm;			// viscosity coefficient of the system load
};

const MotorDATA mDATA[7] =   //�C�����F���򥻰Ѽ�(nominal torque,R,Km,Kb,Im,Cm)
{
	{ 0.177,  0.299, 0.0302, 60 / (317 * mPI), 0.142,  0.0258131 },
	{ 0.405,  0.103, 0.0385, 60 / (248 * mPI), 0.536,  0.1251700969 },
	{ 0.177,  0.299, 0.0302, 60 / (317 * mPI), 0.142,  0.0258131 },
	{ 0.177,  0.299, 0.0302, 60 / (317 * mPI), 0.142,  0.0258131 },
	{ 0.177,  0.299, 0.0302, 60 / (317 * mPI), 0.142,  0.0258131 },
	{ 0.0304,  1.53, 0.0208, 60 / (460 * mPI), 0.0147, 0.0258131 },
	{ 0.0304,  1.53, 0.0208, 60 / (460 * mPI), 0.0147, 0.0258131 }
};
