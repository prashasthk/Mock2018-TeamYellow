/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoTurn.h"
#include "iostream"
using namespace std;

AutoTurn::AutoTurn(double angleInput):
anglePID(new WVPIDController(angleKp, angleKi, angleKd, setpoint, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	setpoint = angleInput;
	Requires(Robot::m_drive); 
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
Robot::m_drive->gyroReset();
anglePID->SetSetPoint(setpoint);
}
// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
	double angle = Robot::m_drive->getAngle();
	cout<< "Angle: " << angle << endl;
	power = 0.2 * anglePID->Tick(angle);
		if (setpoint < 0) {
			Robot::m_drive->tankDrive(0.2 + power, -0.2 - power);
		}
		else {
			Robot::m_drive->tankDrive(-0.2 - power, 0.2 + power);
		}
}
// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() { 
	if (fabs(anglePID->GetError()) < 1) {
  		return true;
	}
	else { 
		return false;
	}
}

// Called once after isFinished returns true
void AutoTurn::End() {
	Robot::m_drive->tankDrive(0,0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {}
