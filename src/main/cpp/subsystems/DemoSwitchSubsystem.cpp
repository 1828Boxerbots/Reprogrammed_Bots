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
    return m_DemoSwitch.Get();  //Could this return statement be shortened? Yes! Do I care? No.
}