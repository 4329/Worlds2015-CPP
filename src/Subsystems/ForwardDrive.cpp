// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "ForwardDrive.h"
#include "ForwardDrive_Config.h"

#include "Commands/MoveForwardDrive.h"

#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

ForwardDrive::ForwardDrive() : Subsystem("ForwardDrive") {
	myConfig = new ForwardDrive_Config();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	forwardLeftTalon = RobotMap::forwardDriveForwardLeftTalon;
	forwardRightTalon = RobotMap::forwardDriveForwardRightTalon;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    positioning = false;
    rPosErr = 0;
    lPosErr = 0;
    RetrieveConfig();
	Configure();
	// Set_PositionMode();
	lLastPosDelta = 0.0;
	rLastPosDelta = 0.0;
	hasMoved = false;
}
    
ForwardDrive::~ForwardDrive()
{
	delete myConfig;
}

void ForwardDrive::RetrieveConfig()
{
	myConfig->ForwardDrive_HighSpeed = Preferences::GetInstance()->GetFloat("ForwardDrive::HighSpeed");
	myConfig->ForwardDrive_LowSpeed = Preferences::GetInstance()->GetFloat("ForwardDrive::LowSpeed");
	myConfig->ForwardDrive_QuadEncoder_PulsesPerDegree = Preferences::GetInstance()->GetFloat("ForwardDrive::QuadEncoder::PulsesPerDegree");
	myConfig->ForwardDrive_RightTalon_Enabled = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::Enabled");
	myConfig->ForwardDrive_RightTalon_CANID = Preferences::GetInstance()->GetInt("ForwardDrive::RightTalon::CANID");
	myConfig->ForwardDrive_RightTalon_Reversed = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::Reversed");
	myConfig->ForwardDrive_RightTalon_HasSensor = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::HasSensor");
	myConfig->ForwardDrive_RightTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::SensorReversed");
	myConfig->ForwardDrive_RightTalon_EnablePID = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::EnablePID");
	myConfig->ForwardDrive_RightTalon_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::0::PID::P");
	myConfig->ForwardDrive_RightTalon_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::0::PID::I");
	myConfig->ForwardDrive_RightTalon_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::0::PID::D");
	myConfig->ForwardDrive_RightTalon_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::0::PID::F");
	myConfig->ForwardDrive_RightTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("ForwardDrive::RightTalon::Profile::0::IZone");
	myConfig->ForwardDrive_RightTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::Profile::0::EnableCLRampRate");
	myConfig->ForwardDrive_RightTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::0::CLRampRate");
	myConfig->ForwardDrive_RightTalon_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::1::PID::P");
	myConfig->ForwardDrive_RightTalon_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::1::PID::I");
	myConfig->ForwardDrive_RightTalon_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::1::PID::D");
	myConfig->ForwardDrive_RightTalon_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::1::PID::F");
	myConfig->ForwardDrive_RightTalon_Profile_1_IZone = Preferences::GetInstance()->GetInt("ForwardDrive::RightTalon::Profile::1::IZone");
	myConfig->ForwardDrive_RightTalon_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::Profile::1::EnableCLRampRate");
	myConfig->ForwardDrive_RightTalon_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::Profile::1::CLRampRate");
	myConfig->ForwardDrive_RightTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::RightTalon::EnableVoltRampRate");
	myConfig->ForwardDrive_RightTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::RightTalon::VoltRampRate");
	myConfig->ForwardDrive_RightTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("ForwardDrive::RightTalon::PID::CL::PM::Error");
	myConfig->ForwardDrive_RightTalon_QuadEncoder_PulsesPerInch = Preferences::GetInstance()->GetFloat("ForwardDrive::RightTalon::QuadEncoder::PulsesPerInch");

	myConfig->ForwardDrive_LeftTalon_Enabled = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::Enabled");
	myConfig->ForwardDrive_LeftTalon_CANID = Preferences::GetInstance()->GetInt("ForwardDrive::LeftTalon::CANID");
	myConfig->ForwardDrive_LeftTalon_Reversed = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::Reversed");
	myConfig->ForwardDrive_LeftTalon_HasSensor = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::HasSensor");
	myConfig->ForwardDrive_LeftTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::SensorReversed");
	myConfig->ForwardDrive_LeftTalon_EnablePID = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::EnablePID");
	myConfig->ForwardDrive_LeftTalon_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::0::PID::P");
	myConfig->ForwardDrive_LeftTalon_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::0::PID::I");
	myConfig->ForwardDrive_LeftTalon_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::0::PID::D");
	myConfig->ForwardDrive_LeftTalon_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::0::PID::F");
	myConfig->ForwardDrive_LeftTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("ForwardDrive::LeftTalon::Profile::0::IZone");
	myConfig->ForwardDrive_LeftTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::Profile::0::EnableCLRampRate");
	myConfig->ForwardDrive_LeftTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::0::CLRampRate");
	myConfig->ForwardDrive_LeftTalon_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::1::PID::P");
	myConfig->ForwardDrive_LeftTalon_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::1::PID::I");
	myConfig->ForwardDrive_LeftTalon_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::1::PID::D");
	myConfig->ForwardDrive_LeftTalon_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::1::PID::F");
	myConfig->ForwardDrive_LeftTalon_Profile_1_IZone = Preferences::GetInstance()->GetInt("ForwardDrive::LeftTalon::Profile::1::IZone");
	myConfig->ForwardDrive_LeftTalon_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::Profile::1::EnableCLRampRate");
	myConfig->ForwardDrive_LeftTalon_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::Profile::1::CLRampRate");
	myConfig->ForwardDrive_LeftTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("ForwardDrive::LeftTalon::EnableVoltRampRate");
	myConfig->ForwardDrive_LeftTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("ForwardDrive::LeftTalon::VoltRampRate");
	myConfig->ForwardDrive_LeftTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("ForwardDrive::LeftTalon::PID::CL::PM::Error");
	myConfig->ForwardDrive_LeftTalon_QuadEncoder_PulsesPerInch = Preferences::GetInstance()->GetFloat("ForwardDrive::LeftTalon::QuadEncoder::PulsesPerInch");

}

