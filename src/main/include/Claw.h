#pragma once

#include <iostream>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/XboxController.h>

#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SmartDashboard.h"

#define servoOpen          90
#define servoClosed        125
#define servoInverseClosed 30 // IT WORKS
// #define CONFIG_1
#define CONFIG_2

using namespace frc;

class Claw {
    public:

        Claw(int clawTalon, int clawServo);
        Claw(WPI_TalonSRX *clawTalon, Servo *clawServo);

        void Tick(XboxController *xbox);
        void OpenServo();
        void CloseServo();
        void InverseCloseServo();
        void RetrieveBall();
        void EjectBall();
        void printVoltage();

    private:
        WPI_TalonSRX *m_clawMotor;
        Servo *m_clawServo;
};
