// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
ForwardDrive* Robot::forwardDrive = 0;
StrafingDrive* Robot::strafingDrive = 0;
ElevatorLift* Robot::elevatorLift = 0;
LiftGrabber* Robot::liftGrabber = 0;
Spinners* Robot::spinners = 0;
Brake* Robot::brake = 0;
CanBurgler* Robot::canBurgler = 0;
//Sensor* Robot::sensor = 0;
//Logger* Robot::logger = 0;
Config* Robot::config = 0;
Pneumatics* Robot::pneumatics = 0;
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

Autonomous_Config* Robot::autonomousConfig = 0;
Robot* Robot::robotInstance = 0;

void Robot::RobotInit() {
//	logger = new Logger();
	robotInstance = this;
	config = new Config();
	RobotMap::init();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	forwardDrive = new ForwardDrive();
	strafingDrive = new StrafingDrive();
	elevatorLift = new ElevatorLift();
	liftGrabber = new LiftGrabber();
	spinners = new Spinners();
	brake = new Brake();
//	sensor = new Sensor();
	canBurgler = new CanBurgler();

	pneumatics = new Pneumatics();
	autonomousConfig = new Autonomous_Config();


	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	config->ReadConfig();
	config->SetConfig();
	config->SaveConfiguration();

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
    if (autonomousConfig->AutonomousMode_Type == 2)
    {
    	autonomousCommand = new AutonomousType2();
    } else if (autonomousConfig->AutonomousMode_Type == 3)
    {
    	autonomousCommand = new AutoCanGrab();
    } else
    {
    	autonomousCommand = new AutonomousCommand();
    }

	teleopCommand = new TeleopCommand();
  }

void Robot::Select_Drive_Back_Auto()
{
	delete autonomousCommand;
	autonomousCommand = new AutonomousType2();
	autonomousConfig->SetAuto(2);
	config->SaveConfiguration();
}

void Robot::Select_CanGrab_Auto()
{
	delete autonomousCommand;
	autonomousCommand = new AutoCanGrab();
	autonomousConfig->SetAuto(3);
	config->SaveConfiguration();
}

void Robot::Select_No_Auto()
{
	delete autonomousCommand;
	autonomousCommand = new AutonomousCommand();
	autonomousConfig->SetAuto(0);
	config->SaveConfiguration();
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();

	if (teleopCommand != NULL)
		teleopCommand->Cancel();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	Robot::liftGrabber->Close();
	Robot::elevatorLift->Set_LiftHome();
//	Robot::forwardDrive->Zero_Encoders();
//	Robot::strafingDrive->Zero_Encoder();

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();

	Robot::liftGrabber->Close();

	if (teleopCommand != NULL)
		teleopCommand->Start();

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

