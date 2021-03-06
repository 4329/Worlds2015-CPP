// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Commands/TeleopCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Brake.h"
#include "Subsystems/Config.h"
#include "Subsystems/ElevatorLift.h"
#include "Subsystems/ForwardDrive.h"
#include "Subsystems/LiftGrabber.h"
//#include "Subsystems/Logger.h"
#include "Subsystems/Pneumatics.h"
//#include "Subsystems/Sensor.h"
#include "Subsystems/Spinners.h"
#include "Subsystems/StrafingDrive.h"
#include "Subsystems/CanBurgler.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousType2.h"
#include "Commands/Autonomous_Config.h"
#include "Commands/AutoCanGrab.h"
#include "OI.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	Command *teleopCommand;
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static ForwardDrive* forwardDrive;
	static StrafingDrive* strafingDrive;
	static ElevatorLift* elevatorLift;
	static LiftGrabber* liftGrabber;
	static Spinners* spinners;
	static Brake* brake;
	static CanBurgler* canBurgler;
//	static Sensor* sensor;
//	static Logger* logger;
	static Config* config;
	static Pneumatics* pneumatics;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    static Autonomous_Config* autonomousConfig;
    static Robot* robotInstance;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	void Select_Drive_Back_Auto();
	void Select_CanGrab_Auto();
	void Select_No_Auto();
};
#endif