void ForwardDrive::StoreConfig()
{
	Preferences::GetInstance()->PutFloat("ForwardDrive::HighSpeed",myConfig->ForwardDrive_HighSpeed);
	Preferences::GetInstance()->PutFloat("ForwardDrive::LowSpeed",myConfig->ForwardDrive_LowSpeed);
	Preferences::GetInstance()->PutFloat("ForwardDrive::QuadEncoder::PulsesPerDegree",myConfig->ForwardDrive_QuadEncoder_PulsesPerDegree);
	Preferences::GetInstance()->PutFloat("ForwardDrive::RightTalon::QuadEncoder::PulsesPerInch",myConfig->ForwardDrive_RightTalon_QuadEncoder_PulsesPerInch);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::Enabled",myConfig->ForwardDrive_RightTalon_Enabled);
	Preferences::GetInstance()->PutInt("ForwardDrive::RightTalon::CANID",myConfig->ForwardDrive_RightTalon_CANID);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::Reversed",myConfig->ForwardDrive_RightTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::HasSensor",myConfig->ForwardDrive_RightTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::SensorReversed",myConfig->ForwardDrive_RightTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::EnablePID",myConfig->ForwardDrive_RightTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::0::PID::P",myConfig->ForwardDrive_RightTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::0::PID::I",myConfig->ForwardDrive_RightTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::0::PID::D",myConfig->ForwardDrive_RightTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::0::PID::F",myConfig->ForwardDrive_RightTalon_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("ForwardDrive::RightTalon::Profile::0::IZone",myConfig->ForwardDrive_RightTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::Profile::0::EnableCLRampRate",myConfig->ForwardDrive_RightTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::0::CLRampRate",myConfig->ForwardDrive_RightTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::1::PID::P",myConfig->ForwardDrive_RightTalon_Profile_1_PID_P);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::1::PID::I",myConfig->ForwardDrive_RightTalon_Profile_1_PID_I);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::1::PID::D",myConfig->ForwardDrive_RightTalon_Profile_1_PID_D);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::1::PID::F",myConfig->ForwardDrive_RightTalon_Profile_1_PID_F);
	Preferences::GetInstance()->PutInt("ForwardDrive::RightTalon::Profile::1::IZone",myConfig->ForwardDrive_RightTalon_Profile_1_IZone);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::Profile::1::EnableCLRampRate",myConfig->ForwardDrive_RightTalon_Profile_1_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::Profile::1::CLRampRate",myConfig->ForwardDrive_RightTalon_Profile_1_CLRampRate);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::RightTalon::EnableVoltRampRate",myConfig->ForwardDrive_RightTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::RightTalon::VoltRampRate",myConfig->ForwardDrive_RightTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("ForwardDrive::RightTalon::PID::CL::PM::Error",myConfig->ForwardDrive_RightTalon_PID_CL_PM_Error);

	Preferences::GetInstance()->PutFloat("ForwardDrive::LeftTalon::QuadEncoder::PulsesPerInch",myConfig->ForwardDrive_LeftTalon_QuadEncoder_PulsesPerInch);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::Enabled",myConfig->ForwardDrive_LeftTalon_Enabled);
	Preferences::GetInstance()->PutInt("ForwardDrive::LeftTalon::CANID",myConfig->ForwardDrive_LeftTalon_CANID);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::Reversed",myConfig->ForwardDrive_LeftTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::HasSensor",myConfig->ForwardDrive_LeftTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::SensorReversed",myConfig->ForwardDrive_LeftTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::EnablePID",myConfig->ForwardDrive_LeftTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::0::PID::P",myConfig->ForwardDrive_LeftTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::0::PID::I",myConfig->ForwardDrive_LeftTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::0::PID::D",myConfig->ForwardDrive_LeftTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::0::PID::F",myConfig->ForwardDrive_LeftTalon_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("ForwardDrive::LeftTalon::Profile::0::IZone",myConfig->ForwardDrive_LeftTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::Profile::0::EnableCLRampRate",myConfig->ForwardDrive_LeftTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::0::CLRampRate",myConfig->ForwardDrive_LeftTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::1::PID::P",myConfig->ForwardDrive_LeftTalon_Profile_1_PID_P);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::1::PID::I",myConfig->ForwardDrive_LeftTalon_Profile_1_PID_I);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::1::PID::D",myConfig->ForwardDrive_LeftTalon_Profile_1_PID_D);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::1::PID::F",myConfig->ForwardDrive_LeftTalon_Profile_1_PID_F);
	Preferences::GetInstance()->PutInt("ForwardDrive::LeftTalon::Profile::1::IZone",myConfig->ForwardDrive_LeftTalon_Profile_1_IZone);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::Profile::1::EnableCLRampRate",myConfig->ForwardDrive_LeftTalon_Profile_1_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::Profile::1::CLRampRate",myConfig->ForwardDrive_LeftTalon_Profile_1_CLRampRate);
	Preferences::GetInstance()->PutBoolean("ForwardDrive::LeftTalon::EnableVoltRampRate",myConfig->ForwardDrive_LeftTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("ForwardDrive::LeftTalon::VoltRampRate",myConfig->ForwardDrive_LeftTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("ForwardDrive::LeftTalon::PID::CL::PM::Error",myConfig->ForwardDrive_LeftTalon_PID_CL_PM_Error);
}


void ForwardDrive::Configure()
{
	LeftPulsesPerInch = myConfig->ForwardDrive_LeftTalon_QuadEncoder_PulsesPerInch;
	RightPulsesPerInch = myConfig->ForwardDrive_RightTalon_QuadEncoder_PulsesPerInch;

	HighSpeedRate = myConfig->ForwardDrive_HighSpeed;
	LowSpeedRate = myConfig->ForwardDrive_LowSpeed;
	PulsesPerDeg = myConfig->ForwardDrive_QuadEncoder_PulsesPerDegree;

	if (myConfig->ForwardDrive_LeftTalon_Enabled)
	{
		printf("FD:Configure LT enabled\n");
        if (myConfig->ForwardDrive_LeftTalon_HasSensor)
        {
			forwardLeftTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
			if (myConfig->ForwardDrive_LeftTalon_SensorReversed)
			{
				forwardLeftTalon->SetSensorDirection(true);
			} else
			{
				forwardLeftTalon->SetSensorDirection(false);
			}
        }
        if (myConfig->ForwardDrive_LeftTalon_EnablePID)
        {
        	printf("FD:Configure LT PID enabled\n");
        	forwardLeftTalon->SelectProfileSlot(0);
			forwardLeftTalon->SetP(myConfig->ForwardDrive_LeftTalon_Profile_0_PID_P);
			forwardLeftTalon->SetI(myConfig->ForwardDrive_LeftTalon_Profile_0_PID_I);
			forwardLeftTalon->SetD(myConfig->ForwardDrive_LeftTalon_Profile_0_PID_D);
			forwardLeftTalon->SetF(myConfig->ForwardDrive_LeftTalon_Profile_0_PID_F);
			if (myConfig->ForwardDrive_LeftTalon_Profile_0_EnableCLRampRate)
			{
				forwardLeftTalon->SetCloseLoopRampRate(myConfig->ForwardDrive_LeftTalon_Profile_0_CLRampRate);
			}

			forwardLeftTalon->SetIzone(myConfig->ForwardDrive_LeftTalon_Profile_0_IZone);

			forwardLeftTalon->SelectProfileSlot(1);
			forwardLeftTalon->SetP(myConfig->ForwardDrive_LeftTalon_Profile_1_PID_P);
			forwardLeftTalon->SetI(myConfig->ForwardDrive_LeftTalon_Profile_1_PID_I);
			forwardLeftTalon->SetD(myConfig->ForwardDrive_LeftTalon_Profile_1_PID_D);
			forwardLeftTalon->SetF(myConfig->ForwardDrive_LeftTalon_Profile_1_PID_F);
			if (myConfig->ForwardDrive_LeftTalon_Profile_1_EnableCLRampRate)
			{
				forwardLeftTalon->SetCloseLoopRampRate(myConfig->ForwardDrive_LeftTalon_Profile_1_CLRampRate);
			}

			forwardLeftTalon->SetIzone(myConfig->ForwardDrive_LeftTalon_Profile_1_IZone);
			lPosErr = myConfig->ForwardDrive_LeftTalon_PID_CL_PM_Error;
        }

		if(myConfig->ForwardDrive_LeftTalon_EnableVoltRampRate)
		{
			forwardLeftTalon->SetVoltageRampRate(myConfig->ForwardDrive_LeftTalon_VoltRampRate);
		}
	}

	if (myConfig->ForwardDrive_RightTalon_Enabled)
	{
		printf("FD:Configure RT enabled\n");
		if (myConfig->ForwardDrive_RightTalon_HasSensor)
		{
			forwardRightTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
			if (myConfig->ForwardDrive_RightTalon_SensorReversed)
			{
				forwardRightTalon->SetSensorDirection(true);
			} else
			{
				forwardRightTalon->SetSensorDirection(false);
			}
		}
		if (myConfig->ForwardDrive_RightTalon_EnablePID)
		{
			printf("FD:Configure RT PID enabled\n");
			forwardRightTalon->SelectProfileSlot(0);
			forwardRightTalon->SetP(myConfig->ForwardDrive_RightTalon_Profile_0_PID_P);
			forwardRightTalon->SetI(myConfig->ForwardDrive_RightTalon_Profile_0_PID_I);
			forwardRightTalon->SetD(myConfig->ForwardDrive_RightTalon_Profile_0_PID_D);
			forwardRightTalon->SetF(myConfig->ForwardDrive_RightTalon_Profile_0_PID_F);
			if (myConfig->ForwardDrive_RightTalon_Profile_0_EnableCLRampRate)
			{
				forwardRightTalon->SetCloseLoopRampRate(myConfig->ForwardDrive_RightTalon_Profile_0_CLRampRate);
			}
			forwardRightTalon->SetIzone(myConfig->ForwardDrive_RightTalon_Profile_0_IZone);

			forwardRightTalon->SelectProfileSlot(1);
			forwardRightTalon->SetP(myConfig->ForwardDrive_RightTalon_Profile_1_PID_P);
			forwardRightTalon->SetI(myConfig->ForwardDrive_RightTalon_Profile_1_PID_I);
			forwardRightTalon->SetD(myConfig->ForwardDrive_RightTalon_Profile_1_PID_D);
			forwardRightTalon->SetF(myConfig->ForwardDrive_RightTalon_Profile_1_PID_F);
			if (myConfig->ForwardDrive_RightTalon_Profile_1_EnableCLRampRate)
			{
				forwardRightTalon->SetCloseLoopRampRate(myConfig->ForwardDrive_RightTalon_Profile_1_CLRampRate);
			}
			forwardRightTalon->SetIzone(myConfig->ForwardDrive_RightTalon_Profile_1_IZone);
			rPosErr = myConfig->ForwardDrive_RightTalon_PID_CL_PM_Error;
		}
		if(myConfig->ForwardDrive_RightTalon_EnableVoltRampRate)
		{
			forwardRightTalon->SetVoltageRampRate(myConfig->ForwardDrive_RightTalon_VoltRampRate);
		}
	}
}

void ForwardDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new MoveForwardDrive());
}

