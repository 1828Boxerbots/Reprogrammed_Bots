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
    frc::SmartDashboard::PutNumber("Intake Motorcontroller Speed", m_intakeMotor.GetMotorOutputPercent());
}

frc2::CommandPtr IntakeSub::SetMotors(double speed, double demoSpeed)
{
    return StartEnd
    (
    //execute
    [this, speed, demoSpeed]
    {
        if (DemoSwitchSub::GetDemoSwitch())
        {
            m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, demoSpeed);
        }
        else
        {
            m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
        }
        
    },
    //end
    [this] 
    {
        m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);
    }

    );

}

// frc2::FunctionalCommand IntakeSub::LoadToPhotoGate(double speed)
// {
//   //Start
//   [this] 
//   {

//   },
//   //Execute
//   [this, speed] 
//   {
//     m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
//   },
//   //End
//   [this] (bool interrupted) 
//   {
//     m_intakeMotor.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0);    
//   },
//   //End Condition
//   [this] {return m_photoGate.Get() == true;};
  
// }