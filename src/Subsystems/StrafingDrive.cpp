// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "StrafingDrive.h"
#include "StrafingDrive_Config.h"
#include "Commands/MoveStrafeDrive.h"

#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

StrafingDrive::StrafingDrive() : Subsystem("StrafingDrive") {
	myConfig = new StrafingDrive_Config();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	strafeRightTalon = RobotMap::strafingDriveStrafeRightTalon;
	strafeLeftTalon = RobotMap::strafingDriveStrafeLeftTalon;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	positioning = false;
	posErr = 0;
	lPosErr = 0;
	rPosErr = 0;
	RetrieveConfig();
	Configure();
	Zero_Encoder();
}

StrafingDrive::~StrafingDrive()
{
	delete myConfig;
}

void StrafingDrive::RetrieveConfig()
{
	myConfig->StrafingDrive_HighSpeed = Preferences::GetInstance()->GetFloat("StrafingDrive::HighSpeed");
	myConfig->StrafingDrive_LowSpeed = Preferences::GetInstance()->GetFloat("StrafingDrive::LowSpeed");
	myConfig->StrafingDrive_QuadEncoder_PulsesPerInch = Preferences::GetInstance()->GetFloat("StrafingDrive::QuadEncoder::PulsesPerInch");
	myConfig->StrafingDrive_RightTalon_Enabled = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Enabled");
	myConfig->StrafingDrive_RightTalon_CANID = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::CANID");
	myConfig->StrafingDrive_RightTalon_Reversed = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Reversed");
	myConfig->StrafingDrive_RightTalon_HasSensor = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::HasSensor");
	myConfig->StrafingDrive_RightTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::SensorReversed");
	myConfig->StrafingDrive_RightTalon_EnablePID = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::EnablePID");
	myConfig->StrafingDrive_RightTalon_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::0::PID::P");
	myConfig->StrafingDrive_RightTalon_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::0::PID::I");
	myConfig->StrafingDrive_RightTalon_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::0::PID::D");
	myConfig->StrafingDrive_RightTalon_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::0::PID::F");
	myConfig->StrafingDrive_RightTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::Profile::0::IZone");
	myConfig->StrafingDrive_RightTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Profile::0::EnableCLRampRate");
	myConfig->StrafingDrive_RightTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::0::CLRampRate");
	myConfig->StrafingDrive_RightTalon_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::1::PID::P");
	myConfig->StrafingDrive_RightTalon_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::1::PID::I");
	myConfig->StrafingDrive_RightTalon_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::1::PID::D");
	myConfig->StrafingDrive_RightTalon_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::1::PID::F");
	myConfig->StrafingDrive_RightTalon_Profile_1_IZone = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::Profile::1::IZone");
	myConfig->StrafingDrive_RightTalon_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Profile::1::EnableCLRampRate");
	myConfig->StrafingDrive_RightTalon_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::Profile::1::CLRampRate");
	myConfig->StrafingDrive_RightTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::EnableVoltRampRate");
	myConfig->StrafingDrive_RightTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::VoltRampRate");
	myConfig->StrafingDrive_RightTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::PID::CL::PM::Error");
	myConfig->StrafingDrive_RightTalon_Slaved = Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Slaved");
	myConfig->StrafingDrive_RightTalon_MasterCANID = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::MasterCANID");

	myConfig->StrafingDrive_LeftTalon_Enabled = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::Enabled");
	myConfig->StrafingDrive_LeftTalon_CANID = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::CANID");
	myConfig->StrafingDrive_LeftTalon_Reversed = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::Reversed");
	myConfig->StrafingDrive_LeftTalon_HasSensor = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::HasSensor");
	myConfig->StrafingDrive_LeftTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::SensorReversed");
	myConfig->StrafingDrive_LeftTalon_EnablePID = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::EnablePID");
	myConfig->StrafingDrive_LeftTalon_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::0::PID::P");
	myConfig->StrafingDrive_LeftTalon_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::0::PID::I");
	myConfig->StrafingDrive_LeftTalon_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::0::PID::D");
	myConfig->StrafingDrive_LeftTalon_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::0::PID::F");
	myConfig->StrafingDrive_LeftTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::Profile::0::IZone");
	myConfig->StrafingDrive_LeftTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::Profile::0::EnableCLRampRate");
	myConfig->StrafingDrive_LeftTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::0::CLRampRate");
	myConfig->StrafingDrive_LeftTalon_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::1::PID::P");
	myConfig->StrafingDrive_LeftTalon_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::1::PID::I");
	myConfig->StrafingDrive_LeftTalon_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::1::PID::D");
	myConfig->StrafingDrive_LeftTalon_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::1::PID::F");
	myConfig->StrafingDrive_LeftTalon_Profile_1_IZone = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::Profile::1::IZone");
	myConfig->StrafingDrive_LeftTalon_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::Profile::1::EnableCLRampRate");
	myConfig->StrafingDrive_LeftTalon_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::Profile::1::CLRampRate");
	myConfig->StrafingDrive_LeftTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::EnableVoltRampRate");
	myConfig->StrafingDrive_LeftTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::VoltRampRate");
	myConfig->StrafingDrive_LeftTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::PID::CL::PM::Error");
	myConfig->StrafingDrive_LeftTalon_Slaved = Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::Slaved");
	myConfig->StrafingDrive_LeftTalon_MasterCANID = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::MasterCANID");
}

