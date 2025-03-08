// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter()//Constructor
{
    //Put init stuff here
}

Shooter::~Shooter() {} //Deconstructor

// This method will be called once per scheduler run
void Shooter::Periodic() {
    frc::SmartDashboard::PutNumber("Shooter Motor Power", m_ShooterMotor.Get());
}

frc2::StartEndCommand Shooter::RunShooter(float speed)
{
    //execute
    [this, speed]
    {
        m_ShooterMotor.Set(speed);
    },
    //end
    [this]
    {
        m_ShooterMotor.Set(0);
    };
}

