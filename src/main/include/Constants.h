// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants 
{

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants


namespace DriveConstants
{
    //motor controler ports

    inline constexpr int kLeftMotorAPort = 0;
    inline constexpr int kLeftMotorBPort = 0;
    inline constexpr int kRightMotorAPort = 0;
    inline constexpr int kRightMotorBPort = 0;

    inline constexpr int kDriveSpeed = 0;
}

namespace ShootConstants
{
    //Shooter motor ports

    inline constexpr int kShooterPort = 0;
    inline constexpr int kShooterSpeed = 0;
}

namespace LoadConstants
{
 inline constexpr int kLowerInnerMotorPort = 0;
 inline constexpr int kHigherInnerMotorPort = 0;
 inline constexpr int kLoadSpeed = 0;


}

namespace IntakeConstants
{
    inline constexpr int kIntakeMotorPort = 0;
    inline constexpr int kIntakeSpeed = 0;
   
}
