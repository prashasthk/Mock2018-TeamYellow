/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoMoveForward.h"

AutoMoveForward::AutoMoveForward(double setpoint):
drivingPID(new WVPIDController(distKp, distKi, distKd, target, false)) {
  Requires(Robot::m_drive);
  target = setpoint;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoMoveForward::Initialize() {
Robot::m_drive->resetEncoders();
drivingPID->SetSetPoint(target);

}
// Called repeatedly when this Command is scheduled to run
void AutoMoveForward::Execute() {
power = drivingPID->Tick((Robot::m_drive->getLeftDistance() + Robot::m_drive->getRightDistance())/2);
Robot::m_drive->tankDrive(0.10 + power, 0.10 + power);
}
// Make this return true when this Command no longer needs to run execute()
bool AutoMoveForward::IsFinished() { 
if (fabs(drivingPID->GetError()) < 0.05) {
  return true;
}
else return false;
}
// Called once after isFinished returns true
void AutoMoveForward::End() {
Robot::m_drive->tankDrive(0,0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMoveForward::Interrupted() {}
