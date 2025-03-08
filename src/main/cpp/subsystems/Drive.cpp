// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive() //Constructor
{
    //Put all of the initialization things here

    //Inverting the selected motors
    m_LeftDriveMotor.SetInverted(false);
    m_RightDriveMotor.SetInverted(true);
}
Drive::~Drive() {} //Deconstructor

// This method will be called once per scheduler run
void Drive::Periodic() {
    frc::SmartDashboard::PutNumber("Left Drive Motor Power", m_LeftDriveMotor.Get());
    frc::SmartDashboard::PutNumber("Right Drive Motor Power", m_RightDriveMotor.Get());
}

frc2::StartEndCommand Drive::RCDrive(double forwardPW, double turnPW)
{
    //execute
    [this, forwardPW, turnPW]
    {
        m_LeftDriveMotor.Set((turnPW+turnPW)/2);
        m_RightDriveMotor.Set((turnPW-turnPW)/2);
    },
    //end
    [this]
    {
        m_LeftDriveMotor.Set(0);
        m_RightDriveMotor.Set(0);
    };
}


