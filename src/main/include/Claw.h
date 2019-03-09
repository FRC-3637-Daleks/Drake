#pragma once

#include <iostream>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/XboxController.h>

#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SmartDashBoard.h"

#define servoOpen       90 
#define servoClosed     135
#define servoInverseClosed -45
#define CONFIG_1
#define CONFIG_2     //use one at a time 

using namespace frc;

class Claw {
    public:

        Claw(int clawTalon, int clawServo);
        Claw(WPI_TalonSRX *clawTalon, Servo *clawServo);

        void Tick(XboxController *xbox);
        void OpenServo();
        void CloseServo();
        void RetrieveBall();
        void EjectBall();
        void printVoltage();
        void InverseCloseServo();

    private:
        WPI_TalonSRX *m_clawMotor;
        Servo *m_clawServo;
};
