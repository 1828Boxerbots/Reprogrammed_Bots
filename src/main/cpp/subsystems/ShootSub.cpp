// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShootSub.h"

ShootSub::ShootSub() = default;

// This method will be called once per scheduler run
void ShootSub::Periodic() {}

frc2::RunCommand ShootSub::Shoot() 
{
    [this] 
    {
        m_ShootMotor.Set(ShootConstants::kShooterSpeed);
    };
};