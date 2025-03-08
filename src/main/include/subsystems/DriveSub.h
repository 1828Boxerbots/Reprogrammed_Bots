// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include  <frc/motorcontrol/PWMTalonSRX.h>
#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/ChassisSpeeds.h>






class DriveSub : public frc2::SubsystemBase {
 public:
  DriveSub();

  void RC(double LeftY, double RightX);
  void StopAllMotors(double value);
  void SetLeftMotors(double value);
  void SetRightMotors(double value);

//Commands
 
 frc2::CommandPtr Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

frc::PWMTalonSRX m_leftMotorA{DriveConstants::kLeftMotorAPort};
frc::PWMTalonSRX m_leftMotorB{DriveConstants::kLeftMotorBPort};
frc::PWMTalonSRX m_RightMotorA{DriveConstants::kRightMotorAPort};
frc::PWMTalonSRX m_RightMotorB{DriveConstants::kRightMotorBPort};



  

};
