#include "BackupToAutonZone.h"
#include "Timer.h"

BackupToAutonZone::BackupToAutonZone() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void BackupToAutonZone::Initialize() {
//	Robot::drivetrain->ResetHeading();
	duration = SmartDashboard::GetNumber("backupTime");
	startTime = Timer::GetFPGATimestamp();
}
void BackupToAutonZone::Execute() {
	Robot::drivetrain->DriveOnHeading(.35);
}
bool BackupToAutonZone::IsFinished() {
	return Timer::GetFPGATimestamp() > startTime + duration;
	//angle disable code not yet tested....proceed with caution.
	//We are not responsible for any problems you may encounter
	//with the following code.  Team 3322 is not liable for thermonuclear war,
	//personal injury, or your robot exploding because your gyro was installed backwards.
	//At least the last two are implausible....
//	if(abs(Robot::drivetrain->driveGyro->GetAngle()) >= 15){
//		return true;
//	}
}
void BackupToAutonZone::End() {
	Robot::drivetrain->DriveOnHeading(0.0);
}
void BackupToAutonZone::Interrupted() {
}