void StrafingDrive::StoreConfig()
{
	Preferences::GetInstance()->PutFloat("StrafingDrive::HighSpeed",myConfig->StrafingDrive_HighSpeed);
	Preferences::GetInstance()->PutFloat("StrafingDrive::LowSpeed",myConfig->StrafingDrive_LowSpeed);
	Preferences::GetInstance()->PutFloat("StrafingDrive::QuadEncoder::PulsesPerInch",myConfig->StrafingDrive_QuadEncoder_PulsesPerInch);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::Enabled",myConfig->StrafingDrive_RightTalon_Enabled);
	Preferences::GetInstance()->PutInt("StrafingDrive::RightTalon::CANID",myConfig->StrafingDrive_RightTalon_CANID);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::Reversed",myConfig->StrafingDrive_RightTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::HasSensor",myConfig->StrafingDrive_RightTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::SensorReversed",myConfig->StrafingDrive_RightTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::EnablePID",myConfig->StrafingDrive_RightTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::0::PID::P",myConfig->StrafingDrive_RightTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::0::PID::I",myConfig->StrafingDrive_RightTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::0::PID::D",myConfig->StrafingDrive_RightTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::0::PID::F",myConfig->StrafingDrive_RightTalon_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("StrafingDrive::RightTalon::Profile::0::IZone",myConfig->StrafingDrive_RightTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::Profile::0::EnableCLRampRate",myConfig->StrafingDrive_RightTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::0::CLRampRate",myConfig->StrafingDrive_RightTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::1::PID::P",myConfig->StrafingDrive_RightTalon_Profile_1_PID_P);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::1::PID::I",myConfig->StrafingDrive_RightTalon_Profile_1_PID_I);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::1::PID::D",myConfig->StrafingDrive_RightTalon_Profile_1_PID_D);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::1::PID::F",myConfig->StrafingDrive_RightTalon_Profile_1_PID_F);
	Preferences::GetInstance()->PutInt("StrafingDrive::RightTalon::Profile::1::IZone",myConfig->StrafingDrive_RightTalon_Profile_1_IZone);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::Profile::1::EnableCLRampRate",myConfig->StrafingDrive_RightTalon_Profile_1_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::Profile::1::CLRampRate",myConfig->StrafingDrive_RightTalon_Profile_1_CLRampRate);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::EnableVoltRampRate",myConfig->StrafingDrive_RightTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::RightTalon::VoltRampRate",myConfig->StrafingDrive_RightTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("StrafingDrive::RightTalon::PID::CL::PM::Error",myConfig->StrafingDrive_RightTalon_PID_CL_PM_Error);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::RightTalon::Slaved",myConfig->StrafingDrive_RightTalon_Slaved);
	Preferences::GetInstance()->PutInt("StrafingDrive::RightTalon::MasterCANID",myConfig->StrafingDrive_RightTalon_MasterCANID);

	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::Enabled",myConfig->StrafingDrive_LeftTalon_Enabled);
	Preferences::GetInstance()->PutInt("StrafingDrive::LeftTalon::CANID",myConfig->StrafingDrive_LeftTalon_CANID);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::Reversed",myConfig->StrafingDrive_LeftTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::HasSensor",myConfig->StrafingDrive_LeftTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::SensorReversed",myConfig->StrafingDrive_LeftTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::EnablePID",myConfig->StrafingDrive_LeftTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::Profile::0::PID::P",myConfig->StrafingDrive_LeftTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::Profile::0::PID::I",myConfig->StrafingDrive_LeftTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::Profile::0::PID::D",myConfig->StrafingDrive_LeftTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::Profile::0::PID::F",myConfig->StrafingDrive_LeftTalon_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("StrafingDrive::LeftTalon::Profile::0::IZone",myConfig->StrafingDrive_LeftTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::Profile::0::EnableCLRampRate",myConfig->StrafingDrive_LeftTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::Profile::0::CLRampRate",myConfig->StrafingDrive_LeftTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::EnableVoltRampRate",myConfig->StrafingDrive_LeftTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("StrafingDrive::LeftTalon::VoltRampRate",myConfig->StrafingDrive_LeftTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("StrafingDrive::LeftTalon::PID::CL::PM::Error",myConfig->StrafingDrive_LeftTalon_PID_CL_PM_Error);
	Preferences::GetInstance()->PutBoolean("StrafingDrive::LeftTalon::Slaved",myConfig->StrafingDrive_LeftTalon_Slaved);
	Preferences::GetInstance()->PutInt("StrafingDrive::LeftTalon::MasterCANID",myConfig->StrafingDrive_LeftTalon_MasterCANID);
}



void StrafingDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new MoveStrafeDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void StrafingDrive::SetDrive_Arcade(float x, bool highRate)
{
	if (Master->GetControlMode() != CANSpeedController::kPercentVbus)
	{
		positioning = false;
		Set_VoltageMode();
	}
	if (highRate)
	{
		Master->Set(-Limit(x)*HighSpeedRate);
	} else
	{
		Master->Set(-Limit(x)*LowSpeedRate);
	}
}

void StrafingDrive::LinearDrive(float inches)
{
	if (!positioning)
	{
		positioning = true;
		Set_PositionMode();
		distance = ZeroPoint + (inches*PulsesPerInch);
		Master->Set(distance);
	}
}

void StrafingDrive::SetManualDistance(float inches)
{
	printf("SD::SMD Distance %f Zero %f Target \n", inches, ZeroPoint, ZeroPoint + (inches*PulsesPerInch));
	distance = ZeroPoint + (inches*PulsesPerInch);
}

bool StrafingDrive::AtCommandedPosition()
{
	//if (!positioning) return true;
	double cpos = Master->GetPosition();
	double delta;

	if (cpos > distance)
	{
		delta = cpos - distance;
	} else
	{
		delta = distance - cpos;
	}

	//printf("sd:acp cpos %f distance %f cle %f poserr %d\n",cpos,distance, abs(cpos - distance),posErr);
	if (abs(delta) <= posErr )
	{
		printf("SD:ACP return cpos %f distance %f", cpos, distance);
		return true;
	}
	return false;
}

void StrafingDrive::Stop()
{
	strafeRightTalon->Disable();
	strafeLeftTalon->Disable();
	positioning = false;
}

void StrafingDrive::Set_PositionMode()
{
	strafeRightTalon->SelectProfileSlot(1);
	Master->SetControlMode(CANSpeedController::kPosition);
	Zero_Encoder();
	Master->Set(ZeroPoint);
}

void StrafingDrive::Set_VoltageMode()
{
	strafeRightTalon->SelectProfileSlot(0);
	Master->SetControlMode(CANSpeedController::kPercentVbus);
	Master->Set(0);
}

void StrafingDrive::Zero_Encoder()
{
	ZeroPoint = Master->GetPosition();
/*	Master->SetPosition(0);
	printf("SD1 %d \n",Master->GetPosition());
	while (Master->GetPosition() != 0)
	{
		printf("SD2 %d \n",Master->GetPosition());
		Master->SetPosition(0);
	}
*/
}

int StrafingDrive::Get_Encoder()
{
	return Master->GetEncPosition();
}

