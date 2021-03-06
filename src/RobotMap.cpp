// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "Robot.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::forwardDriveForwardLeftTalon = NULL;
CANTalon* RobotMap::forwardDriveForwardRightTalon = NULL;
CANTalon* RobotMap::strafingDriveStrafeRightTalon = NULL;
CANTalon* RobotMap::strafingDriveStrafeLeftTalon = NULL;
CANTalon* RobotMap::elevatorLiftLiftTalon = NULL;
Solenoid* RobotMap::liftGrabberLiftGrabberSolenoid = NULL;
CANTalon* RobotMap::spinnersSpinnerRightTalon = NULL;
CANTalon* RobotMap::spinnersSpinnerLeftTalon = NULL;
Solenoid* RobotMap::brakeBrakeSolenoid = NULL;
Compressor* RobotMap::pneumaticsCompressor = NULL;
DoubleSolenoid* RobotMap::canBurglerCanBurglerRightSolenoid = NULL;
DoubleSolenoid* RobotMap::canBurglerCanBurglerLeftSolenoid = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// /home/lvuser/wpilib-preferences.ini

    std::string robotType = Preferences::GetInstance()->GetString("RobotType");

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	forwardDriveForwardLeftTalon = new CANTalon(Preferences::GetInstance()->GetInt("ForwardDrive::LeftTalon::CANID"));
	forwardDriveForwardRightTalon = new CANTalon(Preferences::GetInstance()->GetInt("ForwardDrive::RightTalon::CANID"));
	strafingDriveStrafeRightTalon = new CANTalon(Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::CANID"));
	strafingDriveStrafeLeftTalon = new CANTalon(Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::CANID"));
	elevatorLiftLiftTalon = new CANTalon(Preferences::GetInstance()->GetInt("ElevatorLift::LiftTalon::CANID"));

	forwardDriveForwardLeftTalon->SetPosition(0);
	forwardDriveForwardRightTalon->SetPosition(0);
	strafingDriveStrafeRightTalon->SetPosition(0);
	strafingDriveStrafeLeftTalon->SetPosition(0);

	liftGrabberLiftGrabberSolenoid = new Solenoid(Preferences::GetInstance()->GetInt("LiftGrabber::PCMID"),
			Preferences::GetInstance()->GetInt("LiftGrabber::Solenoid"));
	lw->AddActuator("LiftGrabber", "LiftGrabberSolenoid", liftGrabberLiftGrabberSolenoid);
	
	spinnersSpinnerRightTalon = new CANTalon(Preferences::GetInstance()->GetInt("Spinners::RightTalon::CANID"));
	spinnersSpinnerLeftTalon = new CANTalon(Preferences::GetInstance()->GetInt("Spinners::LeftTalon::CANID"));
	
	brakeBrakeSolenoid = new Solenoid(Preferences::GetInstance()->GetInt("Brake::PCMID"),
			Preferences::GetInstance()->GetInt("Brake::BrakeSolenoid"));
	lw->AddActuator("Brake", "BrakeSolenoid", brakeBrakeSolenoid);
	
	canBurglerCanBurglerRightSolenoid = new DoubleSolenoid(Preferences::GetInstance()->GetInt("RightCanBurgler::PCMID"),
			Preferences::GetInstance()->GetInt("RightCanBurgler::CanBurglerForwardSolenoid"),
			Preferences::GetInstance()->GetInt("RightCanBurgler::CanBurglerReverseSolenoid"));
	lw->AddActuator("CanBurgler", "CanBurglerRightSolenoid", canBurglerCanBurglerRightSolenoid);

	canBurglerCanBurglerLeftSolenoid = new DoubleSolenoid(Preferences::GetInstance()->GetInt("LeftCanBurgler::PCMID"),
			Preferences::GetInstance()->GetInt("LeftCanBurgler::CanBurglerForwardSolenoid"),
			Preferences::GetInstance()->GetInt("LeftCanBurgler::CanBurglerReverseSolenoid"));
	lw->AddActuator("CanBurgler", "CanBurglerLeftSolenoid", canBurglerCanBurglerLeftSolenoid);


	pneumaticsCompressor = new Compressor(Preferences::GetInstance()->GetInt("Compressor::PCMID"));
}


