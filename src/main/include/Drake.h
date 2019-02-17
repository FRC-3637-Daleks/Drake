#pragma once


#include <string>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include <frc/buttons/POVButton.h>
#include <frc/Servo.h>
#include <frc/AnalogPotentiometer.h>

#include "DalekDrive.h"
#include "Arm.h"
#include "Claw.h"

#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SmartDashBoard.h"

using namespace frc;
//using namespace rev;


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  enum CANIDs {LEFT_FRONT_MOTOR = 1, LEFT_REAR_MOTOR, RIGHT_FRONT_MOTOR, RIGHT_REAR_MOTOR, 
  SHOULDER_MOTOR, ELBOW_MOTOR, TURRET_MOTOR, CLAW_MOTOR};
  
  enum DIOS   {FRONT_LEFT_LIDAR = 0, FRONT_RIGHT_LIDAR, RIGHT_FRONT_LIDAR, RIGHT_REAR_LIDAR, 
  LEFT_FRONT_LIDAR_, LEFT_REAR_LIDAR};

 private:
  DalekDrive *m_drive;
  Arm *m_arm;
  Claw *m_claw;
  Joystick *m_leftStick;
  Joystick *m_rightStick;
  XboxController *m_xbox;
  POVButton *m_dPad[4];
};