void ForwardDrive::SetDrive_Arcade(float x, float y, bool highRate)
{
	float tx, ty;

	tx = Limit(x);
	ty = Limit(y);

    printf("FD X %f   Y %f\n",tx,ty);
	if (forwardLeftTalon->GetControlMode() != CANSpeedController::kPercentVbus)
	{
		positioning = false;
		Set_VoltageMode();
	}
	if (ty > 0.0)
	{

		if (tx > 0.0)
		{
			leftMotorOutput = ty - tx;
			rightMotorOutput = std::max(ty, tx);
		}
		else if (tx < 0.0)
		{
			leftMotorOutput = std::max(ty, -tx);
			rightMotorOutput = ty + tx;
		} else
		{
			leftMotorOutput = ty;
			rightMotorOutput = ty;
		}
	}
	else
	{
		if (tx > 0.0)
		{
			leftMotorOutput = - std::max(-ty, tx);
			rightMotorOutput = ty + tx;
		}
		else if (tx < 0.0)
		{
			leftMotorOutput = ty - tx;
			rightMotorOutput = - std::max(-ty, -tx);
		} else
		{
			leftMotorOutput = ty;
			rightMotorOutput = ty;
		}
	}

	if (highRate)
	{
		forwardLeftTalon->Set(leftMotorOutput*HighSpeedRate);
		forwardRightTalon->Set(rightMotorOutput*HighSpeedRate);
	} else
	{
		forwardLeftTalon->Set(leftMotorOutput*LowSpeedRate);
		forwardRightTalon->Set(rightMotorOutput*LowSpeedRate);
	}
}

