#include "subsystems/DriveSubsystem.h"

DriveSub::DriveSub()
{
//Acts as an Init
//m_driveMotorBackRight.SetInverted(ctre::phoenix::motorcontrol::InvertType::InvertMotorOutput);
m_driveMotorFrontRight.SetInverted(ctre::phoenix::motorcontrol::InvertType::InvertMotorOutput);
m_driveMotorBackRight.Follow(m_driveMotorFrontRight);
m_driveMotorBackLeft.Follow(m_driveMotorFrontLeft);
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

//frc2::StartEndCommand DriveSub::TankDrive(double Leftspeed, double Rightspeed)
//{
//    return frc2::StartEndCommand
//    (
//        //execute
//        [this, Leftspeed, Rightspeed]
//    {
//    if ((m_driveMotorBackLeft.GetTemperature() >= DriveConstants::kTempuratureLimit) || (m_driveMotorFrontLeft.GetTemperature() >= DriveConstants::kTempuratureLimit) || (m_driveMotorBackRight.GetTemperature() >= DriveConstants::kTempuratureLimit) || (m_driveMotorFrontRight.GetTemperature() >= DriveConstants::kTempuratureLimit))
//    {
//        m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//    }
//    else
//    {
//        m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Leftspeed);
//        m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Leftspeed);
//        m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Rightspeed);
//        m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, Rightspeed);
//    }
//
//    },
//    //end
//    [this]
//    {
//        m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//        m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
//    }
//    );
//    
//}

frc2::StartEndCommand DriveSub::TankDrive(double LeftY, double RightY)
{
    return frc2::StartEndCommand 
    (
        //Execute
        [this, LeftY, RightY]
        {
            m_driveObject.TankDrive(LeftY, RightY);
        },
        //End
        [this]
        {
           m_driveMotorBackLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
           m_driveMotorFrontLeft.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
           m_driveMotorBackRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
           m_driveMotorFrontRight.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        }
    );
}