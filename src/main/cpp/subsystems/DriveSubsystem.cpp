#include "subsystems/DriveSubsystem.h"

DriveSub::DriveSub()
{
//Acts as an Init
}

DriveSub::~DriveSub()
{

}

void DriveSub::Init()
{

}

void DriveSub::Periodic()
{
    frc::SmartDashboard::PutNumber("DriveBackLeft Motorcontroller Temperature", m_driveMotorBackLeft.GetTemperature());
    frc::SmartDashboard::PutNumber("DriveBackRight Motorcontroller Temperature", m_driveMotorBackRight.GetTemperature());
    frc::SmartDashboard::PutNumber("DriveFrontLeft Motorcontroller Temperature", m_driveMotorFrontLeft.GetTemperature());
    frc::SmartDashboard::PutNumber("DriveFrontRight Motorcontroller Temperature", m_driveMotorFrontRight.GetTemperature());
}

void DriveSub::TankDrive(double Leftspeed, double Rightspeed)
{
    if ((m_driveMotorBackLeft.GetTemperature() >= DriveConstants::kTempuratureLimit) || (m_driveMotorFrontLeft.GetTemperature() >= DriveConstants::kTempuratureLimit))
    {
        m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
    }
    else
    {
        m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Leftspeed);
        m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Leftspeed);
    }
    if ((m_driveMotorBackRight.GetTemperature() >= DriveConstants::kTempuratureLimit) || (m_driveMotorFrontRight.GetTemperature() >= DriveConstants::kTempuratureLimit))
    {
        m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
    }
    else
    {
        m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -Rightspeed);
        m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, -Rightspeed);
    }
    
}

void DriveSub::RCDrive(double LeftY, double RightX)
{
    TankDrive(LeftY + RightX, LeftY - RightX);
}


