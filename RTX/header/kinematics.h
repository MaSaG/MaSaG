#pragma once
#include "Eigen/Dense"
#include "Eigen/Geometry"
#include "User_Data.h"
#include "DH_Params.h"

typedef Eigen::Transform<float, 3, Eigen::Affine> Transform;
typedef Eigen::Matrix<float, ARM_DOF, 1> Vectornf;
typedef Eigen::Matrix<  int, ARM_DOF, 1> Vectorni;
typedef Eigen::Matrix<float, 6,       1> Vector6f;
typedef Eigen::Matrix<float, 6, ARM_DOF> Matrix6nf;

class kinematics
{
public:
	Transform ForwardKinematics(Vectornf& q);
	Transform FK_MaSaG(Vectornf& q);
	void      updateJacobian(Vectornf& q, Matrix6nf& J);
	void	  InversKinematics();  
	Vector6f  Transform2Vector6f(Transform& t);
private:
	Transform transformDH(DH_Params dh, float th);
	void quaternion2euler(Eigen::Quaternionf& qu, Eigen::Vector3f& vec);
};

