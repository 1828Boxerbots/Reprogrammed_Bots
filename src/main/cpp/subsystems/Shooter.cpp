// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter()// Constructor
{
    // Put init stuff here
}

Shooter::~Shooter() {} // Deconstructor

// This method will be called once per scheduler run
void Shooter::Periodic() {
    frc::SmartDashboard::PutNumber("ShooterMotor1 Power", m_ShooterMotor1.Get());
    frc::SmartDashboard::PutNumber("ShooterMotor2 Power", m_ShooterMotor2.Get());

    frc::SmartDashboard::PutNumber("ShooterMotor1 Encoder", m_ShooterEncoder1.Get());
    frc::SmartDashboard::PutNumber("ShooterMotor2 Encoder", m_ShooterEncoder2.Get());
}

frc2::StartEndCommand Shooter::RunShooter(float speed)
{
    // execute
    [this, speed]
    {
        m_ShooterMotor1.Set(speed);
        m_ShooterMotor2.Set(speed);
    },
    // end
    [this]
    {
        m_ShooterMotor1.Set(0);
        m_ShooterMotor2.Set(0);
    };
}

