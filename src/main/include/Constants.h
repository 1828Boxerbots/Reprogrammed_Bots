// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "units/velocity.h"

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
    // Ports
    // Motors
    inline constexpr int kLeftDriveMotorPort = 1;
    inline constexpr int kRightDriveMotorPort = 0;
    // Encoders
    // inline constexpr int kLeftDrive1EncoderPort = 4;
    // inline constexpr int kLeftDrive2EncoderPort = 5;
    // inline constexpr int kRightDrive1EncoderPort = 2;
    // inline constexpr int kRightDrive2EncoderPort = 3;

    // Math
    inline constexpr int kDriveMotorRPM = 5310;
    inline constexpr float kDriveMotorGearRatio = 12.75;
    inline constexpr float kDtiveWheelDiameterMeter = 0.1524;
    inline constexpr units::meters_per_second_t kMaxDriveMPS = 3.323_mps;
    inline constexpr double kMaxDriveMPSDouble = 3.323;
}

namespace LoadConstants
{
    // Ports
    inline constexpr int kFrontLoadMotorPort = 3;
    inline constexpr int kMidLoadMotorPort = 4; 

    // Other konstants
    inline constexpr float kSpeed = 0.25;
}

namespace ShooterConstants
{
    // Posts
    // Motor
    inline constexpr int kShooterMotorPort = 6;
    // Encoder
    // inline constexpr int kShooter1EncoderPort = 0;
    // inline constexpr int kShooter2EncoderPort = 1;

    // Other konstants
    inline constexpr float kSpeed = 0.25;
}