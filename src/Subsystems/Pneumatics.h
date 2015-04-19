// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef PNEUMATICS_H
#define PNEUMATICS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Configurable.h"

class Pneumatics_Config;

class Pneumatics: public Subsystem, public Configurable {
private:
	Pneumatics_Config * myConfig;

public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Compressor* compressor;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Pneumatics();
	virtual ~Pneumatics();
	virtual void RetrieveConfig();
	virtual void StoreConfig();
	virtual void Configure();

	void InitDefaultCommand();

	void On();
	void Off();
};

#endif
