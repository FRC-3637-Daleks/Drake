#include "Robot.h"
#include "Arm.h"
#include "Claw.h"
#include <iostream>
#include <Math.h>

#include <frc/smartdashboard/SmartDashboard.h>

double newvar = 90;
bool checkersIsfun = false;

void Robot::RobotInit() {
  //servo1             = new Servo(SERVO_MOTOR);
  leftDohickey       = new Joystick(LEFT_JOYSTICK);
  rightDohickey      = new Joystick(RIGHT_JOYSTICK);
  ps4                = new XboxController(XBOX_CONTROLLER);
  nerfSparkyItsOP    = new CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushless);
  rawrXDTalon        = new WPI_TalonSRX(2);
  sparkEncoderboi    = new CANEncoder(*nerfSparkyItsOP);
  potInput           = new AnalogInput(THEBIGPOT);
  pot                = new AnalogPotentiometer(potInput, 360, 30);
  arm                = new Arm(shoulderMotor, eblowMotor, turretMotor, turretPot, ARM_CAMERA);
  claw               = new Claw(clawMotor, clawServo, ballLimit, CLAW_CAMERA);

)
  //forwardLimitSwitch = new CANDigitalInput(*nerfSparkyItsOP, CANDigitalInput::LimitSwitch::kForward, CANDigitalInput::LimitSwitchPolarity::kNormallyOpen);
  //reverseLimitSwitch = new CANDigitalInput(*nerfSparkyItsOP, CANDigitalInput::LimitSwitch::kReverse, CANDigitalInput::LimitSwitchPolarity::kNormallyOpen);
  // iSmokePot                = new AnalogPotentiometer(, 1.0, 0.0);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  // std::cout << nerfSparkyItsOP->GetFaults() << "\n";
  //std::cout << sparkEncoderboi->GetVelocity() << "velocity\n";
  //std::cout << sparkEncoderboi->GetPosition() << "position\n";

  // std::cout << leftDohickey->GetY();

  // #thecoschallenge

  /*if (checkersIsfun) {
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
    }
  }

  nerfSparkyItsOP->Set(.25 * newvar);
  */


  //std::cout << rightDohickey->GetButton(frc::Joystick::ButtonType::kTriggerButton) << "\n";
  nerfSparkyItsOP->Set(leftDohickey->GetY()*.2);
  //std::cout << nerfSparkyItsOP ->GetBusVoltage() << "\n";
  //std::cout << nerfSparkyItsOP ->GetOutputCurrent() << "hello\n";
  rawrXDTalon->Set(rightDohickey->GetY()*.5);
  std::cout << rawrXDTalon->GetOutputCurrent() << "boioiiii\n";
  //servo1->SetAngle(newvar);
  //std::cout<<servo1->GetAngle()<< "\n";

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif