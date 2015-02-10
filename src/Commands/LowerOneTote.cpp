// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LowerOneTote.h"

LowerOneTote::LowerOneTote() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lift);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void LowerOneTote::Initialize() {
	durationNumber = 400;
	Robot::lift->encoder->Reset();
	limitSwitchTripped = false;
}

// Called repeatedly when this Command is scheduled to run
void LowerOneTote::Execute() {
	Robot::lift->speedController1->Set(-.2);
	printf("encoder! %f", Robot::lift->encoder->GetDistance());
	Robot::lift->speedController2->Set(-.2);
	if(!limitSwitchTripped) {
	limitSwitchTripped = Robot::lift->limitSwitch->Get();
	}
	if(limitSwitchTripped){
		printf("limitSwitch tripped!");
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LowerOneTote::IsFinished() {
	bool done = false;
	if(Robot::lift->limitSwitch->Get()) {
		startNumber = 	Robot::lift->encoder->GetDistance();
		printf("start number %f", startNumber);
	}
	if(limitSwitchTripped){
	printf("current Number %f", currentNumber);
	currentNumber = Robot::lift->encoder->GetDistance();
	done =  currentNumber-durationNumber >= startNumber;
	}
	return done;
}

// Called once after isFinished returns true
void LowerOneTote::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerOneTote::Interrupted() {

}
