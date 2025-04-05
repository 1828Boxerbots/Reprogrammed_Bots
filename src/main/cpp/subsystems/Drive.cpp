// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive() // Constructor
{
    // Put all of the initialization things here

    // Inverting the selected motors
    m_LeftDriveMotor1.SetInverted(false);
    m_LeftDriveMotor2.SetInverted(false);
    m_RightDriveMotor1.SetInverted(true);
    m_RightDriveMotor2.SetInverted(true);
}
Drive::~Drive() {} // Deconstructor

// This method will be called once per scheduler run
void Drive::Periodic() {
    frc::SmartDashboard::PutNumber("LeftDriveMotor1 Power", m_LeftDriveMotor1.Get());
    frc::SmartDashboard::PutNumber("LeftDriveMotor2 Power", m_LeftDriveMotor2.Get());
    frc::SmartDashboard::PutNumber("RightDriveMotor1 Power", m_RightDriveMotor1.Get());
    frc::SmartDashboard::PutNumber("RightDriveMotor2 Power", m_RightDriveMotor2.Get());

    frc::SmartDashboard::PutNumber("LeftDriveMotor1 Encoder", m_LeftDriveEncoder1.Get());
    frc::SmartDashboard::PutNumber("LeftDriveMotor2 Encoder", m_LeftDriveEncoder2.Get());
    frc::SmartDashboard::PutNumber("RightDriveMotor1 Encoder", m_RightDriveEncoder1.Get());
    frc::SmartDashboard::PutNumber("RightDriveMotor2 Encoder", m_RightDriveEncoder2.Get());

    frc::SmartDashboard::PutNumber("LeftDriveSpeed MPS", m_leftDriveSpeed * DriveConstants::kMaxDriveMPSDouble);
    frc::SmartDashboard::PutNumber("RightDriveSpeed MPS", m_rightDriveSpeed * DriveConstants::kMaxDriveMPSDouble);
}

void Drive::RCDrive(double forwardPW, double turnPW, 
    units::meters_per_second_t leftDriveSpeed, 
    units::meters_per_second_t RightDriveSpeed)
{
    m_LeftDriveMotor1.Set((forwardPW + turnPW) /8);
    m_LeftDriveMotor2.Set((forwardPW + turnPW) /8);
    m_RightDriveMotor1.Set((forwardPW - turnPW) /8);
    m_RightDriveMotor2.Set((forwardPW - turnPW) /8);

    // leftDriveSpeed = (((forwardPW + turnPW) /2) / DriveConstants::kMaxDriveMPS);
    // RightDriveSpeed = (((forwardPW - turnPW) /2) / DriveConstants::kMaxDriveMPS);

    // Track Width of the robot
    frc::DifferentialDriveKinematics kinematics{21.75_in};
    
    // Gets Drive Wheel Speeds {left side drive, right side drive}
    frc::DifferentialDriveWheelSpeeds wheelSpeeds{leftDriveSpeed, RightDriveSpeed};
    // Placeholder Values

    // Convert Wheel Speeds to ChassisSpeeds
    auto [linearVelocity, vy, angularVelocity] = kinematics.ToChassisSpeeds(wheelSpeeds);
}


// void Drive::DriveKinamatics()
// {
//     // Track Width of the robot
//     frc::DifferentialDriveKinematics kinematics{21.75_in};
    
//     // Gets Drive Wheel Speeds {left side drive, right side drive}
//     frc::DifferentialDriveWheelSpeeds wheelSpeeds{m_leftDriveSpeed, m_RightDriveSpeed};
//     // Placeholder Values

//     // Convert Wheel Speeds to ChassisSpeeds
//     auto [linearVelocity, vy, angularVelocity] = kinematics.ToChassisSpeeds(wheelSpeeds);
// }

/*
5310 RPM
12.75:1
6in diameter wheels
3.323 mps

5310/60 = rps
rps/12.75 = x
convert 6in -> meter
met * pi = dim
dim * x = mps
*/