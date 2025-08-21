#include "subsystems/DemoSwitchSubsystem.h"

frc::DigitalInput DemoSwitchSub::m_DemoSwitch{DemoSwitchConstants::kDemoSwitchPort};

DemoSwitchSub::DemoSwitchSub()
{

}

DemoSwitchSub::~DemoSwitchSub()
{

}

void DemoSwitchSub::Init()
{

}

void DemoSwitchSub::Periodic()
{

}

bool DemoSwitchSub::GetDemoSwitch()
{
    m_DemoSwitchStatus = m_DemoSwitch.Get();
    return m_DemoSwitchStatus;  //Could this return statement be shortened? Yes! Do I care? No.
}