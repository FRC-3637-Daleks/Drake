#pragma once

#include <iostream>
#include <Math.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/buttons/POVButton.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SmartDashBoard.h"

//millimeters 

#define armBaseHeight            343; //Base attchted from the robot
#define armBaseFrontX            445; //Disatnce from the center of the arm to front robot
#define armBaseSideX             358; // Distance from the center of the arm to side robot
#define clawLenght               165;
#define maxLowArmAngle           150; //Measuring for the oppsite side 110
#define minLowArmAngle            70; //Measuring for the oppsite side 30
#define lowArmLength              813
#define highArmLength             1016
#define defaultX                  190        
#define cargoHatchHeight          381          // 1
#define cargoBallHeight           1219         // 2
#define cargoBallLength           750                 
#define rocketHatchLowHeight      483  // check   3
#define rocketBallLowHeight       699//           4
#define rocketHatchMiddleHeight   1194//          5
#define rocketBallMiddleHeight    1410//          6
#define rocketHatchTopHeight      1905//          7
#define rocketBallTopHeight       2121//          8
#define ballPickUpX               279 //guess     9
#define ballPickUpY               165 //guess
#define discLoadHeight            381//          10      not used for controls
#define ballLoadHeight            0 //unknown    11      WRITE THIS ONE

using namespace rev;
using namespace frc;

//Plus Sign xbox Buttons
enum POVButtons {R, T, L, B};

class Arm {
  public:
    float shoulderAngle, elbowAngle, curX, curY;

    Arm(int shoulderMotor, int elbowMotor, int turretMotor, int shoulderPot);
    Arm(CANSparkMax *shoulderMotor, WPI_TalonSRX *elbowMotor, WPI_TalonSRX *turretMotor, Potentiometer *shoulderPot);

    void Tick(XboxController *xbox, POVButton *dPad[4]); 
    void moveToPosition(float x, float y);
    void printVoltage();
  
  private:
    CANSparkMax *m_shoulderMotor;
    CANEncoder *m_shoulderMotorEncoder;
    WPI_TalonSRX *m_elbowMotor, *m_turretMotor;
    //  *m_elbowPot, *m_turretPot; ->Working on this
    Potentiometer *m_shoulderPot;
 
    void SetMotors();
    bool FindArmAngles(float x, float y, float *ang1, float *ang2);
    void FindArmMinMax(float base, float *elbowMin, float *elbowMax);
};