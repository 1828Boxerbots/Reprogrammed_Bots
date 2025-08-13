// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  m_driveSub.Init();
  m_intakeSub.Init();
  m_shooterSub.Init();
  // Configure the button bindings
  ConfigureBindings(); 
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  frc2::Trigger B_Button = m_driverController.B();

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.X().WhileTrue(frc2::CommandPtr(m_intakeSub.SetMotors(IntakeConstants::kIntakeSpeed))); //make intake run
  (m_driverController.LeftBumper() && m_driverController.X()).WhileTrue(frc2::CommandPtr(m_intakeSub.SetMotors(-IntakeConstants::kIntakeSpeed))); //reverse intake while left bumper and X held
  m_driverController.RightTrigger().WhileTrue(frc2::CommandPtr(m_shooterSub.Setmotors(ShooterConstants::kShooterSpeed))); //make shooter run
  (m_driverController.LeftBumper() && m_driverController.RightTrigger()).WhileTrue(frc2::CommandPtr(m_shooterSub.Setmotors(-ShooterConstants::kShooterSpeed))); //reverse shooter while left bumper and right trigger held
  m_driverController.B().WhileTrue(frc2::CommandPtr(m_intakeSub.SetMotors(IntakeConstants::kIntakeSpeed))).WhileTrue(frc2::CommandPtr(m_shooterSub.Setmotors(ShooterConstants::kShooterSpeed))); //makes both intake and shooter run from pressing B
  m_driveSub.SetDefaultCommand(m_driveSub.TankDrive(m_driverController.GetLeftY(), m_driverController.GetRightY()));//Might work? Default command is drive
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