void StrafingDrive::Configure()
{
	int masterCan;
	PulsesPerInch = myConfig->StrafingDrive_QuadEncoder_PulsesPerInch;
	HighSpeedRate = myConfig->StrafingDrive_HighSpeed;
	LowSpeedRate  = myConfig->StrafingDrive_LowSpeed;

	rPosErr = myConfig->StrafingDrive_RightTalon_PID_CL_PM_Error;
	lPosErr = myConfig->StrafingDrive_LeftTalon_PID_CL_PM_Error;

	if (myConfig->StrafingDrive_RightTalon_Slaved)
	{
		Master = strafeLeftTalon;
		Slave = strafeRightTalon;
		masterCan = myConfig->StrafingDrive_RightTalon_MasterCANID;
		posErr = lPosErr;
	} else
	{
		Master = strafeRightTalon;
		Slave = strafeLeftTalon;
		masterCan = myConfig->StrafingDrive_LeftTalon_MasterCANID;
		posErr = rPosErr;
	}

	Slave->SetControlMode(CANSpeedController::kFollower);
	Slave->Set(masterCan);

	if (myConfig->StrafingDrive_RightTalon_EnablePID)
	{
		strafeRightTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
		if (myConfig->StrafingDrive_RightTalon_SensorReversed)
		{
			strafeRightTalon->SetSensorDirection(true);
		} else
		{
			strafeRightTalon->SetSensorDirection(false);
		}
		strafeRightTalon->SelectProfileSlot(0);
		strafeRightTalon->SetP(myConfig->StrafingDrive_RightTalon_Profile_0_PID_P);
		strafeRightTalon->SetI(myConfig->StrafingDrive_RightTalon_Profile_0_PID_I);
		strafeRightTalon->SetD(myConfig->StrafingDrive_RightTalon_Profile_0_PID_D);
		strafeRightTalon->SetF(myConfig->StrafingDrive_RightTalon_Profile_0_PID_F);
		if (myConfig->StrafingDrive_RightTalon_Profile_0_EnableCLRampRate)
		{
			strafeRightTalon->SetCloseLoopRampRate(myConfig->StrafingDrive_RightTalon_Profile_0_CLRampRate);
		}
		strafeRightTalon->SetIzone(myConfig->StrafingDrive_RightTalon_Profile_0_IZone);

		strafeRightTalon->SelectProfileSlot(1);
		strafeRightTalon->SetP(myConfig->StrafingDrive_RightTalon_Profile_1_PID_P);
		strafeRightTalon->SetI(myConfig->StrafingDrive_RightTalon_Profile_1_PID_I);
		strafeRightTalon->SetD(myConfig->StrafingDrive_RightTalon_Profile_1_PID_D);
		strafeRightTalon->SetF(myConfig->StrafingDrive_RightTalon_Profile_1_PID_F);
		if (myConfig->StrafingDrive_RightTalon_Profile_1_EnableCLRampRate)
		{
			strafeRightTalon->SetCloseLoopRampRate(myConfig->StrafingDrive_RightTalon_Profile_1_CLRampRate);
		}
		strafeRightTalon->SetIzone(myConfig->StrafingDrive_RightTalon_Profile_1_IZone);

		if(myConfig->StrafingDrive_RightTalon_EnableVoltRampRate)
		{
			strafeRightTalon->SetVoltageRampRate(myConfig->StrafingDrive_RightTalon_VoltRampRate);
		}
	}

	if (myConfig->StrafingDrive_LeftTalon_EnablePID)
	{
		strafeLeftTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
		if (myConfig->StrafingDrive_LeftTalon_SensorReversed)
		{
			strafeLeftTalon->SetSensorDirection(true);
		} else
		{
			strafeLeftTalon->SetSensorDirection(false);
		}
		strafeLeftTalon->SelectProfileSlot(0);
		strafeLeftTalon->SetP(myConfig->StrafingDrive_LeftTalon_Profile_0_PID_P);
		strafeLeftTalon->SetI(myConfig->StrafingDrive_LeftTalon_Profile_0_PID_I);
		strafeLeftTalon->SetD(myConfig->StrafingDrive_LeftTalon_Profile_0_PID_D);
		strafeLeftTalon->SetF(myConfig->StrafingDrive_LeftTalon_Profile_0_PID_F);
		if (myConfig->StrafingDrive_LeftTalon_Profile_0_EnableCLRampRate)
		{
			strafeLeftTalon->SetCloseLoopRampRate(myConfig->StrafingDrive_LeftTalon_Profile_0_CLRampRate);
		}

		strafeLeftTalon->SetIzone(myConfig->StrafingDrive_LeftTalon_Profile_0_IZone);

		strafeLeftTalon->SelectProfileSlot(1);
		strafeLeftTalon->SetP(myConfig->StrafingDrive_LeftTalon_Profile_1_PID_P);
		strafeLeftTalon->SetI(myConfig->StrafingDrive_LeftTalon_Profile_1_PID_I);
		strafeLeftTalon->SetD(myConfig->StrafingDrive_LeftTalon_Profile_1_PID_D);
		strafeLeftTalon->SetF(myConfig->StrafingDrive_LeftTalon_Profile_1_PID_F);
		if (myConfig->StrafingDrive_LeftTalon_Profile_1_EnableCLRampRate)
		{
			strafeLeftTalon->SetCloseLoopRampRate(myConfig->StrafingDrive_LeftTalon_Profile_1_CLRampRate);
		}

		strafeLeftTalon->SetIzone(myConfig->StrafingDrive_LeftTalon_Profile_1_IZone);

		if(myConfig->StrafingDrive_LeftTalon_EnableVoltRampRate)
		{
			strafeLeftTalon->SetVoltageRampRate(myConfig->StrafingDrive_LeftTalon_VoltRampRate);
		}
	}
	Set_VoltageMode();
}

float StrafingDrive::Limit(float num)
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