void ForwardDrive::SetDrive_Tank(float left, float right, bool highRate)
{
	if (highRate)
	{
		forwardLeftTalon->Set(Limit(left)*HighSpeedRate);
		forwardRightTalon->Set(Limit(right)*HighSpeedRate);
	} else
	{
		forwardLeftTalon->Set(Limit(left)*LowSpeedRate);
		forwardRightTalon->Set(Limit(right)*LowSpeedRate);
	}
}

void ForwardDrive::LinearDrive(float inches)
{
//	if (positioning == false)
//	{
//	    printf("FD-LD %f", inches);
		positioning = true;
		ldistance = lZeroPoint + (inches * LeftPulsesPerInch);
		rdistance = rZeroPoint + (inches * RightPulsesPerInch);
		forwardLeftTalon->Set(ldistance);
		forwardRightTalon->Set(rdistance);

//	}
}

bool ForwardDrive::AtCommandedPosition()
{
	double lcpos = forwardLeftTalon->GetPosition();
	double rcpos = forwardRightTalon->GetPosition();
	double ldelta;
	double rdelta;

	if (lcpos > ldistance)
	{
		ldelta = lcpos - ldistance;
	} else
	{
		ldelta = ldistance - lcpos;
	}

	if (rcpos > rdistance)
	{
		rdelta = rcpos - rdistance;
	} else
	{
		rdelta = rdistance - rcpos;
	}

	printf("FDACP lcpos %f ldist %f ldelta %f lastlDelta %f \n", lcpos, ldistance, ldelta, lLastPosDelta);
	printf("FDACP rcpos %f rdist %f rdelta %f lastrDelta %f \n", rcpos, rdistance, rdelta, rLastPosDelta);

	if ((hasMoved == true) && (ldelta == lLastPosDelta) && (rdelta == rLastPosDelta))
	{
		printf("FDACP Returning due to no measured movement \n");
		return true;
	} else
	{
		if ((ldelta != abs(ldistance - lcpos)) && (rdelta != abs(rdistance - rcpos))) hasMoved = true;
	}

	if ((lLastPosDelta != 0) && (abs(lLastPosDelta) < abs(ldelta)))
	{
		printf("FDACP Returning because left target overshot last %f cur %f\n" , lLastPosDelta, ldelta);
		return true;
	}

	if ((rLastPosDelta != 0) && (abs(rLastPosDelta) < abs(rdelta)))
	{
		printf("FDACP Returning because right target overshot last %f cur %f\n" , rLastPosDelta, rdelta);
		return true;
	}

	if (abs(ldelta) <= lPosErr )
	{
		printf("FDACP Returning left cpos %f dist %f \n", lcpos, ldistance);
		return true;
	}

	if (abs(rdelta) <= rPosErr )
	{
		printf("FDACP Returning right cpos %f dist %f \n", rcpos, rdistance);
		return true;
	}
	lLastPosDelta = ldelta;
	rLastPosDelta = rdelta;

	return false;
}


