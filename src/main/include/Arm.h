#pragma once
#include "Robot.h";

#define M_PI  3.14159265358979323846;

class Arm {
public:

Arm(CANSparkMax *shoulderMotor, CANSparkMax *eblowMotor, WPI_TalonSRX *turretMotor, float armCamera);

void ArmAngles(float x, float y);
void ArmMinMax(int min, int max);


}

