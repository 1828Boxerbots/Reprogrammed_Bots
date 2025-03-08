// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <rev/SparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Drive : public frc2::SubsystemBase {
 public:
  Drive();
  ~Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  //@brief Will be used as a defualt command that moves the drivetrain
  frc2::StartEndCommand RCDrive(double forwardPW, double turnPW);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  //private member variables
  rev::spark::SparkMax m_LeftDriveMotor{DriveConstants::kLeftDriveMotorPort, rev::spark::SparkMax::MotorType::kBrushed};
  rev::spark::SparkMax m_RightDriveMotor{DriveConstants::kRightDriveMotorPort, rev::spark::SparkMax::MotorType::kBrushed};
};
