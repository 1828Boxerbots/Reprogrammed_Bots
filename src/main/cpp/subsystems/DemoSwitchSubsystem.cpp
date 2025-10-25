#include "subsystems/DemoSwitchSubsystem.h"

bool DemoSwitchSub::m_DemoSwitchStatus = true;

DemoSwitchSub::DemoSwitchSub()
{
    frc::SmartDashboard::PutBoolean("DemoSwitch Status", m_DemoSwitch.Get());
}

DemoSwitchSub::~DemoSwitchSub()
{

}

void DemoSwitchSub::Init()
{

}

void DemoSwitchSub::Periodic()
{
    frc::SmartDashboard::PutBoolean("DemoSwitch Status", m_DemoSwitch.Get());
    m_DemoSwitchStatus = m_DemoSwitch.Get(); 
}

