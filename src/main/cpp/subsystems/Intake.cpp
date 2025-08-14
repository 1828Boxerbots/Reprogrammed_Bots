#include "subsystems/Intake.h"

Intake::Intake() //Constructor
{
    //Put init stuff her
}

Intake::~Intake() {} //Deconstructor

// This method will be called once per scheduler run
void Intake::Periodic() {
    frc::SmartDashboard::PutNumber("Intake Motor Power", m_IntakeMotor.Get());
}