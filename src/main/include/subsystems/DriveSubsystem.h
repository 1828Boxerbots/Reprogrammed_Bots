#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h> 
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

class DriveSub : public frc2::SubsystemBase
{

DriveSub(); 
~DriveSub(); 


void Init();
void Periodic();
void TankDrive(double leftspeed, double rightspeed);
void RCDrive(double LeftY, double RightX);

};

