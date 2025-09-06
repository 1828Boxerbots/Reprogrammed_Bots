// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"
#include "subsystems/DemoSwitchSub.h"

DriveSub::DriveSub() = default;

DriveSub::DriveSub()
{
    m_leftMotorB.SetInverted(true);

    m_leftMotorB.Follow(m_leftMotorA);
    m_RightMotorB.Follow(m_RightMotorA);
}

// This method will be called once per scheduler run
void DriveSub::Periodic() 
{
  frc::SmartDashboard::PutNumber("LeftA Motor: ", m_leftMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("LeftB Motor: ",  m_leftMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("RightA Motor: ", m_RightMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("RightB Motor: ", m_RightMotorB.GetMotorOutputVoltage());
}

 frc2::RunCommand DriveSub::RC(double LeftY, double RightX) // make this the run command
{   
   if(DemoSwitchSub::Readswitch() == true)
   {
     m_drive.ArcadeDrive(LeftY*DemoModeConstants::kDemoDriveScale, RightX*DemoModeConstants::kDemoDriveScale);
   }
   else
   {
      m_drive.ArcadeDrive(LeftY, RightX);
   }
}



void DriveSub::StopAllMotors(double value)
{
   // m_leftMotorA.Set(0);
    //m_leftMotorB.Set(0);
   // m_RightMotorA.Set(0);
   // m_RightMotorB.Set(0);
}

void DriveSub::SetLeftMotors(double value)
{
   // m_leftMotorA.Set(value);
   // m_leftMotorB.Set(value);
}

 void DriveSub::SetRightMotors(double value)
 {
    // m_RightMotorA.Set(value);
    //m_RightMotorB.Set(value);
 }

 frc2::CommandPtr DriveSub::Drive()
 {

 }