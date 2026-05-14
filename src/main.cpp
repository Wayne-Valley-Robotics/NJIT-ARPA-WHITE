#include "Arduino.h"
// #include "battery.h"
#include "drive_interface.h" // it be nice if these things ran after setup() somehow

void setup()
{
  // prizm.PrizmBegin();
  Serial.begin(115200);
  // int batteryWarnLevel = batteryCheck();
  // if (batteryWarnLevel >= 3)
  // {
  //   Serial.println("Battery level low. Warning level " + batteryWarnLevel);
  //   prizm.setRedLED(HIGH);
  // }
  drive_interface::initMotors();
}

void loop()
{
  drive_interface::forward(255);
}