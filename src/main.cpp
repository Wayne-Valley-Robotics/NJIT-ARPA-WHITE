#include "Arduino.h"
// #include "battery.h"
#include "inputs_interface.h"
#include "drive_interface.h"

void setup()
{
  // prizm.PrizmBegin();
  Serial.begin(115200);
  PS4::DATA::init();

  // TODO: implement some kind of battery check to make sure the battery is charged. there are no safe-guards for this
  // and in the worst case scenario everything could look fine, until you try to drive all the motors at once and the
  // whole system browns out. maybe it's also a good idea to implement some kind of connectivity check with the controller?
  // the inputs shouldn't update (PS4::poll() == false) if the controller isn't connected. then stop motors or smth idk

  drive_interface::initMotors();

  if (!PS4::poll())
  {
    Serial.println("Waiting for controller...");
    // wait for first input
    while (!PS4::poll())
    {
      delay(200);
    }
  }
  Serial.println("Controller Connected!");
}

void loop()
{
  PS4::poll();
  if (PS4::Square())
    drive_interface::forward(255);
}