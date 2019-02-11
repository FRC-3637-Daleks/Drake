#pragma once
#include "Robot.h";


class Arm {
public:

Arm(CANSparkMax *shoulderMotor, CANSparkMax *eblowMotor, WPI_TalonSRX *turretMotor, float  ARM_CAMERA);

void ArmAngles(float x, float y);


}
