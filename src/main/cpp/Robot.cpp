#include "Drake.h"
#include <iostream>

// #thecoschallenge

  /* if (checkersIsfun) {
    if (!leftDohickey->GetButton(frc::Joystick::ButtonType::kTriggerButton)) {
       checkersIsfun = false;
     }
  } else {
    if (leftDohickey->GetButton(frc::Joystick::ButtonType::kTriggerButton)) {
      checkersIsfun = true;
      if (newvar == (90)){
        newvar = 135;
      } else {
        newvar = (90);
      }
    }*/

void
Robot::RobotInit() 
{
    m_drive      = new DalekDrive(1, 2, 3, 4, DalekDrive::driveType::kMecanum);

    m_leftStick  = new frc::Joystick(1);
    m_rightStick = new frc::Joystick(2);
    m_xbox       = new frc::XboxController(3);

    //Plus Sign Button Objects-> parameter xbox, angle
    m_dPad[R]    = new frc::POVButton(*m_xbox, 0);
    m_dPad[T]    = new frc::POVButton(*m_xbox, 90);
    m_dPad[L]    = new frc::POVButton(*m_xbox, 180);
    m_dPad[B]    = new frc::POVButton(*m_xbox, 270);

    m_arm = new Arm(SHOULDER_MOTOR, ELBOW_MOTOR, TURRET_MOTOR, 0);
    m_claw = new Claw(CLAW_MOTOR, 0);

    //Grip to raspberry pi cam
    //CameraServer::GetInstance()->StartAutomaticCapture();
}

void
Robot::RobotPeriodic() 
{
}

void
Robot::AutonomousInit() 
{
}

void
Robot::AutonomousPeriodic()
{
}

void
Robot::TeleopInit() 
{
}

void
Robot::TeleopPeriodic()
{
    //Setting to Cartesian Drive, one joystick
    m_drive->Cartesian(*m_leftStick, 0.0);

    // claw periodic function
    m_claw->Tick(m_xbox);
    m_arm->Tick(m_xbox, m_dPad);

    //Motor Voltage values
    m_arm->printVoltage();
    m_claw->printVoltage();
}

void
Robot::TestPeriodic()
{
}

#ifndef RUNNING_FRC_TESTS
int
main() 
{ 
  return frc::StartRobot<Robot>();
}
#endif