// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Load.h"

Load::Load() //Constructor
{
    //Put init stuff her
}

Load::~Load() {} //Deconstructor

// This method will be called once per scheduler run
void Load::Periodic() {
    frc::SmartDashboard::PutNumber("Load Front Motor Power", m_FrontLoadMotor.Get());
    frc::SmartDashboard::PutNumber("Load Mid Motor Power", m_MidLoadMotor.Get());
}

frc2::StartEndCommand Load::RunAllLoad(float speed)
{
    // execute
    [this, speed]
    {
        m_FrontLoadMotor.Set(speed);
        m_MidLoadMotor.Set(speed);
    },
    // end
    [this]
    {
        m_FrontLoadMotor.Set(0);
        m_MidLoadMotor.Set(0);
    };
}

frc2::StartEndCommand Load::RunFrontLoad(float speed)
{
    // execute
    [this, speed]
    {
        m_FrontLoadMotor.Set(speed);
    },
    // end
    [this]
    {
        m_FrontLoadMotor.Set(0);
    };
}

frc2::StartEndCommand Load::RunMidLoad(float speed)
{
    // execute
    [this, speed]
    {
        m_MidLoadMotor.Set(speed);
    },
    // end
    [this]
    {
        m_MidLoadMotor.Set(0);
    };
}
