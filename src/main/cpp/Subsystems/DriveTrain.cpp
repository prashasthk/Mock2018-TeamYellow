/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/DriveTrain.h"
#include "Commands/TankDrive.h"
#include "RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(2)), right(new TalonSRX(3)), gyro(new ADXRS450_Gyro())
 {
left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute,0,10);
left->SetSelectedSensorPosition(0,0,10);
right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute,0,10);
right->SetSelectedSensorPosition(0,0,10);
gyro->Reset();
}
void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new TankDrive());
}
void DriveTrain::gyroReset() {
	gyro->Reset();
}
void DriveTrain::tankDrive(double leftPow, double rightPow){
  left->Set(ControlMode::PercentOutput, leftPow);
  right->Set(ControlMode::PercentOutput, rightPow);
}
void DriveTrain::resetEncoders() {
  left->SetSelectedSensorPosition(0,0,10);
  right->SetSelectedSensorPosition(0,0,10);
}
double DriveTrain::getLeftDistance() {
  double absolutePosition = left->GetSensorCollection().GetQuadraturePosition();
  return absolutePosition;
}
double DriveTrain::getRightDistance() {
  double absolutePosition = -(right->GetSensorCollection().GetQuadraturePosition());
  return absolutePosition;
} 
// Put methods for controlling this subsystem
// here. Call these from Commands.