void ForwardDrive::Pivot(float degrees)
{
	if (!positioning)
	{
		positioning = true;
		Set_PositionMode();
		if (degrees >= 0.0)
		{
			ldistance = degrees*PulsesPerDeg;
			rdistance = -(degrees*PulsesPerDeg);
		} else
		{
			ldistance = -(degrees*PulsesPerDeg);
			rdistance = degrees*PulsesPerDeg;
		}
		forwardLeftTalon->Set(ldistance);
		forwardRightTalon->Set(rdistance);
	}
}

void ForwardDrive::SetManualDistance(float inches)
{
	printf("FD::SMD Distance %f %f \n", inches, (inches * LeftPulsesPerInch));
	ldistance = lZeroPoint + (inches * LeftPulsesPerInch);
	rdistance = rZeroPoint + ((-1*inches) * RightPulsesPerInch);
	lLastPosDelta = 0.0;
	rLastPosDelta = 0.0;
	hasMoved = false;
}

void ForwardDrive::SetManualPivot(float degrees)
{
	if (degrees >= 0.0)
	{
		ldistance = degrees*PulsesPerDeg;
		rdistance = -(degrees*PulsesPerDeg);
	} else
	{
		ldistance = -(degrees*PulsesPerDeg);
		rdistance = degrees*PulsesPerDeg;
	}
}

