#pragma once

// claw servo position must be public or have a public get function

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/buttons/POVButton.h>
#include <frc/XboxController.h>

#include <frc/Joystick.h>

#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SmartDashBoard.h"

using namespace rev;
using namespace std;

// in millimeters (check these)
#define armBaseHeight             343
#define armBaseFrontX             445
#define armBaseSideX              358
#define clawLength                165
#define maxLowArmAngle            150
#define minLowArmAngle            70
#define lowArmLength              813
#define highArmLength             1092
#define defaultX                  470                    // i made this up
#define cargoHatchHeight          381          // 1
#define cargoBallHeight           1219         // 2
#define cargoBallLength           750                    // i made this up
#define rocketHatchLowHeight      495  // check   3
#define rocketBallLowHeight       683//           4
#define rocketHatchMiddleHeight   1168//          (5) 1193.8mm
#define rocketBallMiddleHeight    1422//          6
#define rocketHatchTopHeight      1867//          7
#define rocketBallTopHeight       2083//          8
#define ballPickUpX               279 //guess     9
#define ballPickUpY               165 //guess
#define discLoadHeight            381//          10      not used for controls
#define ballLoadHeight            0 //unknown    11      WRITE THIS ONE
#define sensorFrontToBack         406.4

enum POVButtons {R, T, L, B};

using namespace frc;

class Arm {
  public:
    float shoulderAngle, elbowAngle, curX, curY;
    bool turretReset;

    Arm(int shoulderMotor, int elbowMotor, int turretMotor, int shoulderPot);
    Arm(CANSparkMax *shoulderMotor, WPI_TalonSRX *elbowMotor, 
          WPI_TalonSRX *turretMotor, AnalogPotentiometer *shoulderPot);

    void Tick(XboxController *xbox, POVButton *dPad[4]);
    void moveToPosition(float x, float y);
    void printInfo();
  
  private:
    CANSparkMax *m_shoulderMotor;
    CANEncoder *m_shoulderMotorEncoder;
    WPI_TalonSRX *m_elbowMotor, *m_turretMotor;
    AnalogPotentiometer *m_shoulderPot;
    PIDController *m_shoulderController;

    void SetMotors();
    void ArmInit();
    bool validElbowPosition(double pos);
    double computeElbowPosition(double angle);
    bool validShoulderPosition(double pos);
    double computeShoulderPosition(double angle);
    bool FindArmAngles(float x, float y, float *ang1, float *ang2);
    // void FindArmMinMax(float base, float *elbowMin, float *elbowMax);
    float DeadZone(float input, float range);
    float ProximityDistance(int frontSensor, int rearSensor);
    float radiansToDegrees (float radians) ;
};

