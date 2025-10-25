#include "subsystems/ShooterSubsystem.h" 

ShooterSub::ShooterSub()
{
//acts as an init
m_shootMotor1.SetInverted(ctre::phoenix::motorcontrol::InvertType::InvertMotorOutput);
m_shootMotor2.SetInverted(ctre::phoenix::motorcontrol::InvertType::InvertMotorOutput);
}

ShooterSub::~ShooterSub()
{

}

void ShooterSub::Init()
{

}

void ShooterSub::Periodic()
{
    frc::SmartDashboard::PutNumber("Shooter1 Motorcontroller Speed", m_shootMotor1.GetMotorOutputPercent());
    frc::SmartDashboard::PutNumber("Shooter2 Motorcontroller Speed", m_shootMotor2.GetMotorOutputPercent());
    frc::SmartDashboard::PutNumber("Shooter3 Motorcontroller Speed", m_shootMotor3.GetMotorOutputPercent());
    frc::SmartDashboard::PutNumber("Shooter4 Motorcontroller Speed", m_shootMotor4.GetMotorOutputPercent());
}

frc2::CommandPtr ShooterSub::Setmotors(double speed, double demoSpeed)
{
    return StartEnd
    (
    //execute
    [this, speed, demoSpeed]
    {
        if (DemoSwitchSub::GetDemoSwitch())
        {
            m_shootMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, demoSpeed);
            m_shootMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, demoSpeed);
            m_shootMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, demoSpeed); //may need to be inverted
            m_shootMotor4.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, demoSpeed); //may need to be inverted
        }
        else
        {
            m_shootMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            m_shootMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            m_shootMotor3.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed); //may need to be inverted
            m_shootMotor4.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed); //may need to be inverted
        }

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
