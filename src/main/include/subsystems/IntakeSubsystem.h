#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/StartEndCommand.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h" 

class Intake : public frc2::SubsystemBase
{
    public: 
    Intake();
    ~Intake();
    void Init();
    void Periodic() override;
    frc2::StartEndCommand SetMotors(double speed);

    ctre::phoenix::motorcontrol::can::VictorSPX m_intakeMotor{IntakeConstants::kIntakePort};
};