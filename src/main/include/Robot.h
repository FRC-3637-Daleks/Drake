#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "rev/CANSparkMax.h"
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/Servo.h>
#include <frc/AnalogPotentiometer.h>

using namespace rev;
using namespace frc;

class Robot : public TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  
  enum Joysticks {LEFT_JOYSTICK = 0, RIGHT_JOYSTICK, XBOX_CONTROLLER};

  Joystick *leftDohickey, *rightDohickey; 
  XboxController *ps4;
  CANSparkMax *shoulderMotor, *eblowMotor;
  WPI_TalonSRX *clawMotor, *turretMotor	;
  CANEncoder *shouldMotorEncoder, *elbowMotorEncoder;
  Arm *arm;
  Claw *claw;
  Servo *clawServo
  Potentiometer *turretPot; //Setup to roboRio analog input 0
  AnalogInput *turretPotInput, *ballLimit;

  #define armBaseHeight = 343;
  #define armBaseFrontX  = 445;
  #define armBaseSideX = 358;
  #define clawLenght = 165;
  #define maxLowArmAngle = 150;
  #define minLowArmAngle = 70;
  #define lowArmLength = 813;
  #define highArmLength = 1016;
  #define cargoDiskHeight = 381;
  #define cargoBallHeight = 1219;
  #define rocketDiskLowHeight = 483;
  #define rocketBallLowHeight = 699;
  #define rocketDiskMiddleHeight = 1194;
  #define rocketBallMiddleHeight = 1410;
  #define rocketDiskTopHeight = 1905;
  #define rocketBallTopHeight = 2121;
  //#define ballPickUpX = 279;
  //#define ballPickUpY = 165;
  #define discLoadHeight = 381;

  //CANDigitalInput *forwardLimitSwitch, *reverseLimitSwitch;
  //Servo *servo1;


 private:
  SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};