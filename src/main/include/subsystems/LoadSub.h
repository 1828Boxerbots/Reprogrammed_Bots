// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include  <frc/motorcontrol/PWMTalonSRX.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/RunCommand.h>
#include "Constants.h"

class LoadSub : public frc2::SubsystemBase {
 public:
  LoadSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

frc2::RunCommand Load();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

frc::PWMTalonSRX m_LowerInnerMotor{LoadConstants::kHigherInnerMotorPort};
frc::PWMTalonSRX m_HigherInnerMotor{LoadConstants::kLowerInnerMotorPort};


};
