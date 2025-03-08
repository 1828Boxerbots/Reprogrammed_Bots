// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoadSub.h"

LoadSub::LoadSub() = default;

// This method will be called once per scheduler run
void LoadSub::Periodic() {}

frc2::RunCommand LoadSub::Load()
{
    [this] 
    {
        m_HigherInnerMotor.Set(LoadConstants::kLoadSpeed);
        m_LowerInnerMotor.Set(LoadConstants::kLoadSpeed);
    };
    //{Reference?};
};