void ForwardDrive::Stop()
{
	printf("FD-STOP\n");
	forwardRightTalon->Disable();
	forwardLeftTalon->Disable();
	positioning = false;
}

void ForwardDrive::Set_PositionMode()
{
	forwardLeftTalon->SelectProfileSlot(1);
	forwardRightTalon->SelectProfileSlot(1);
	forwardLeftTalon->SetControlMode(CANSpeedController::kPosition);
	forwardRightTalon->SetControlMode(CANSpeedController::kPosition);
	Zero_Encoders();
	forwardLeftTalon->Set(lZeroPoint);
	forwardRightTalon->Set(rZeroPoint);
	forwardLeftTalon->ClearError();
	forwardRightTalon->ClearIaccum();
	forwardLeftTalon->EnableControl();
	forwardRightTalon->EnableControl();
}

void ForwardDrive::Set_VoltageMode()
{
	forwardLeftTalon->SelectProfileSlot(0);
	forwardRightTalon->SelectProfileSlot(0);
	forwardLeftTalon->SetControlMode(CANSpeedController::kPercentVbus);
	forwardRightTalon->SetControlMode(CANSpeedController::kPercentVbus);
	forwardLeftTalon->EnableControl();
	forwardRightTalon->EnableControl();
	forwardLeftTalon->Set(0);
	forwardRightTalon->Set(0);
}

void ForwardDrive::Zero_Encoders()
{
/*	forwardRightTalon->SetPosition(0);
	forwardLeftTalon->SetPosition(0);
	printf("FDR1 %d \n",forwardRightTalon->GetPosition());
	printf("FDR1 %d \n",forwardLeftTalon->GetPosition());
	while (forwardRightTalon->GetPosition() != 0)
	{
		printf("FDR2 %d \n",forwardRightTalon->GetPosition());
		forwardRightTalon->SetPosition(0);
	}

	while (forwardLeftTalon->GetPosition() != 0)
	{
		printf("FDL2 %d \n",forwardLeftTalon->GetPosition());
		forwardLeftTalon->SetPosition(0);
	}
*/
	lZeroPoint = forwardLeftTalon->GetPosition();
	rZeroPoint = forwardRightTalon->GetPosition();
	lLastPosDelta = 0.0;
	rLastPosDelta = 0.0;
	hasMoved = false;
}

int ForwardDrive::Get_LeftEncoder()
{
	return forwardLeftTalon->GetPosition();
}

int ForwardDrive::Get_RightEncoder()
{
	return forwardRightTalon->GetPosition();
}

/**
 * Limit motor values to the -1.0 to +1.0 range.
 */
float ForwardDrive::Limit(float num)
{
	if (num > 1.0)
	{
		return 1.0;
	}
	if (num < -1.0)
	{
		return -1.0;
	}
	return num;
}
