#include "subsystems/IntakeSubsystem.h"

IntakeSub::IntakeSub()
{

}

IntakeSub::~IntakeSub()
{

}

void IntakeSub::Init()
{

}

void IntakeSub::Periodic()
{
frc::SmartDashboard::PutNumber("Intake Motorcontroller Temperature", m_intakeMotor.GetTemperature());
}

frc2::StartEndCommand IntakeSub::SetMotors(double speed)
{
    return frc2::StartEndCommand
    (
    //execute
    [this, speed]
    {
        m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
    },
    //end
    [this]
    {
        m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
    }

    );

}