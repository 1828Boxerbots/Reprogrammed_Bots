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
  m_driveSub.SetDefaultCommand
  (
    frc2::RunCommand
    (
      [this] 
      {
        m_driveSub.TankDrive(-m_driverController.GetLeftY(), -m_driverController.GetRightY());
      },
      {&m_driveSub}
    )
  );//Might work? Default command is drive
  // if(DemoSwitchSub::GetDemoSwitch() == true)
  // {
  //   m_intakeSpeed = IntakeConstants::kDemoIntakeSpeed;
  //   m_shootSpeed = ShooterConstants::kDemoShooterspeed;
  //   m_driveSpeedMultiplier = DriveConstants::kDemoDriveSpeedMultiplier;
  // }
  // else
  // {
    m_intakeSpeed = IntakeConstants::kIntakeSpeed;
    m_shootSpeed = ShooterConstants::kShooterSpeed;
    m_driveSpeedMultiplier = DriveConstants::kDriveSpeedMultiplier;
  //}
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
  (!m_driverController.LeftBumper() && m_driverController.X()).WhileTrue((m_intakeSub.SetMotors(IntakeConstants::kIntakeSpeed, IntakeConstants::kDemoIntakeSpeed))); //make intake run
  (m_driverController.LeftBumper() && m_driverController.X()).WhileTrue((m_intakeSub.SetMotors(-IntakeConstants::kIntakeSpeed, -IntakeConstants::kDemoIntakeSpeed))); //reverse intake while left bumper and X held
  //m_driverController.Y().ToggleOnTrue(frc2::CommandPtr(m_intakeSub.LoadToPhotoGate(m_intakeSpeed)));
  (!m_driverController.LeftBumper() && m_driverController.RightTrigger()).WhileTrue(m_shooterSub.Setmotors(ShooterConstants::kShooterSpeed, ShooterConstants::kDemoShooterspeed)); //make shooter run
  (m_driverController.LeftBumper() && m_driverController.RightTrigger()).WhileTrue(m_shooterSub.Setmotors(-ShooterConstants::kShooterSpeed, -ShooterConstants::kDemoShooterspeed)); //reverse shooter while left bumper and right trigger held
  (!m_driverController.LeftBumper() && m_driverController.B()).WhileTrue((m_intakeSub.SetMotors(IntakeConstants::kIntakeSpeed, IntakeConstants::kDemoIntakeSpeed))).WhileTrue((m_shooterSub.Setmotors(ShooterConstants::kShooterSpeed, ShooterConstants::kDemoShooterspeed))); //makes both intake and shooter run from pressing B
  (m_driverController.LeftBumper() && m_driverController.B()).WhileTrue((m_intakeSub.SetMotors(-IntakeConstants::kIntakeSpeed, -IntakeConstants::kDemoIntakeSpeed))).WhileTrue((m_shooterSub.Setmotors(-ShooterConstants::kShooterSpeed, ShooterConstants::kDemoShooterspeed))); //makes both intake and shooter reverse while pressing B and holding left bumper
  
}

frc2::CommandPtr 
RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

