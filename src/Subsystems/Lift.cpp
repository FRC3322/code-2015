// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "../RobotMap.h"
#include "Lift.h"
#include "../Commands/ResetLift.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

void LiftInterupt(uint32_t x, void *param){
	printf("limit switch interrupt callback");
	ResetLift* resetLift = (ResetLift*)param;
	if(resetLift) {
		resetLift->isFinished = true;
		Robot::lift->encoder->Reset();
	}
}

int Lift::getCurrentPosition(){
	return currentHookIndex;
}
int Lift::previousPosition(){
	int previousIndex = currentHookIndex-1;
	if(previousIndex<0){
		previousIndex = 0;
	}
	currentHookIndex = previousIndex;
	return hookPositions[currentHookIndex];

}
int Lift::nextPosition(){
	int nextIndex = currentHookIndex + 1;
	if (nextIndex > hookPositions.size() - 1) {
		nextIndex = hookPositions.size() - 1;
	}
	currentHookIndex = nextIndex;
	return hookPositions[currentHookIndex];
}
void Lift::indexUp(){
	pidController->SetSetpoint(nextPosition());
	printf("\nindex up one to %d", hookPositions[currentHookIndex]);
}
void Lift::indexDown(){
	pidController->SetSetpoint(previousPosition());
	printf("\nindex down one to %d", hookPositions[currentHookIndex]);
}

void Lift::toggleGear() {
	double time = Timer::GetFPGATimestamp();
	if(time - lastLiftShiftTime >= 0.5) {	//TODO: is this time too high
		lastLiftShiftTime = time;
		if(RobotMap::liftgearboxShifter->Get() == DoubleSolenoid::kForward) {
			RobotMap::liftgearboxShifter->Set(DoubleSolenoid::kReverse);
		} else {
			RobotMap::liftgearboxShifter->Set(DoubleSolenoid::kForward);
		}
	}
}

Lift::Lift(Command* resetLift) : Subsystem("lift") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	speedController1 = RobotMap::liftSpeedController1;
	encoder = RobotMap::liftencoder;
	limitSwitch = RobotMap::liftlimitSwitch;
	gearboxShifter = RobotMap::liftgearboxShifter;
	pusher = RobotMap::liftpusher;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	pidController = RobotMap::liftPidController;
	encoder->SetPIDSourceParameter(Encoder::PIDSource::kDistance);
	pidController->SetPID(p, i, d);
	pidController->SetTolerance(5);
	lastLiftShiftTime = 0.0;
	limitSwitch->RequestInterrupts(LiftInterupt, resetLift);
	limitSwitch->EnableInterrupts();

}
    
void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

