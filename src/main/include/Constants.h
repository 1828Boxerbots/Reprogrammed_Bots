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

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace DriveConstants
{
    inline constexpr int kDrive0Port = 0;
    inline constexpr int kDrive1Port = 1;
    inline constexpr int kDrive2Port = 2;
    inline constexpr int kDrive3Port = 3;
    //.GetTemperature Method of VictorSPX may get temp of controller not motor itself, be aware. 
    inline constexpr double kTempuratureLimit = 60; //Placeholder-ish value, unsure of good number. 
}
namespace ShooterConstants
{
    inline constexpr int kShooter1Port = 4; 
    inline constexpr int kShooter2Port = 5; 
    inline constexpr int kShooter3Port = 6; 
    inline constexpr int kShooter4Port = 7; 
}
namespace IntakeConstants
{
    inline constexpr int kIntakePort = 8;
}