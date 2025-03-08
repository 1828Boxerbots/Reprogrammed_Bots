#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/RunCommand.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class DriveSub : public frc2::SubsystemBase
{
public:
DriveSub(); 
~DriveSub(); 


void Init();
void Periodic() override;
void TankDrive(double Leftspeed, double Rightspeed);
void RCDrive(double LeftY, double RightX);


//Unsure of motor number and configuration, double check the true orentation of motor number to position on robot
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorBackLeft{DriveConstants::kDrive0Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorFrontLeft{DriveConstants::kDrive1Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorFrontRight{DriveConstants::kDrive2Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorBackRight{DriveConstants::kDrive3Port};


};

