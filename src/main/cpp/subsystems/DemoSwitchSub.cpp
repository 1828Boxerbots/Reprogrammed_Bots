#include "subsystems/DemoSwitchSub.h"


DemoSwitchSub::DemoSwitchSub() = default;

bool DemoSwitchSub::Readswitch()
{
    return m_DemoSwitch.Get();
}

void DemoSwitchSub::Periodic()
{
    frc::SmartDashboard::PutNumber("Demo Switch value: ", m_DemoSwitch.Get());
  
}