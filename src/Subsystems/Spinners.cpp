// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Spinners.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Spinners::Spinners() : Subsystem("Spinners") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	spinnerRightTalon = RobotMap::spinnersSpinnerRightTalon;
	spinnerLeftTalon = RobotMap::spinnersSpinnerLeftTalon;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	LPosIn = Preferences::GetInstance()->GetBoolean("Spinners::LeftTalon::PosIn");
	RPosIn = Preferences::GetInstance()->GetBoolean("Spinners::RightTalon::PosIn");
	InRate = Preferences::GetInstance()->GetFloat("Spinners::InRate");
	OutRate = Preferences::GetInstance()->GetFloat("Spinners::OutRate");
	RotRate = Preferences::GetInstance()->GetFloat("Spinners::RotRate");

}
    
void Spinners::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Spinners::Intake()
{
	if (RPosIn)
	{
		spinnerRightTalon->Set(InRate);
	} else
	{
		spinnerRightTalon->Set(0 - InRate);
	}

	if (LPosIn)
	{
		spinnerLeftTalon->Set(InRate);
	} else
	{
		spinnerLeftTalon->Set(0 - InRate);
	}
}

void Spinners::Expel()
{
	if (RPosIn)
	{
		spinnerRightTalon->Set(0 - OutRate);
	} else
	{
		spinnerRightTalon->Set(OutRate);
	}

	if (LPosIn)
	{
		spinnerLeftTalon->Set(0 - OutRate);
	} else
	{
		spinnerLeftTalon->Set(OutRate);
	}
}

void Spinners::Rotate()
{
	if (RPosIn)
	{
		spinnerRightTalon->Set(0 - RotRate);
	} else
	{
		spinnerRightTalon->Set(RotRate);
	}

	if (LPosIn)
	{
		spinnerLeftTalon->Set(RotRate);
	} else
	{
		spinnerLeftTalon->Set(0 - RotRate);
	}
}

void Spinners::Stop()
{
	spinnerLeftTalon->Set(0);
	spinnerRightTalon->Set(0);
}
