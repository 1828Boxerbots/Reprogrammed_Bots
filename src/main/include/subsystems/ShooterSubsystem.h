#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/StartEndCommand.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h" 
#include "DemoSwitchSubsystem.h"

class ShooterSub : public frc2::SubsystemBase
{
    public:
    ShooterSub();
    ~ShooterSub();

    void Init();
    void Periodic() override;
    frc2::CommandPtr Setmotors(double speed, double demoSpeed);


ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor1{ShooterConstants::kShooter1Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor2{ShooterConstants::kShooter2Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor3{ShooterConstants::kShooter3Port};
ctre::phoenix::motorcontrol::can::VictorSPX m_shootMotor4{ShooterConstants::kShooter4Port};
};