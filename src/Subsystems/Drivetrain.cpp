// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drivetrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rearRight = RobotMap::drivetrainrearRight;
	frontLeft = RobotMap::drivetrainfrontLeft;
	rearLeft = RobotMap::drivetrainrearLeft;
	frontRight = RobotMap::drivetrainfrontRight;
	robotDrive = RobotMap::drivetrainrobotDrive;
	driveGyro = RobotMap::drivetraindriveGyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Drivetrain::ResetHeading() {
	driveGyro->Reset();
}
double Drivetrain::CorrectionAngle() {
	//TODO: code to detect gyroscope failure + fall-back mode (hard-coded constants)
	return -0.02 * driveGyro->GetAngle();
}
void Drivetrain::DriveOnHeading(double velocity) {
	RobotMap::drivetrainrobotDrive->MecanumDrive_Polar(velocity,0,CorrectionAngle());
}
void Drivetrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
