#pragma once
#include "Robot.h";

#define servoOpen = 90; 
#define servoClosed = 135;

class Claw {
public:

Claw(WPI_TalonSRX *clawMotor, Servo *clawServo, AnalogInput *ballLimit, float clawCamera);

void OpenServo();
void ClosedServo();
void GetBall();
void EjectBall();

}


