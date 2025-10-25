#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/RunCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include "DemoSwitchSubsystem.h"


class DriveSub : public frc2::SubsystemBase
{
public:
DriveSub(); 
~DriveSub(); 


void Init();
void Periodic() override; 
//frc2::StartEndCommand TankDrive(double Leftspeed, double Rightspeed);
void TankDrive(double LeftY, double RightX);


//Unsure of motor number and configuration, double check the true orentation of motor number to position on robot
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorBackLeft{DriveConstants::kDrive3Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorFrontLeft{DriveConstants::kDrive1Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorFrontRight{DriveConstants::kDrive0Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_driveMotorBackRight{DriveConstants::kDrive2Port};
  frc::DifferentialDrive m_driveObject
  {
      [&](double output) { m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, output); },
      [&](double output) { m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, output); }
  };

};

