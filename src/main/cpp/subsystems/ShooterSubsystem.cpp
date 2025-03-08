#include "subsystems/ShooterSubsystem.h" 

ShooterSub::ShooterSub()
{
//acts as an init
}

ShooterSub::~ShooterSub()
{

}

void ShooterSub::Init()
{

}

void ShooterSub::Periodic()
{
    frc::SmartDashboard::PutNumber("Shooter1 Motorcontroller Temperature", m_shootMotor1.GetTemperature());
    frc::SmartDashboard::PutNumber("Shooter2 Motorcontroller Temperature", m_shootMotor2.GetTemperature());
    frc::SmartDashboard::PutNumber("Shooter3 Motorcontroller Temperature", m_shootMotor3.GetTemperature());
    frc::SmartDashboard::PutNumber("Shooter4 Motorcontroller Temperature", m_shootMotor4.GetTemperature());
}

frc2::StartEndCommand ShooterSub::Setmotors(double speed)
{
    return frc2::StartEndCommand
    (
    //execute
    [this, speed]
    {
        m_shootMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
        m_shootMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
        m_shootMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
        m_shootMotor4.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
    },
    //end
    [this]
    {
        m_shootMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        m_shootMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        m_shootMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
        m_shootMotor4.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
    
    }

    );
   
}
