#include "subsystems/IntakeSubsystem.h"

Intake::Intake()
{

}

Intake::~Intake()
{

}

void Intake::Init()
{

}

void Intake::Periodic()
{
frc::SmartDashboard::PutNumber("Intake Motorcontroller Temperature", m_intakeMotor.GetTemperature());
}

frc2::StartEndCommand Intake::SetMotors(double speed)
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