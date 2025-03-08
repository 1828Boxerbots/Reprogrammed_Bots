// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"

DriveSub::DriveSub() = default;

DriveSub::DriveSub()
{
    m_leftMotorA.SetInverted(true);
    m_leftMotorB.SetInverted(true);
}

// This method will be called once per scheduler run
void DriveSub::Periodic() {}

void DriveSub::RC(double LeftY, double RightX)
{
    
}


void DriveSub::StopAllMotors(double value)
{
    m_leftMotorA.Set(0);
    m_leftMotorB.Set(0);
    m_RightMotorA.Set(0);
    m_RightMotorB.Set(0);
}

void DriveSub::SetLeftMotors(double value)
{
    m_leftMotorA.Set(value);
    m_leftMotorB.Set(value);
}

 void DriveSub::SetRightMotors(double value)
 {
     m_RightMotorA.Set(value);
    m_RightMotorB.Set(value);
 }

 frc2::CommandPtr DriveSub::Drive()
 {

 }