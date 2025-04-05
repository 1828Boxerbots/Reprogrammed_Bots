// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  m_Drive.SetDefaultCommand(frc2::RunCommand(
    [this]
    {
      m_Drive.RCDrive({m_driverController.GetLeftY()}, 
        {m_driverController.GetRightX()}, 
        {m_driverController.GetLeftY() * DriveConstants::kMaxDriveMPS},
        {m_driverController.GetRightX() * DriveConstants::kMaxDriveMPS});
    }));

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  // Configure your trigger bindings here

  // Load Binds
  // Run Front
  !m_driverController.LeftBumper()
    && m_driverController.A().WhileTrue(frc2::CommandPtr(m_Load.RunFrontLoad(LoadConstants::kSpeed)));
  m_driverController.LeftBumper()
    && m_driverController.A().WhileTrue(frc2::CommandPtr(m_Load.RunFrontLoad(-LoadConstants::kSpeed)));
  // Run Mid
  !m_driverController.LeftBumper()
    && m_driverController.X().WhileTrue(frc2::CommandPtr(m_Load.RunMidLoad(LoadConstants::kSpeed)));
  m_driverController.LeftBumper()
    && m_driverController.X().WhileTrue(frc2::CommandPtr(m_Load.RunMidLoad(-LoadConstants::kSpeed)));
  // Run Both
  !m_driverController.LeftBumper()
    && m_driverController.B().WhileTrue(frc2::CommandPtr(m_Load.RunAllLoad(LoadConstants::kSpeed)));
  m_driverController.LeftBumper()
    && m_driverController.B().WhileTrue(frc2::CommandPtr(m_Load.RunAllLoad(-LoadConstants::kSpeed)));

  // Shooter Binds
  // Out
  !m_driverController.LeftBumper()
    && m_driverController.RightTrigger().WhileTrue(frc2::CommandPtr(m_Shooter.RunShooter(m_driverController.GetRightTriggerAxis() * ShooterConstants::kSpeed)));
  // In
  m_driverController.LeftBumper()
    && m_driverController.RightTrigger().WhileTrue(frc2::CommandPtr(m_Shooter.RunShooter(m_driverController.GetRightTriggerAxis() * -ShooterConstants::kSpeed)));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
