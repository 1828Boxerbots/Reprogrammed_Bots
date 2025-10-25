#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <frc2/command/StartEndCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include "Constants.h" 

class DemoSwitchSub : public frc2::SubsystemBase
{
    public:
    DemoSwitchSub();
    ~DemoSwitchSub();

    void Init();
    void Periodic() override;
    static bool GetDemoSwitch() {return m_DemoSwitchStatus;}


    private:
    static bool m_DemoSwitchStatus;
    frc::DigitalInput m_DemoSwitch {DemoSwitchConstants::kDemoSwitchPort};
};